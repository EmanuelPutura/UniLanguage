//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_NONTERMINALSYMBOL_H
#define COMPILER_NONTERMINALSYMBOL_H

#include "../ParserLanguageSymbol.h"

class NonTerminalSymbol : public ParserLanguageSymbol {
public:
    explicit NonTerminalSymbol(std::string symbol, int productionIndex);

    bool isTerminalSymbol() const final;
};


#endif //COMPILER_NONTERMINALSYMBOL_H
