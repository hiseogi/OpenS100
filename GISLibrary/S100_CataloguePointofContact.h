#pragma once

#include <string>
#include "CI_Address.h"
#include "CI_Telephone.h"

namespace S100 {
    class S100_CataloguePointofContact
    {
    public:
        std::string Organization;
        CI_Telephone Phone;
        CI_Address Address;

        void GetContents(pugi::xml_node& node);
    };
}
