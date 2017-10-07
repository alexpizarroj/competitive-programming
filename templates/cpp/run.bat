@echo off
setlocal

if "%~1"=="" (
  echo Usage: run ^<problem-letter^>
  goto return
)

set problem_letter=%~dp0%1
rem echo %problem_letter%

set main_file=%problem_letter%.cpp
rem echo %main_file%

set input_file=%problem_letter%.in
rem echo %input_file%

echo Compiling...
g++ -Wall -O2 -std=c++14 -o p.exe "%main_file%"
if ERRORLEVEL 1 goto return

echo Running...
p.exe < "%input_file%"

:return
