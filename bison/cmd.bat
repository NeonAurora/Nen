@echo off
:: Set directories
set ENGINE_DIR=Engine
set IO_DIR=IO

:: Create directories if they don't exist
if not exist "%ENGINE_DIR%" mkdir "%ENGINE_DIR%"
if not exist "%IO_DIR%" mkdir "%IO_DIR%"

:: Remove old files
del "%ENGINE_DIR%\parser.exe"
del "%ENGINE_DIR%\lex.yy.c"
del "%ENGINE_DIR%\echo.tab.c"
del "%ENGINE_DIR%\echo.tab.h"
del "%IO_DIR%\output.txt"
del echo.output

:: Run Bison and Flex
bison -d -v echo.y
flex echo.l

:: Move generated files to Engine directory
move lex.yy.c "%ENGINE_DIR%"
move echo.tab.c "%ENGINE_DIR%"
move echo.tab.h "%ENGINE_DIR%"

:: Compile the generated C files from the Engine directory
g++ -Wall -o "%ENGINE_DIR%\parser.exe" "%ENGINE_DIR%\echo.tab.c" "%ENGINE_DIR%\lex.yy.c"

:: Run the parser with input from b.n in the I/O directory and output to output.txt in the same directory
type "%IO_DIR%\b.n" | "%ENGINE_DIR%\parser.exe" > "%IO_DIR%\output.txt"
