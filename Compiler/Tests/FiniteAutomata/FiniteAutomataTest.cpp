//
// Created by Emanuel on 11.12.2022.
//

#include "FiniteAutomataTest.h"
#include "../../FiniteAutomata/FiniteAutomata.h"

#include <iostream>

void FiniteAutomataTest::printMenu() {
    std::cout << "0. Exit\n";
    std::cout << "1. Display the set of states\n";
    std::cout << "2. Display the alphabet\n";
    std::cout << "3. Display all the transitions\n";
    std::cout << "4. Display the initial state\n";
    std::cout << "5. Display the set of final states\n";
    std::cout << "6. For a DFA, check that a sequence is accepted by the FA\n";
}

void FiniteAutomataTest::test() {
    FiniteAutomata finiteAutomata;
    finiteAutomata.parse("../Files/FiniteAutomata/FA.in");

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                std::cout << "States:\n";
                for (const auto& element: finiteAutomata.getStates()) {
                    std::cout << element << '\n';
                }
                std::cout << '\n';
                break;
            case 2:
                std::cout << "Alphabet:\n";
                for (const auto& element: finiteAutomata.getAlphabet()) {
                    std::cout << element << '\n';
                }
                std::cout << '\n';
                break;
            case 3:
                std::cout << "Transitions:\n";
                for (const auto& element: finiteAutomata.getTransitions()) {
                    std::cout << element.toString() << '\n';
                }
                std::cout << '\n';
                break;
            case 4:
                std::cout << "Initial State:\n";
                std::cout << finiteAutomata.getInitialState() << '\n';
                break;
            case 5:
                std::cout << "Final States: \n";
                for (const auto& element: finiteAutomata.getFinalStates()) {
                    std::cout << element << '\n';
                }
                std::cout << '\n';
                break;
            case 6: {
                std::string sequence;

                std::cout << "Sequence: ";
                std::cin >> sequence;

                std::cout << (finiteAutomata.check(sequence) ? "accepted" : "not accepted") << '\n';
                break;
            }
            default:
                std::cout << "Incorrect command!\n";
        }
    }
}
