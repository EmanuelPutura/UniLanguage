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

void ParserTest::testFileContextFreeGrammar() {
    RecursiveParser parser("../Files/Grammar/g1.txt");

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;
        std::cin.get();

        switch (command) {
            case 0:
                return;
            case 1: {
                std::vector<std::string> sequence;
                int sequenceLength;

                std::cout << "number of symbols >> ";
                std::cin >> sequenceLength;

                if (sequenceLength < 0) {
                    std::cout << "Incorrect sequence length!\n";
                    continue;
                }

                while (sequenceLength) {
                    std::string current;
                    std::cout << "current symbol >> ";
                    std::cin >> current;
                    sequence.push_back(current);

                    sequenceLength--;
                }

                auto parsingOutput = parser.parse(sequence);

                if (!parsingOutput.getIsValidInput()) {
                    std::cout << "The sequence was not validated by the parser!\n";
                } else {
                    std::cout << "Sequence accepted! The parsing table is: \n\n";
                    std::cout << parsingOutput;

                    std::ofstream fout("../Files/Parser/parsing_table.txt");
                    fout << parsingOutput;

                    fout.close();
                }

                break;
            }
            default:
                std::cout << "Incorrect command!\n";
        }
    }
}

void ParserTest::testLanguageGrammar() {
    RecursiveParser parser("../Files/Grammar/g2.txt");
    Scanner scanner("../Files/Programs/p1.txt", "../Files/LanguageSpecification/tokens.in");
    scanner.scan();
    std::ifstream file;

    std::vector<std::string> inputSequence;
    std::string line;

    while (true) {
        printMenu();
        int command;

        std::cout << ">> ";
        std::cin >> command;

        switch (command) {
            case 0:
                return;
            case 1: {
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

                auto parsingOutput = parser.parse(inputSequence);

                if (!parsingOutput.getIsValidInput()) {
                    std::cout << "The sequence was not validated by the parser!\n";
                } else {
                    std::cout << "Sequence accepted! The parsing table is: \n\n";
                    std::cout << parsingOutput;
                }

                file.close();

                break;
            }
            default:
                std::cout << "Incorrect command!\n";
        }
    }
}
