//
// Created by Emanuel on 12.12.2022.
//

#include "ParserLanguageSymbol.h"

#include <utility>

ParserLanguageSymbol::ParserLanguageSymbol(std::string symbol) : symbol(std::move(symbol)), productionIndex(0) {}

const std::string &ParserLanguageSymbol::getSymbol() const {
    return symbol;
}

int ParserLanguageSymbol::getProductionIndex() const {
    return productionIndex;
}
