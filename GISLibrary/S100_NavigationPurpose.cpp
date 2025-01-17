#include "stdafx.h"
#include "S100_NavigationPurpose.h"

namespace S100 {
    std::string S100_NavigationPurposeToString(S100_NavigationPurpose category) {
        switch (category) {
        case S100_NavigationPurpose::port: return "port";
        case S100_NavigationPurpose::transit: return "transit";
        case S100_NavigationPurpose::overview: return "overview";
        default: throw std::invalid_argument("Unknown category");
        }
    }

    S100_NavigationPurpose S100_NavigationPurposeFromString(const std::string& categoryName) {
        if (categoryName == "port") return S100_NavigationPurpose::port;
        if (categoryName == "transit") return S100_NavigationPurpose::transit;
        if (categoryName == "overview") return S100_NavigationPurpose::overview;
        throw std::invalid_argument("Unknown category name");
    }
}
