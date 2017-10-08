@echo off
setlocal

call "%~dp0config.bat"

set restore_folder_name=%~1
if "%restore_folder_name%"=="" (
    echo Usage: restore-from folder
    exit /b 1
)

set restore_folder=%project_folder%%restore_folder_name%\
if not exist "%restore_folder_name%" (
    echo Error: No such folder named '%restore_folder_name%'.
    exit /b 1
)

call %project_folder%backup-to.bat task-last-backup -y
xcopy /S /Q /Y "%restore_folder%*" "%task_folder%" 1>nul

exit /b 0