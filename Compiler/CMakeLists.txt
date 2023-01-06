cmake_minimum_required(VERSION 3.16)
project(Compiler)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler main.cpp SymbolTable/RedBlackTree/RedBlackTree.cpp SymbolTable/RedBlackTree/RedBlackTree.h SymbolTable/RedBlackTree/Node.h
        SymbolTable/SymbolTable.cpp SymbolTable/SymbolTable.h SymbolTable/Tests/SymbolTableTest.cpp SymbolTable/Tests/SymbolTableTest.h Scanner/Scanner.cpp
        Scanner/Scanner.h ProgramInternalForm/ProgramInternalForm.cpp ProgramInternalForm/ProgramInternalForm.h FiniteAutomata/Transition/Transition.cpp
        FiniteAutomata/Transition/Transition.h FiniteAutomata/FiniteAutomata.cpp FiniteAutomata/FiniteAutomata.h Utils/UtilFunctions.cpp
        Utils/UtilFunctions.h Grammar/Grammar.h Grammar/Production/Production.h Grammar/Production/Production.cpp Grammar/Grammar.cpp 
        Tests/FiniteAutomata/FiniteAutomataTest.cpp Tests/FiniteAutomata/FiniteAutomataTest.h Tests/Grammar/GrammarTest.cpp Tests/Grammar/GrammarTest.h 
        Tests/Scanner/ScannerTest.cpp Tests/Scanner/ScannerTest.h Parser/RecursiveParser.cpp Parser/RecursiveParser.h Parser/LanguageSymbol/ParserLanguageSymbol.cpp
        Parser/LanguageSymbol/ParserLanguageSymbol.h Parser/LanguageSymbol/TerminalSymbol/TerminalSymbol.cpp Parser/LanguageSymbol/TerminalSymbol/TerminalSymbol.h
        Parser/LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.cpp Parser/LanguageSymbol/NonTerminalSymbol/NonTerminalSymbol.h Tests/Parser/ParserTest.cpp Tests/Parser/ParserTest.h)
