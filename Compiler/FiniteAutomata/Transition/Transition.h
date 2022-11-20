//
// Created by Emanuel on 14.11.2022.
//

#ifndef COMPILER_TRANSITION_H
#define COMPILER_TRANSITION_H

#include <string>

class Transition {
private:
    std::string source;
    std::string destination;
    std::string symbol;
public:
    Transition(const std::string& source, const std::string& destination, const std::string& symbol);

    static Transition transitionFromString(const std::string& input);

    friend bool operator< (const Transition& t1, const Transition& t2);

    std::string toString() const;

    const std::string& getSource() const;

    const std::string& getDestination() const;

    const std::string& getSymbol() const;
};


#endif //COMPILER_TRANSITION_H
