@echo off

if "%1"=="" goto :compilerDef
set _compiler=%1
echo Compiler: %1
goto :compilerEnd
:compilerDef
set _compiler="clang++"
echo Compiler: clang++
:compilerEnd

if "%2"=="gcc" goto :flagsGCC
if "%2"=="g++" goto :flagsGCC
if not "%2"=="" goto :flagsClang
if "%_compiler%"=="g++" goto :flagsGCC
if "%_compiler%"=="gcc" goto :flagsGCC
:flagsClang
echo Flags: Clang
set _flags=-std=c++20
goto :flagsEnd
:flagsGCC
echo Flags: GCC
set _flags=-std=c++2a -mwindows -municode
:flagsEnd

vmake %_compiler% %_flags% -o chatt.exe -D_CRT_SECURE_NO_WARNINGS NAMN -lws2_32 -lntdll -luser32