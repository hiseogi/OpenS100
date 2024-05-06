#include "stdafx.h"
#include "ExchangeCatalogueIdentifier.h"

namespace S100 {
    void ExchangeCatalogueIdentifier::GetContents(pugi::xml_node& node)
    {
        for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
        {
            const pugi::char_t* instructionName = instruction.name();

            if (!strcmp(instructionName, "S100XC:identifier"))
            {
                Identifier = instruction.child_value();
            }
            else if (!strcmp(instructionName, "S100XC:dateTime"))
            {
                DateTime = S100_DateTime(instruction.child_value());
                std::string str = DateTime.ToString();
            }
            else
            {
                std::wstring content = pugi::as_wide(instructionName);
                content.append(L"is another data");
            }
        }
    }

    void ExchangeCatalogueIdentifier::Save(pugi::xml_node& node)
    {
        if (Identifier != "")
        {
            auto item = node.append_child("S100XC:identifier");
             item.text().set(Identifier.c_str());
        }
        {
            auto item = node.append_child("S100XC:dateTime");
            DateTime.Save(item);
        }
        
    }
}
