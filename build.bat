@echo off
if not exist build mkdir build
pushd build 
cl /W3 /we4013 /LD /O2 /EHsc ../src/main.c ../src/eac.c ../src/logger.c /link /DLL /OUT:EOSSDK-Win64-Shipping.dll User32.lib
popd
