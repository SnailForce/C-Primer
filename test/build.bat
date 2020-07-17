@echo off

call "C:\\Program Files (x86)\\Microsoft Visual Studio\2019\\Community\\VC\\Auxiliary\\Build\\vcvarsall.bat" x86

set compilerflags=/Od /Zi /EHsc

set linkerflags=/OUT:helloworld.exe

cl.exe %compilerflags% helloworld.cpp /link %linkerflags%