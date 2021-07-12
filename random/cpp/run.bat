@echo off
:A
::comment
cls
set /p s=c for cpp/p for python: 
IF %s% ==c  IF %s% ==p ELSE Goto A
IF %s% ==c (Goto valid)  ELSE (IF %s% ==p (Goto valid ) ELSE (Goto invalid))


:valid
set /p n=file: 
IF %s%==c g++ %n%.cpp && a
IF %s%==p python %n%.py
Pause
Goto A

:invalid
echo invalid input
Pause
Goto A
::end