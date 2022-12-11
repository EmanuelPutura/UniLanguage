#pragma once

#include <string>
#include <vector>

#include "Production/Production.h"

class Grammar {
private:
    std::vector<std::string> nonterminals;
    std::vector<std::string> terminals;
    std::vector<Production> productions;
    std::string startingSymbol;
    bool isCFG = true;
public:
    Grammar() = default;

    ~Grammar() = default;

    void parse(const std::string &file_path);

    const std::vector<std::string> &getNonterminals() const;

    const std::vector<std::string> &getTerminals() const;

    const std::vector<Production> &getProductions() const;

    const std::string &getStartingSymbol() const;

    bool checkCFG() const;
};