@echo off
setlocal

call "%~dp0config.bat"

if exist "%task_folder%" (
    call "%project_folder%restore-from.bat" model
) else (
    call "%project_folder%ensure-task-exists.bat"
)