@echo off
setlocal

call "%~dp0config.bat"

mkdir "%task_folder%" 2>nul

if not exist "%task_cpp_file%" (
    copy "%model_task_cpp_file%" "%task_cpp_file%" 1>nul
)

if not exist "%task_input_file%" (
    copy "%model_task_input_file%" "%task_input_file%" 1>nul
)

exit /b 0