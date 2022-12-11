//
// Created by Emanuel on 14.11.2022.
//

#include "Transition.h"
#include "../../Utils/UtilFunctions.h"

Transition::Transition(const std::string &source, const std::string &symbol, const std::string &destination) :
        source(source), destination(destination), symbol(symbol) {}

const std::string &Transition::getDestination() const {
    return destination;
}

const std::string &Transition::getSymbol() const {
    return symbol;
}

const std::string &Transition::getSource() const {
    return source;
}

std::string Transition::toString() const {
    return "(" + source + ", " + destination + ") -> " + symbol;
}

bool operator<(const Transition &t1, const Transition &t2) {
    return t1.toString() < t2.toString();
}

Transition Transition::transitionFromString(const std::string& input) {
    auto trim_input = trim(input);
    auto pos = trim_input.find(",");
    auto init_state = trim_input.substr(1, pos - 1);
    auto closing_par_pos = trim_input.find(")");
    auto symbol = trim_input.substr(pos + 2, closing_par_pos - pos - 2);

    pos = trim_input.find("->");
    pos += 3;

    auto fin_state = trim_input.substr(pos);
    return Transition(init_state, symbol, fin_state);
}
