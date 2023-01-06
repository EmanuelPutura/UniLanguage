//
// Created by Emanuel on 12.12.2022.
//

#ifndef COMPILER_PARSERLANGUAGESYMBOL_H
#define COMPILER_PARSERLANGUAGESYMBOL_H

#include <string>

class ParserLanguageSymbol {
public:
    explicit ParserLanguageSymbol(std::string symbol, int productionIndex);
    virtual ~ParserLanguageSymbol() = default;

    void setProductionIndex(int newProductionIndex);

    const std::string& getSymbol() const;
    int getProductionIndex() const;

    virtual bool isTerminalSymbol() const = 0;
protected:
    std::string symbol;
    int productionIndex;
};


#endif //COMPILER_PARSERLANGUAGESYMBOL_H
