//
// Created by Emanuel on 11.12.2022.
//

#include "ScannerTest.h"
#include "../../SymbolTable/Tests/SymbolTableTest.h"
#include "../../Scanner/Scanner.h"

void ScannerTest::test() {
    SymbolTableTest::symbolTableTest();

    std::cout << "Program 1 scanner output:\n";
    Scanner scannerP1("../Files/Programs/p1.txt", "../Files/LanguageSpecification/tokens.in");
    scannerP1.scan();

    std::cout << "Program 2 scanner output:\n";
    Scanner scannerP2("../Files/Programs/p2.txt", "../Files/LanguageSpecification/tokens.in");
    scannerP2.scan();

    std::cout << "Program 3 scanner output:\n";
    Scanner scannerP3("../Files/Programs/p3.txt", "../Files/LanguageSpecification/tokens.in");
    scannerP3.scan();

    std::cout << "Program 1 containing errors scanner output:\n";
    Scanner scannerP1Error("../Files/Programs/p_err1.txt", "../Files/LanguageSpecification/tokens.in");
    scannerP1Error.scan();
}
