//
// Created by Emanuel on 05.11.2022.
//

#include <fstream>
#include "ProgramInternalForm.h"

const std::vector<std::pair<std::string, int>> ProgramInternalForm::getPif() const {
    return tokens;
}

void ProgramInternalForm::push(const std::string &token, int position) {
    tokens.push_back({token, position});
}

ProgramInternalForm::ProgramInternalForm(const std::string &outFilePath) : outFilePath(outFilePath) {}

std::ostream &operator<<(std::ostream &out, const ProgramInternalForm &pif) {
    for (int i = 0; i < pif.tokens.size(); ++i) {
        out << pif.tokens[i].first << std::string(" -> ") << std::to_string(pif.tokens[i].second) << std::endl;
    }

    return out;
}

void ProgramInternalForm::getPifInFile() const {
    std::ofstream fout (outFilePath);
    fout << *this << '\n';
    fout.close();
}
