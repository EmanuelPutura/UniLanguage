//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_TERMINALSYMBOL_H
#define COMPILER_TERMINALSYMBOL_H

#include "../LanguageSymbol.h"

class TerminalSymbol : public LanguageSymbol {
public:
    bool isTerminalSymbol() const final ;
};


#endif //COMPILER_TERMINALSYMBOL_H
