#include "Grammar.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "../Utils/UtilFunctions.h"

Production getProductionFromStr(const std::string &input) {
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

                nonTerminals.insert(line);
            }
        }

        if (!line.empty() && line[0] == 'T') {
            while (std::getline(in, line)) {
                line = trim(line);

                if (line.empty())
                    break;

                terminals.insert(line);
            }
        }

        if (!line.empty() && line[0] == 'P') {
            while (std::getline(in, line)) {
                line = trim(line);

                if (line.empty())
                    break;

                Production production = getProductionFromStr(line);

                if (production.getSource().find('$') != std::string::npos) {
                    isCFG = false;
                }

                productions.insert({production.getSource(), production});
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

const std::unordered_set<std::string> &Grammar::getNonTerminals() const {
    return nonTerminals;
}

const std::unordered_set<std::string> &Grammar::getTerminals() const {
    return terminals;
}

const std::unordered_map<std::string, Production> &Grammar::getProductions() const {
    return productions;
}

const std::string &Grammar::getStartingSymbol() const {
    return startingSymbol;
}

bool Grammar::checkCFG() const {
    return isCFG;
}

std::vector<std::vector<std::string>> Grammar::getDestinationsForSource(const std::string& source) const {
    auto productionIt = productions.find(source);
    if (productionIt == productions.end()) {
        return {};
    }

    return productionIt->second.getDestinations();
}

std::vector<std::string> Grammar::getDestinationsForSourceRaw(const std::string &source) const {
    auto productionIt = productions.find(source);
    if (productionIt == productions.end()) {
        return {};
    }

    return productionIt->second.getDestinationsRaw();
}
