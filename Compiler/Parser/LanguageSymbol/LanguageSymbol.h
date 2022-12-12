//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_LANGUAGESYMBOL_H
#define COMPILER_LANGUAGESYMBOL_H

#include <string>

class LanguageSymbol {
public:
    explicit LanguageSymbol(std::string symbol);

    const std::string& getSymbol() const;
    int getProductionIndex() const;

    virtual bool isTerminalSymbol() const = 0;
protected:
    std::string symbol;
    int productionIndex;
};


#endif //COMPILER_LANGUAGESYMBOL_H
