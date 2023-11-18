del a.exe
del lex.yy.c
flex echo.l
g++ lex.yy.c -o a.exe
type b.n | a.exe
type b.n | a.exe > output.txt