#pragma once
#include "S100_IC_DrawingInstruction.h"
#include "S100_IC_Feature.h"
#include "XML_Collection.h"

namespace S100
{
	class S100_IC_DisplayPlane : public xmlParseable
	{
	public:
		std::string Identifier;
		std::string Name;
		int Order;
		std::string Description;
		int* InteroperabilityLevel;
		XmlCollection<S100_IC_Feature> Features;
		XmlCollection<S100_IC_DrawingInstruction> DrawingInstructions;

		inline void GetContents(pugi::xml_node& node) override
		{
			for (pugi::xml_node instruction = node.first_child(); instruction; instruction = instruction.next_sibling())
			{
				const pugi::char_t* instructionName = instruction.name();

				if (!strcmp(instructionName, "identifier"))
				{
					Identifier = instruction.child_value();
				}
				else if (!strcmp(instructionName, "name"))
				{
					Name = instruction.child_value();
				}
				else if (!strcmp(instructionName, "order"))
				{
					Order = atoi(instruction.child_value());
				}
				else if (!strcmp(instructionName, "description"))
				{
					Description = instruction.child_value();
				}
				else if (!strcmp(instructionName, "interoperabilityLevel"))
				{
					InteroperabilityLevel = new int(atoi(instruction.child_value()));
				}
				else if (!strcmp(instructionName, "features"))
				{
					Features.parseXmlNode(instruction, "S100_IC_Feature");
				}
				else if (!strcmp(instructionName, "drawingInstructions"))
				{
					Features.parseXmlNode(instruction, "S100_IC_DrawingInstruction");
				}
				else
				{
					std::wstring content = pugi::as_wide(instructionName);
					content.append(L"is another data");
				}
			}
		}
	};

}
