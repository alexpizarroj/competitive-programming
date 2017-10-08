@echo off
setlocal

call "%~dp0config.bat"

call "%project_folder%ensure-task-exists.bat"

set backup_folder_name=%~1
if "%backup_folder_name%"=="" (
    echo Error: Missing target folder.
    exit /b 1
)

if not exist "%task_folder%" (
    echo Error: Task folder doesn't exist.
    exit /b 1
)

set backup_folder=%project_folder%%backup_folder_name%\
if exist "%backup_folder%" (
    if /I "%~2"=="-y" (
        rmdir /S /Q "%backup_folder%"
    ) else (
        echo Error: A folder named '%backup_folder_name%' already exists.
        exit /b 1
    )
)

xcopy /S /Q /Y "%task_folder%*" "%backup_folder%" 1>nul

exit /b 0