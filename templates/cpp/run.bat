@echo off
setlocal

call %~dp0preinit_env.bat

call %project_folder%build.bat 1>&2
if ERRORLEVEL 1 goto :eof

"%task_exe_file%" < "%task_input_file%"