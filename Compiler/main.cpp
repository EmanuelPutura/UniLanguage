#include "SymbolTable/Tests/SymbolTableTest.h"
#include "Scanner/Scanner.h"
#include "FiniteAutomata/FiniteAutomata.h"
#include "Grammar/Grammar.h"

void scanner() {
    SymbolTableTest::symbolTableTest();

    Scanner scanner("../Files/Programs/p3.txt", "../Files/LanguageSpecification/tokens.in");
    scanner.scan();

    std::cout << '\n';
}

void printMenuFiniteAutomata() {
    std::cout << "0. Exit\n";
    std::cout << "1. Display the set of states\n";
    std::cout << "2. Display the alphabet\n";
    std::cout << "3. Display all the transitions\n";
    std::cout << "4. Display the initial state\n";
    std::cout << "5. Display the set of final states\n";
    std::cout << "6. For a DFA, check that a sequence is accepted by the FA\n";
}

void printMenuGrammar() {
    std::cout << "0. Exit\n";
    std::cout << "1. Display the set of nonterminals\n";
    std::cout << "2. Display the set of terminals\n";
    std::cout << "3. Display the set of productions\n";
    std::cout << "4. Display the starting symbol\n";
    std::cout << "5. Check if the grammar is a CFG\n";
}

void finiteAutomata() {
    FiniteAutomata finiteAutomata;
    finiteAutomata.parse("../Files/FiniteAutomata/FA.in");

    while (true) {
        printMenuFiniteAutomata();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                std::cout << "States:\n";
                for (auto el: finiteAutomata.getStates()) {
                    std::cout << el << '\n';
                }
                std::cout << '\n';
                break;
            case 2:
                std::cout << "Alphabet:\n";
                for (auto el: finiteAutomata.getAlphabet()) {
                    std::cout << el << '\n';
                }
                std::cout << '\n';
                break;
            case 3:
                std::cout << "Transitions:\n";
                for (auto el: finiteAutomata.getTransitions()) {
                    std::cout << el.toString() << '\n';
                }
                std::cout << '\n';
                break;
            case 4:
                std::cout << "Initial State:\n";
                std::cout << finiteAutomata.getInitialState() << '\n';
                break;
            case 5:
                std::cout << "Final States: \n";
                for (auto el: finiteAutomata.getFinalStates()) {
                    std::cout << el << '\n';
                }
                std::cout << '\n';
            case 6:
                std::string sequence;

                std::cout << "Sequence: ";
                std::cin >> sequence;

                std::cout << (finiteAutomata.check(sequence) ? "accepted" : "not accepted") << '\n';
        }
    }
}

void grammar() {
    Grammar grammar;
    grammar.parse("../Files/Grammar/g2.txt");

    while (true) {
        printMenuGrammar();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                std::cout << "Nonterminals:\n";
                for (auto el: grammar.getNonterminals()) {
                    std::cout << el << '\n';
                }
                std::cout << '\n';
                break;
            case 2:
                std::cout << "Terminals:\n";
                for (auto el: grammar.getTerminals()) {
                    std::cout << el << '\n';
                }
                std::cout << '\n';
                break;
            case 3:
                std::cout << "Productions:\n";
                for (auto el: grammar.getProductions()) {
                    std::cout << el.getString() << '\n';
                }
                std::cout << '\n';
                break;
            case 4:
                std::cout << "Starting symbol:\n";
                std::cout << grammar.getStartingSymbol() << "\n\n";
                break;
            case 5:
                std::cout << "Check CFG: " << std::boolalpha << grammar.checkCFG() << "\n\n";
        }
    }
}

int main() {
    scanner();
    //finiteAutomata();
    grammar();

    return 0;
}
