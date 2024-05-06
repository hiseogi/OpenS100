#pragma once

#include "S100_Date.h"
#include <string>
#include <memory>

namespace S100 {
    class SupportFileSpecification
    {
    public:
        std::string Name;
        std::shared_ptr<std::string> Version;
        std::shared_ptr<S100_Date> Date;

        void GetContents(pugi::xml_node& node);
        void Save(pugi::xml_node& node);
    };
}
