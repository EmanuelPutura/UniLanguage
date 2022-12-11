#include "Grammar.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "../Utils/UtilFunctions.h"

Production get_production_from_str(const std::string &input) {
    auto trim_input = trim(input);

    auto pos = input.find("->");

    auto source = input.substr(0, pos - 1);

    auto str_destinations = input.substr(pos + 3);

    std::istringstream dest_ss(str_destinations);
    std::string destination;
    std::vector<std::string> destinations;

    while (std::getline(dest_ss, destination, '|')) {
        destinations.push_back(destination);
    }

    return Production(source, destinations);
}

void Grammar::parse(const std::string &file_path) {
    std::ifstream in(file_path);
    std::string line;

    while (std::getline(in, line)) {
        if (!line.empty() && line[0] == 'N') {
            while (std::getline(in, line)) {
                line = trim(line);

                if (line.empty())
                    break;

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                nonTerminals.push_back(line);
            }
        }

        if (!line.empty() && line[0] == 'T') {
            while (std::getline(in, line)) {
                line = trim(line);

                if (line.empty())
                    break;

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                terminals.push_back(line);
            }
        }

        if (!line.empty() && line[0] == 'P') {
            while (std::getline(in, line)) {
                line = trim(line);

                if (line.empty())
                    break;

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                Production production = get_production_from_str(line);

                if (production.getSource().find('$') != std::string::npos) {
                    isCFG = false;
                }

                productions.push_back(production);
            }
        }

        if (!line.empty() && line[0] == 's') {
            line = trim(line);

            auto pos = line.find('=');

            startingSymbol = line.substr(pos + 1);

            startingSymbol = trim(startingSymbol);
        }
    }

    in.close();
}

const std::vector<std::string> &Grammar::getNonTerminals() const {
    return nonTerminals;
}

const std::vector<std::string> &Grammar::getTerminals() const {
    return terminals;
}

const std::vector<Production> &Grammar::getProductions() const {
    return productions;
}

const std::string &Grammar::getStartingSymbol() const {
    return startingSymbol;
}

bool Grammar::checkCFG() const {
    return isCFG;
}
