#pragma once

#include <string>
#include <vector>

class Production
{
private:
    std::string source;
    std::vector<std::string> destinations;
public:
    Production(const std::string& source, const std::vector<std::string>& destinations);

    std::string getString() const;

    friend bool operator<(const Production &el, const Production &other);

    const std::string& getSource() const;

    __attribute__((unused)) const std::vector<std::string>& getDestinations() const;
};

