@echo off
 setlocal EnableDelayedExpansion
 set PATH=%PATH%;C:\Program Files\CodeBlocks\MinGW\bin
 doskey make=mingw32-make.exe $*
 cmd.exe /k