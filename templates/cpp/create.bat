@echo off
setlocal

call "%~dp0_config.bat"

set task_name=%~1
if "%task_name%"=="" (
    echo Error: Missing task name argument
    exit /b 1
)

set new_src_file=%src_folder%%task_name%.cpp
if exist "%new_src_file%" (
    echo Error: Task "%task_name%.cpp" already exists.
    exit /b 1
)

mkdir "%src_folder%" 2>nul
copy /Y "%task_template_cpp_file%" "%new_src_file%" 1>nul

mkdir "%input_folder%" 2>nul
set new_input_file=%input_folder%%task_name%.in
if not exist "%new_input_file%" echo. > "%new_input_file%"

exit /b 0