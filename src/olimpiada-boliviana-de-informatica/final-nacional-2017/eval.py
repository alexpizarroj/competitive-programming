#!/usr/bin/env python3
import os
import sys
import subprocess


def panic(msg):
    print("eval.py: " + msg, file=sys.stderr)
    print("PROGRAMA ABORTADO", file=sys.stderr)
    sys.exit(1)


def get_working_folder():
    return os.path.realpath(os.getcwd())


def get_problem_folder():
    if len(sys.argv) == 2:
        folder = os.path.realpath(sys.argv[1])
    else:
        folder = get_working_folder()
    folder = (folder if os.path.isdir(folder) else None)
    return folder


def get_relative_path(path, basepath):
    if not path.startswith(basepath):
        panic("ERROR: Esto no debería ocurrir.")
    return path[len(basepath):]


def print_result(detail, result, msg_if_false):
    result_str = "OK" if result else msg_if_false
    print("{:60s}{:s}".format(detail, result_str))


def print_result_of_filepath_check(filepath, basepath):
    relpath = get_relative_path(filepath, basepath)
    res = os.path.isfile(filepath)
    print_result("El archivo '%s' existe" % (relpath), res,
                 "No, el archivo no existe")


def try_compile_solution(solution_filepath, errlog_filepath):
    if solution_filepath == None:
        return (None, None, False, "No existe solución modelo")

    (_, src_kind) = os.path.splitext(solution_filepath)
    solution_filepath_noext = solution_filepath[:-len(src_kind)]

    # Which language is the model solution using?
    if src_kind == ".cpp":
        model_filepath = solution_filepath_noext + ".exe"
        model_runcmd = [model_filepath]
        compilation_cmd = ["g++", "-Wall", "-O2", "-std=c++11", "-o",
                           model_filepath, solution_filepath]
    elif src_kind == ".java":
        model_filepath = solution_filepath_noext + ".class"
        model_runcmd = ["java", "-cp", os.path.dirname(solution_filepath),
                        os.path.basename(solution_filepath_noext)]
        compilation_cmd = ["javac", solution_filepath]
    elif src_kind == ".py":
        model_filepath = ""
        model_runcmd = ["python", solution_path]
        compilation_cmd = [""]
    else:
        return (None, None, False, "Extensión '%s' inválida" % (src_kind))

    if compilation_cmd[0] != "":
        # Compile the solution
        with open(errlog_filepath, "wb") as log:
            try:
                p = subprocess.Popen(compilation_cmd, stdout=None, stderr=log)
                p.communicate()
            except OSError:
                # If we run into an issue, return
                fail_msg = "Error al buscar/ejecutar '%s'" % (
                    compilation_cmd[0])
                return (None, None, False, fail_msg)

            errorlevel = p.returncode

        # If we get compilation error(s), return
        if errorlevel != 0:
            return (None, None, False,
                    "Error de compilación. Log de errores:\n  " + errlog_filepath)
        else:
            # If compilation went OK, remove the compilation log
            os.remove(errlog_filepath)

    # Up to this point, all went well
    return (model_filepath, model_runcmd, True, "")


def get_first_linediff(filepath1, filepath2):
    current_line = 1

    with open(filepath1) as f1, open(filepath2) as f2:
        line1, line2 = f1.readline(), f2.readline()

        while line1 != "" and line2 != "":
            if line1 != line2:
                return current_line
            current_line += 1

            line1, line2 = f1.readline(), f2.readline()

    return (None if line1 == line2 else current_line)


if __name__ == "__main__":
    # Path of the directory to evaluate
    problem_folder = get_problem_folder()
    if problem_folder is None:
        panic("La ruta dada no es la de una carpeta.")

    # Paths to important subfolders
    problem_folder_name = os.path.basename(problem_folder)
    base_data_folder = problem_folder  # os.path.join(problem_folder, "data")
    # sample_folder = os.path.join(base_data_folder, "test-data")
    secret_folder = os.path.join(base_data_folder, "test-data")
    solution_files = [os.path.join(problem_folder, "main.cpp"),
                      os.path.join(problem_folder, "main.java"),
                      os.path.join(problem_folder, "main.py")]

    print("Datos básicos del problema")
    print("  Dirección:\t" + problem_folder)
    print("  Carpeta:\t" + problem_folder_name + "\n")

    # GENERAL TESTING

    print("** EVALUACION GENERAL **")
    print_result("DETALLE", False, "RESULTADO")

    # Search for model solution(s) existance. While at it, pick one
    solution_path = None
    for solution in solution_files:
        print_result_of_filepath_check(solution, problem_folder)
        if solution_path == None and os.path.isfile(solution):
            solution_path = solution

    # See if the model solution compiles
    if solution_path != None:
        solution_relpath = get_relative_path(solution_path, problem_folder)
        logfile_path = os.path.join(os.path.dirname(solution_path),
                                    "log-de-compilacion.txt")

        model_filepath, model_runcmd, solution_compiles, fail_msg = \
            try_compile_solution(solution_path, logfile_path)

        current_issue = "La solución '%s' compila" % (solution_relpath)
        print_result(current_issue, solution_compiles, fail_msg)

    # OUTPUT GENERATION AND TESTING

    def do_output_matching_tests(data_folder):
        print("\n** %s **" % (data_folder))
        print_result("DETALLE", False, "RESULTADO")

        # .out files generation for every .in file
        for fn in os.listdir(data_folder):
            if not fn.endswith(".in"):
                continue

            input_fp = os.path.join(data_folder, fn)
            output_fp = input_fp[:-3] + ".out"
            modelout_fp = input_fp[:-3] + ".model.out"
            modelerr_fp = input_fp[:-3] + ".model.err"
            fn_out = os.path.basename(output_fp)

            # Run the model solution using the test data as input
            with open(input_fp, "rb") as modelin, \
                    open(modelout_fp, "wb") as modelout, \
                    open(modelerr_fp, "wb") as modelerr:
                p = subprocess.Popen(model_runcmd, stdin=modelin,
                                     stdout=modelout, stderr=modelerr)
                p.communicate()
                errorlevel = p.returncode

            current_issue = fn

            # If the model solution ran successfully, remove the error file
            if errorlevel == 0:
                os.remove(modelerr_fp)
            else:
                print_result(current_issue, False, "No, RTE para esta entrada")
                continue

            # If the expected output matches the model output,
            #   remove the model output and leave the original file untouched
            # If they don't match, report the first line of the mismatch and
            #   show the issue to the user
            linediff = get_first_linediff(output_fp, modelout_fp)
            if linediff == None:
                print_result(current_issue, True, "")
            else:
                print_result(current_issue, False,
                             "No, la línea %d no concuerda" % (linediff))
            # If there was no mismatch, delete the model output
            if linediff == None:
                os.remove(modelout_fp)

    if solution_path == None or solution_compiles == False:
        print("Omitidas -- No se dispone de una solución modelo.")
    else:
        try:
            # do_output_matching_tests(sample_folder)
            do_output_matching_tests(secret_folder)
        finally:
            if os.path.isfile(model_filepath):
                os.remove(model_filepath)

    print("\n** FIN DE LAS PRUEBAS **\nPresione [ENTER] para salir...")
    input()
