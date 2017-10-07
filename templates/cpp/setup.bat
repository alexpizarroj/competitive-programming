@echo off
setlocal

call %~dp0preinit_env.bat

echo Started: Setting up task

mkdir "%task_folder%" 2> nul

if not exist "%task_cpp_file%" (
    copy "%model_task_cpp_file%" "%task_cpp_file%"
)

if not exist "%task_input_file%" (
    copy "%model_task_input_file%" "%task_input_file%"
)

echo Finished: Setting up task