//
// Created by Emanuel on 14.11.2022.
//

#include "FiniteAutomata.h"
#include "Utils/UtilFunctions.h"

#include <fstream>
#include <vector>
#include <iostream>

std::vector<Transition> getTransitionsStartingFromState(const std::set<Transition>& transitions, const std::string& state) {
    std::vector<Transition> result;

    for (const auto& transition : transitions) {
        if (transition.getSource() == state) {
            result.push_back(transition);
        }
    }

    return result;
}

void FiniteAutomata::parse(const std::string &filePath) {
    std::ifstream in(filePath);
    std::string line;

    while (std::getline(in, line)) {
        if (line.size() > 0 && line[0] == 'Q') {
            while (std::getline(in, line)) {
                if (line.find("}") != std::string::npos) {
                    break;
                }

                line = trim(line);

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                states.insert(line);
            }
        }

        if (line.size() > 0 && line[0] == 'E') {
            while (std::getline(in, line)) {
                if (line.find("}") != std::string::npos) {
                    break;
                }

                line = trim(line);

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                alphabet.insert(line);
            }
        }

        if (line.size() > 0 && line[0] == 'f') {
            while (std::getline(in, line)) {
                if (line.find("}") != std::string::npos) {
                    break;
                }

                line = trim(line);

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                Transition transition = Transition::transitionFromString(line);

                for (const auto& el : transitions) {
                    if (el.getSource() == transition.getSource() &&
                        el.getSymbol() == transition.getSymbol() &&
                        el.getDestination() != transition.getDestination()) {
                        isDFA = false;
                    }
                }

                if (transition.getSource() == "eps") {
                    isDFA = false;
                }

                transitions.insert(transition);
            }
        }

        if (line.size() > 0 && line[0] == 'q' && line[1] == '0') {
            line = trim(line);

            auto pos = line.find('=');

            initialState = line.substr(pos + 1);

            initialState = trim(initialState);
        }

        if (line.size() > 0 && line[0] == 'F') {
            while (std::getline(in, line)) {
                if (line.find("}") != std::string::npos) {
                    break;
                }

                line = trim(line);

                if (line[line.size() - 1] == ',') {
                    line.pop_back();
                }

                finalStates.insert(line);
            }
        }
    }

    in.close();
}

const std::set<std::string> &FiniteAutomata::getStates() const {
    return states;
}

const std::set<std::string> &FiniteAutomata::getAlphabet() const {
    return alphabet;
}

const std::set<std::string> &FiniteAutomata::getFinalStates() const {
    return finalStates;
}

const std::set<Transition> &FiniteAutomata::getTransitions() const {
    return transitions;
}

const std::string &FiniteAutomata::getInitialState() const {
    return initialState;
}

bool FiniteAutomata::check(const std::string &word) const {
    std::string current = initialState;

    for (size_t i = 0; i < word.size(); ++i) {
        auto stateTransitions = getTransitionsStartingFromState(transitions, current);
        auto found = false;

        for (const auto& transition : stateTransitions) {
            if (transition.getSymbol() == std::string(1, word[i])) {
                current = transition.getDestination();
                found = true;
            }
        }

        if (!found) {
            return false;
        }
    }

    for (const auto& finalState : finalStates) {
        if (current == finalState) {
            return true;
        }
    }

    return false;
}
