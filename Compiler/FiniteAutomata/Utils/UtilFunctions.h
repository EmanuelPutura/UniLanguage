//
// Created by Emanuel on 14.11.2022.
//

#ifndef COMPILER_UTILFUNCTIONS_H
#define COMPILER_UTILFUNCTIONS_H

#include <string>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string leftTrim(const std::string& s);

std::string rightTrim(const std::string& s);

std::string trim(const std::string& s);

#endif //COMPILER_UTILFUNCTIONS_H
