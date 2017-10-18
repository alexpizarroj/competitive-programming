set task_name=%~1
if "%task_name%"=="" (
    echo Error: Missing task name argument
    exit /b 1
)

set task_cpp_file=%src_folder%%task_name%.cpp
if not exist "%task_cpp_file%" (
    echo Error: Missing task file "%task_name%.cpp"
    exit /b 1
)

exit /b 0