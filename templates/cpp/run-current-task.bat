@echo off
setlocal

call "%~dp0config.bat"

call %project_folder%build-current-task.bat 1>&2
if %ERRORLEVEL% NEQ 0 goto :eof

"%task_exe_file%" < "%task_input_file%"