#pragma once
#include "S100_RuleFile.h"

#include "..\\extlibs\pugixml\include\pugixml.hpp"

#include <unordered_map>
#include <string>

class S100_Rules
{
public:
	S100_Rules();
	virtual ~S100_Rules();

private:
	std::unordered_map<std::string, S100_RuleFile*> ruleFiles;

public:
	void AddRuleFiles(std::string& key, S100_RuleFile* value);
	void SetRuleFiles(std::unordered_map<std::string, S100_RuleFile*> value);

	S100_RuleFile* GetRuleFiles(std::string& key);
	std::unordered_map<std::string, S100_RuleFile*> GetRuleFiles();

	void GetContents(MSXML2::IXMLDOMNodePtr pNode);
	void GetContents(pugi::xml_node& node);
};