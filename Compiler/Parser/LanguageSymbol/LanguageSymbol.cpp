//
// Created by Emanuel on 12.12.2022.
//

#include "LanguageSymbol.h"

#include <utility>

LanguageSymbol::LanguageSymbol(std::string symbol) : symbol(std::move(symbol)), productionIndex(0) {}

const std::string &LanguageSymbol::getSymbol() const {
    return symbol;
}

int LanguageSymbol::getProductionIndex() const {
    return productionIndex;
}
