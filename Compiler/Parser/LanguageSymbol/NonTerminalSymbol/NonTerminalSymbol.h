//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_NONTERMINALSYMBOL_H
#define COMPILER_NONTERMINALSYMBOL_H

#include "../LanguageSymbol.h"

class NonTerminalSymbol : public LanguageSymbol {
public:
    explicit NonTerminalSymbol(std::string symbol);

    bool isTerminalSymbol() const final;
};


#endif //COMPILER_NONTERMINALSYMBOL_H
