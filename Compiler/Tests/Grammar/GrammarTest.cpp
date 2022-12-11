//
// Created by Emanuel on 11.12.2022.
//

#include "GrammarTest.h"
#include "../../Grammar/Grammar.h"

#include <iostream>

void GrammarTest::printMenu() {
    std::cout << "0. Exit\n";
    std::cout << "1. Display the set of non-terminals\n";
    std::cout << "2. Display the set of terminals\n";
    std::cout << "3. Display the set of productions\n";
    std::cout << "4. Display the starting symbol\n";
    std::cout << "5. Check if the grammar is a CFG\n";
}

void GrammarTest::test() {
    Grammar grammar;
    grammar.parse("../Files/Grammar/g2.txt");

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                std::cout << "Non-terminals:\n";
                for (const auto& element: grammar.getNonterminals()) {
                    std::cout << element << '\n';
                }
                std::cout << '\n';
                break;
            case 2:
                std::cout << "Terminals:\n";
                for (const auto& element: grammar.getTerminals()) {
                    std::cout << element << '\n';
                }
                std::cout << '\n';
                break;
            case 3:
                std::cout << "Productions:\n";
                for (const auto& element: grammar.getProductions()) {
                    std::cout << element.getString() << '\n';
                }
                std::cout << '\n';
                break;
            case 4:
                std::cout << "Starting symbol:\n";
                std::cout << grammar.getStartingSymbol() << "\n\n";
                break;
            case 5:
                std::cout << "Check CFG: " << std::boolalpha << grammar.checkCFG() << "\n\n";
            default:
                std::cout << "Incorrect command!\n";
        }
    }
}
