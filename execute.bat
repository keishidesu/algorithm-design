@echo off

set execonf=%1
set exeall=0

:: if build file not exist
if not exist build\NUL (
  echo Please Compile the files first with 'build' command or batch file
  goto exeExit
)
:: Make output folder if not exists
if not exist output\NUL (
  echo Creating output directory...
  mkdir output
)

if "%execonf%" == "generator" goto exeGenerator
if "%execonf%" == "hashtablechain" goto exeHashTableChain
if "%execonf%" == "hashtablelinear" goto exeHashTableLinear
if "%execonf%" == "binarytree" goto exeBinaryTree
if "%execonf%" == "priorityQueue" goto exePriorityQueue
goto exeall

:: Generator
:exeGenerator
echo Executing generator...
"build/generator"
echo.
if errorlevel 1 goto exeExit
if %exeall% == 1 goto exeAllContinue0
if %exeall% == 0 goto exeExit

:: HashTableLinear
:exeHashTableLinear
echo Executing Hash Table with Linear Probing...
"build/hashtablelinear"
echo.
if errorlevel 1 goto exeExit
if %exeall% == 1 goto exeAllContinue2
if %exeall% == 0 goto exeExit

:: HashTableChaining
:exeHashTableChain
echo Executing Hash Table with Chaining...
"build/hashtablechain"
echo.
if errorlevel 1 goto exeExit
if %exeall% == 1 goto exeAllContinue1
if %exeall% == 0 goto exeExit

:: AVL
:exeBinaryTree
echo Executing AVL Binary Search Tree...
"build/binarytree"
echo.
if errorlevel 1 goto exeExit
if %exeall% == 1 goto exeAllContinue3
if %exeall% == 0 goto exeExit

:: PriorityQueue
:exePriorityQueue
echo Executing Priority Queue with Heap
"build/Priorityqueue"
echo.
if errorlevel 1 goto exeExit
if %exeall% == 1 goto exeAllContinue4
if %exeall% == 0 goto exeExit

:: Build Everything
:exeall
set exeall=1
echo Executing all artifacts...
goto exeGenerator
:exeAllContinue0
goto exeHashTableChain
:exeAllContinue1
goto exeHashTableLinear
:exeAllContinue2
goto exeBinaryTree
:exeAllContinue3
goto exePriorityQueue
:exeAllContinue4
goto exeExit

:exeExit
if errorlevel 1 (
  echo Execution Failure!
) else (
  echo Execution Complete!
)