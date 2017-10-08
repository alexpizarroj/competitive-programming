@echo off
setlocal

call "%~dp0config.bat"

call "%project_folder%ensure-task-exists.bat"

echo Started: Compiling

if exist "%task_exe_file%" (
    del "%task_exe_file%" /F /Q
)

g++ -Wfatal-errors -Wall -O2 -std=c++14 -g -o "%task_exe_file%" "%task_cpp_file%"
if %ERRORLEVEL% NEQ 0 exit /b 1

echo Finished: Compiling
echo.

exit /b 0