@echo off
setlocal

call %~dp0preinit_env.bat

call %project_folder%setup.bat

echo Started: Compiling

if exist "%task_exe_file%" (
    del "%task_exe_file%" /F /Q
)

g++ -Wfatal-errors -Wall -O2 -std=c++14 -g -o "%task_exe_file%" "%task_cpp_file%"

if ERRORLEVEL 1 goto :eof

echo Finished: Compiling
echo.