#include "Tests/Scanner/ScannerTest.h"
#include "Tests/FiniteAutomata/FiniteAutomataTest.h"
#include "Tests/Grammar/GrammarTest.h"
#include "Tests/Parser/ParserTest.h"

int main() {
//    ScannerTest::test();
//    FiniteAutomataTest::test();
//    GrammarTest::test();

    ParserTest::testFileContextFreeGrammar();
//    ParserTest::testLanguageGrammar();
//    ParserTest::testLanguageGrammar();

    return 0;
}
