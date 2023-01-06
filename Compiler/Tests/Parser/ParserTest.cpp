//
// Created by Dragos on 12/19/2022.
//

#include "ParserTest.h"
#include "../../Parser/RecursiveParser.h"
#include "../../Scanner/Scanner.h"

#include <iostream>
#include <sstream>
#include <fstream>

std::pair<std::string, int> splitPifLine(const std::string &line) {
    std::stringstream lineSs(line);

    std::string current;
    std::vector<std::string> parts;

    while (std::getline(lineSs, current, ' ')) {
        if (current == "->") {
            continue;
        }
        parts.push_back(current);
    }

    return std::make_pair(parts[0], std::stoi(parts[1]));
}

void ParserTest::printMenu() {
    std::cout << "0. Exit\n";
    std::cout << "1. Check input sequence\n";
}

void ParserTest::test() {
    RecursiveParser parser("../Files/Grammar/g2.txt");
    Scanner scanner("../Files/Programs/p1.txt", "../Files/LanguageSpecification/tokens.in");
    scanner.scan();
    std::ifstream file;

    std::vector<std::string> inputSequence;
    bool res;
    std::string line;

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                inputSequence.clear();

                file.open("../Files/Output/PIF.out");

                while (std::getline(file, line)) {
                    if (line.empty()) {
                        continue;
                    }

                    auto linePair = splitPifLine(line);

                    inputSequence.push_back(linePair.first);
                }

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
