cmake_minimum_required(VERSION 3.16)
project(Compiler)

set(CMAKE_CXX_STANDARD 14)

add_executable(Compiler main.cpp SymbolTable/RedBlackTree/RedBlackTree.cpp SymbolTable/RedBlackTree/RedBlackTree.h SymbolTable/RedBlackTree/Node.h
        SymbolTable/RedBlackTree/rbt_testing.h SymbolTable/RedBlackTree/rbt_testing.cpp SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h)