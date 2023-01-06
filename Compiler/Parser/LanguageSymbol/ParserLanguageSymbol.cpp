//
// Created by Emanuel on 12.12.2022.
//

#include "ParserLanguageSymbol.h"

#include <utility>

ParserLanguageSymbol::ParserLanguageSymbol(std::string symbol, int productionIndex) : symbol(std::move(symbol)), productionIndex(productionIndex) {}

const std::string &ParserLanguageSymbol::getSymbol() const {
    return symbol;
}

int ParserLanguageSymbol::getProductionIndex() const {
    return productionIndex;
}

void ParserLanguageSymbol::setProductionIndex(int newProductionIndex) {
    productionIndex = newProductionIndex;
}
