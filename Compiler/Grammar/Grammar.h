#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "Production/Production.h"

class Grammar {
private:
    std::unordered_set<std::string> nonTerminals;
    std::unordered_set<std::string> terminals;
    std::unordered_map<std::string, Production> productions;
    std::string startingSymbol;
    bool isCFG = true;
public:
    Grammar() = default;

    ~Grammar() = default;

    void parse(const std::string &file_path);

    const std::unordered_set<std::string> &getNonTerminals() const;

    const std::unordered_set<std::string> &getTerminals() const;

    const std::unordered_map<std::string, Production> &getProductions() const;

    std::vector<std::vector<std::string>> getDestinationsForSource(const std::string& source) const;

    std::vector<std::string> getDestinationsForSourceRaw(const std::string& source) const;

    const std::string &getStartingSymbol() const;

    bool checkCFG() const;
};