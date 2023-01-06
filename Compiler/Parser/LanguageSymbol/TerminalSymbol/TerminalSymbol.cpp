//
// Created by Emanuel on 12.12.2022.
//

#include "TerminalSymbol.h"

bool TerminalSymbol::isTerminalSymbol() const {
    return true;
}

TerminalSymbol::TerminalSymbol(std::string symbol, int productionIndex) : ParserLanguageSymbol(symbol, productionIndex) {

}
