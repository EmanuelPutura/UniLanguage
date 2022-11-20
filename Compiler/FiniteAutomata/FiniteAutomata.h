//
// Created by Emanuel on 14.11.2022.
//

#ifndef COMPILER_FINITEAUTOMATA_H
#define COMPILER_FINITEAUTOMATA_H

#include <set>
#include <string>
#include "Transition/Transition.h"

class FiniteAutomata {
private:
    std::set<std::string> states;
    std::set<std::string> alphabet;
    std::set<Transition> transitions;

    std::string initialState;
    std::set<std::string> finalStates;

    bool isDFA = true;
public:
    void parse(const std::string& filePath);

    bool check(const std::string& word) const;

    const std::set<std::string>& getStates() const;

    const std::set<std::string>& getAlphabet() const;

    const std::string& getInitialState() const;

    const std::set<std::string>& getFinalStates() const;

    const std::set<Transition>& getTransitions() const;
};


#endif //COMPILER_FINITEAUTOMATA_H
