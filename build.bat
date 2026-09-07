@echo off
setlocal

cl /LD /O2 "%~dp0src\main.c" /link /OUT:"%~dp0EOSSDK-Win64-Shipping.dll" User32.lib

if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

echo Build successful.
exit /b 0
