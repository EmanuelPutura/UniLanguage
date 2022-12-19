//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_TERMINALSYMBOL_H
#define COMPILER_TERMINALSYMBOL_H

#include "../ParserLanguageSymbol.h"

class TerminalSymbol : public ParserLanguageSymbol {
public:
    explicit TerminalSymbol(std::string symbol);

    bool isTerminalSymbol() const final ;
};


#endif //COMPILER_TERMINALSYMBOL_H
