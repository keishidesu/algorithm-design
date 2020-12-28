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
if "%buildconf%" == "hashtablechain" goto buildHashTableChain
if "%buildconf%" == "hashtablelinear" goto buildHashTableLinear
if "%buildconf%" == "binarytree" goto buildBinaryTree
if "%buildconf%" == "priorityheap" goto buildPriorityHeap
goto buildAll

:: Generator
:buildGenerator
echo Building Generator executable...
g++ src/*.cpp -o build/generator.exe -DBUILD_GENERATOR %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue0
goto buildExit

:: Hash Table Chain
:buildHashTableChain
echo Building Hash Table Chain executable...
g++ src/*.cpp -o build/hashTableChain.exe -DBUILD_HASHTABLECHAIN %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue1
goto buildExit

:buildHashTableLinear
echo Building Hash Table Linear executable...
g++ src/*.cpp -o build/hashTableLinear.exe -DBUILD_HASHTABLELINEAR %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue2
goto buildExit

:: Binary Tree
:buildBinaryTree
echo Building Binary Tree executable...
g++ src/*.cpp -o build/binaryTree.exe -DBUILD_BINARYTREE %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue3
goto buildExit

:: Priority Heap
:buildPriorityHeap
echo Building Priority Heap executable...
g++ src/*.cpp -o build/priorityHeap.exe -DBUILD_PRIORITYHEAP %debug%
if errorlevel 1 goto buildExit
if %buildall% == 1 goto buildAllContinue4
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
goto buildHashTableChain
:buildAllContinue1
goto buildHashTableLinear
:buildAllContinue2
goto buildBinaryTree
:buildAllContinue3
goto buildPriorityHeap
:buildAllContinue4
goto buildExit

:buildExit
if errorlevel 1 (
  echo Build Failure!
) else (
  echo Build Complete!
)
