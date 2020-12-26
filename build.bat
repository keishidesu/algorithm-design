@echo off

set buildconf=%1
set buildall=0
set debug=

:: Make build file if not exists
if not exist build\NUL (
  echo Creating build directory...
  mkdir build
) else (
  echo Build directory exists!
)

if "%2" == "debug" (
  echo This is a debug build!
  set debug=-DBUILD_DEBUG
)
if "%buildconf%" == "generator" goto buildGenerator
if "%buildconf%" == "hashTable" goto buildHashTable
if "%buildconf%" == "binaryTree" goto buildBinaryTree
if "%buildconf%" == "priorityQueue" goto buildPriorityQueue
goto buildAll

:: Generator
:buildGenerator
echo Building Generator executable...
g++ src/*.cpp -o build/generator.exe -DBUILD_GENERATOR %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue0
goto buildExit

:: Hash Table
:buildHashTable
echo Building Hash Table executable...
g++ src/*.cpp -o build/hashTable.exe -DBUILD_HASHTABLE %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue1
goto buildExit

:: Binary Tree
:buildBinaryTree
echo Building Binary Tree executable...
g++ src/*.cpp -o build/binaryTree.exe -DBUILD_BINARYTREE %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue2
goto buildExit

:: Priority Queue
:buildPriorityQueue
echo Building Priority Queue executable...
g++ src/*.cpp -o build/priorityQueue.exe -DBUILD_PRIORITYQUEUE %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue3
goto buildExit

:: Build Everything
:buildAll
set buildall=1
if "%buildconf%" == "debug" (
  echo This is a debug build for all!
  set debug=-DBUILD_DEBUG
)
echo Building all artifacts...
goto buildGenerator
:buildAllContinue0
goto buildHashTable
:buildAllContinue1
goto buildBinaryTree
:buildAllContinue2
goto buildPriorityQueue
:buildAllContinue3
goto buildExit

:buildExit
if errorlevel 1 (
  echo Build Failure!
) else (
  echo Build Complete!
)
