#include "Production.h"

#include <algorithm>

Production::Production(const std::string &source, const std::vector<std::string> &destinations) :
        source{source},
        destinations{destinations} {
}

std::string Production::getString() const {
    std::string res = source + " -> ";

    for (auto destination: destinations) {
        destination.erase(std::remove(destination.begin(), destination.end(), '$'), destination.end());
        res += destination + " | ";
    }

    res.pop_back();
    res.pop_back();
    res.pop_back();

    return res;
}

const std::string &Production::getSource() const {
    return source;
}

__attribute__((unused)) const std::vector<std::string> &Production::getDestinations() const {
    return destinations;
}

bool operator<(const Production &el, const Production &other) {
    return el.getString() < other.getString();
}
