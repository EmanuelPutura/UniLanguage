cmake_minimum_required(VERSION 3.16)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compiler main.cpp SymbolTable/RedBlackTree/RedBlackTree.cpp SymbolTable/RedBlackTree/RedBlackTree.h SymbolTable/RedBlackTree/Node.h
        SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h SymbolTable/Tests/SymbolTableTest.cpp SymbolTable/Tests/SymbolTableTest.h)