//
// Created by Emanuel on 05.11.2022.
//

#ifndef COMPILER_PROGRAMINTERNALFORM_H
#define COMPILER_PROGRAMINTERNALFORM_H

#include <vector>
#include <string>

class ProgramInternalForm {
private:
    std::string outFilePath;
    std::vector<std::pair<std::string, int>> tokens;
public:
    ProgramInternalForm(const std::string& outFilePath);

    const std::vector<std::pair<std::string, int>> getPif() const;

    void getPifInFile() const;

    void push(const std::string& token, int position);

    friend std::ostream& operator<< (std::ostream& out, const ProgramInternalForm& pif);
};


#endif //COMPILER_PROGRAMINTERNALFORM_H
