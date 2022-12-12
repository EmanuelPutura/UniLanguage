//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_NONTERMINALSYMBOL_H
#define COMPILER_NONTERMINALSYMBOL_H

#include "../LanguageSymbol.h"

class NonTerminalSymbol : LanguageSymbol {
public:
    bool isTerminalSymbol() const final;
};


#endif //COMPILER_NONTERMINALSYMBOL_H
