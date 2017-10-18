@echo off
setlocal

call "%~dp0_config.bat"
call "%~dp0_task-name-arg.bat" %1
if %ERRORLEVEL% NEQ 0 exit /b 1

call "%~dp0compile.bat" %1 %2
if %ERRORLEVEL% NEQ 0 exit /b 1

echo.
"%output_exe_file%"

exit /b 0