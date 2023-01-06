//
// Created by Dragos on 12/19/2022.
//

#include "ParserTest.h"
#include "../../Parser/RecursiveParser.h"

#include <iostream>
#include <sstream>
#include <fstream>

std::vector<std::string> getInputSequenceFromString(const std::string &inputString) {
    std::istringstream ss(inputString);

    std::string symbol;
    std::vector<std::string> inputSequence;

    while (std::getline(ss, symbol, ' ')) {
        inputSequence.push_back(symbol);
    }

    return inputSequence;
}

void ParserTest::printMenu() {
    std::cout << "0. Exit\n";
    std::cout << "1. Check input sequence\n";
}

void ParserTest::test() {
    RecursiveParser parser("../Files/Grammar/g2.txt");
    std::ifstream file;

    std::string inputString;
    std::vector<std::string> inputSequence;
    bool res;
    std::string line;

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        //std::cin.get();

        switch (command) {
            case 0:
                return;
            case 1:
                inputSequence.clear();
                inputString = "";
                file.open("../Files/Programs/p2.txt");

                //std::getline(std::cin, inputString);

                while (std::getline(file, line)) {
                    if (line.empty()) {
                        continue;
                    }
                    inputString += line + " ";
                }

                inputSequence = getInputSequenceFromString(inputString);

                for (size_t i = 0; i < inputSequence.size(); ++i) {
                    if (inputSequence[i].empty()) {
                        inputSequence.erase(inputSequence.begin() + i);
                        --i;
                    }
                }

                res = parser.parse(inputSequence);

                if (!res) {
                    std::cout << "Error\n";
                } else {
                    std::cout << "Sequence accepted\n";
                }

                file.close();

                break;
            default:
                std::cout << "Incorrect command!\n";
        }
    }
}
