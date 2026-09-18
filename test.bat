@echo off
REM usage:
REM   test.bat program.exe                test with NO input (immediate EOF)
REM   test.bat program.exe input.txt       feed input.txt's content into the program
if "%~2"=="" (
    echo.| ".\%~1"
) else (
    type "%~2" | ".\%~1"
)
echo.
echo [exit code: %ERRORLEVEL%]
