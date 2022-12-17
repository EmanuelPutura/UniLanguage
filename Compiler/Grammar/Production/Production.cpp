#include "Production.h"

#include <algorithm>
#include <sstream>

Production::Production(const std::string &source, const std::vector<std::string> &destinations) :
        source{source},
        destinations{destinations} {
}

std::string Production::toString() const {
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

std::vector<std::vector<std::string>> Production::getDestinations() const {
    std::vector<std::vector<std::string>> res(destinations.size(), std::vector<std::string>());

    for (size_t i = 0; i < res.size(); ++i) {
        std::istringstream dest_ss(destinations[i]);
        std::string symbol;

        while (std::getline(dest_ss, symbol, '$')) {
            res[i].push_back(symbol);
        }
    }

    return res;
}


bool operator<(const Production &el, const Production &other) {
    return el.toString() < other.toString();
}

const std::vector<std::string> &Production::getDestinationsRaw() const {
    return destinations;
}
