@echo off
cl /LD /O2 /EHsc src/main.c /link /DLL /OUT:EOSSDK-Win64-Shipping.dll User32.lib
