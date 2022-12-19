//
// Created by Emanuel on 12.12.2022.
//

#include "NonTerminalSymbol.h"

#include <utility>

bool NonTerminalSymbol::isTerminalSymbol() const {
    return false;
}

NonTerminalSymbol::NonTerminalSymbol(std::string symbol) : ParserLanguageSymbol(std::move(symbol)) {

}
