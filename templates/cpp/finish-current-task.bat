@echo off
setlocal

call "%~dp0config.bat"

call "%project_folder%backup-to.bat" %1
if %ERRORLEVEL% NEQ 0 goto :eof

call "%project_folder%start-new-task.bat"
