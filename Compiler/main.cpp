#include "SymbolTable/Tests/SymbolTableTest.h"
#include "Scanner/Scanner.h"

int main() {
    SymbolTableTest::symbolTableTest();

    Scanner scanner ("../Files/Programs/p3.txt", "../Files/LanguageSpecification/tokens.in");
    scanner.scan();

    return 0;
}
