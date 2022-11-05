//
// Created by Emanuel on 05.11.2022.
//

#include "SymbolTableTest.h"

void SymbolTableTest::symbolTableTest() {
    const std::vector<std::pair<std::string, int>> testData = {
            {"S1", 1}, {"S2", 2}, {"S1", 1}, {"S3", 3}, {"S3", 3},
            {"S2", 2}, {"S4", 4}, {"S1", 1}
    };

    SymbolTable st;

    for (size_t i = 0; i < testData.size(); ++i) {
        assert(st.retrievePosition(testData[i].first) == testData[i].second);
    }
}
