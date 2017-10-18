@echo off
setlocal

call "%~dp0_config.bat"
call "%~dp0_task-name-arg.bat" %1
if %ERRORLEVEL% NEQ 0 exit /b 1

set compiler_args=-Wfatal-errors -Wall -std=c++14 -g
if /I "%~2"=="-debug" (
    set compiler_args=%compiler_args% -DVS_CODE_DEBUG
) else (
    set compiler_args=%compiler_args% -DMEASURE_RUNTIME -O2
)

echo Started: Compiling

if exist "%output_exe_file%" del "%output_exe_file%" /F /Q

mkdir "%bin_folder%" 2>nul

g++ %compiler_args% -o "%output_exe_file%" "%task_cpp_file%"
if %ERRORLEVEL% NEQ 0 exit /b 1

echo Finished: Compiling

exit /b 0