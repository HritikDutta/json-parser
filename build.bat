@echo off

set includes= /I .

set compile_flags= /Zi /EHsc /std:c++17 /DDEBUG

cl %compile_flags% /c misc/*.cpp  %includes%
cl %compile_flags% /c platform/*.cpp %includes%
cl %compile_flags% /c parser/*.cpp %includes%
cl %compile_flags% /c example.cpp %includes%

link *.obj /DEBUG /OUT:jp.exe

del *.obj