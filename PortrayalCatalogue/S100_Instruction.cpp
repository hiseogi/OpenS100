#include "stdafx.h"
#include "S100_Instruction.h"

S100_Instruction::S100_Instruction() : type(0)
{

}

S100_Instruction::~S100_Instruction()
{
	for (auto itor = spatialReference.begin(); itor != spatialReference.end(); itor++)
	{
		delete *itor;
	}
}

void S100_Instruction::GetContents(pugi::xml_node node)
{

}

void S100_Instruction::SetType(int value) 
{
	type = value;
}

void S100_Instruction::SetFeatureReference(std::wstring& value)
{
	featureReference = value;
}

void S100_Instruction::SetFeatureReference(std::string& value)
{
	if (value.empty())
		featureReference = _T("");
	else
	{
		std::wstring FeatureReference(value.begin(), value.end());
		SetFeatureReference(FeatureReference);
	}
}

void S100_Instruction::setId(std::string value)
{
	id = value;
}

void S100_Instruction::setParentId(std::string value)
{
	parentId = value;
}

void S100_Instruction::setHover(bool value)
{
	hover = value;
}

void S100_Instruction::SetSpatialReference(S100_SpatialReference* value)
{
	spatialReference.push_back(value);
}

void S100_Instruction::SetSpatialReference(std::list<S100_SpatialReference*> value) 
{
	spatialReference = value;
}

void S100_Instruction::SetViewingGroup(std::wstring& value)
{
	viewingGroup.push_back(value);
}

void S100_Instruction::SetViewingGroup(std::string& value)
{
	if (value.empty())
		return;

	std::wstring ViewingGroup(value.begin(), value.end());
	SetViewingGroup(ViewingGroup);
}

void S100_Instruction::SetDisplayPlane(std::wstring& value)
{
	displayPlane = value;
}

void S100_Instruction::SetDisplayPlane(std::string& value)
{
	if (value.empty())
		displayPlane = _T("");
	else
	{
		std::wstring DisplayPlane(value.begin(), value.end());
		SetDisplayPlane(DisplayPlane);
	}
}

void S100_Instruction::SetDrawingPriority(std::wstring& value)
{
	drawingPriority = _ttoi(value.c_str());
}

void S100_Instruction::SetDrawingPriority(std::string& value)
{
	drawingPriority = atoi(value.c_str());
}

void S100_Instruction::SetDrawingPriority(int value)
{
	drawingPriority = value;
}

void S100_Instruction::SetScaleMinimum(std::wstring& value)
{
	scaleMinimum = _ttoi(value.c_str());
}

void S100_Instruction::SetScaleMinimum(std::string& value)
{
	scaleMinimum = atoi(value.c_str());
}

void S100_Instruction::SetScaleMinimum(int value)
{
	scaleMinimum = value;
}

void S100_Instruction::SetScaleMaximum(std::wstring& value)
{
	scaleMaximum = _ttoi(value.c_str());
}

void S100_Instruction::SetScaleMaximum(std::string& value)
{
	scaleMaximum = atoi(value.c_str());
}

void S100_Instruction::SetScaleMaximum(int value)
{
	scaleMaximum = value;
}

void S100_Instruction::setAlertReference(S100_AlertReference value)
{
	alertReference = value;
}

int S100_Instruction::GetType() 
{
	return type;
}

const std::wstring& S100_Instruction::GetFeatureReference()
{
	return featureReference;
}

const std::string S100_Instruction::getId()
{
	if (id.has_value())
	{
		return id.value();
	}

	return std::string("");
}

const std::string S100_Instruction::getParentId()
{
	if (parentId.has_value())
	{
		return parentId.value();
	}

	return std::string("");
}

const bool S100_Instruction::getHover()
{
	if (hover.has_value())
	{
		return hover.value();
	}

	return false;
}

S100_SpatialReference* S100_Instruction::GetSpatialReference(int index) 
{
	auto it = spatialReference.begin();
	advance(it, index);
	return *it;
}
std::list<S100_SpatialReference*> S100_Instruction::GetSpatialReference()
{
	return spatialReference;
}

std::wstring S100_Instruction::GetViewingGroup(int index) 
{
	if (index >= 0 && index < viewingGroup.size())
	{
		return viewingGroup[index];
	}

	return L"";
}

int S100_Instruction::getViewingGroupCount()
{
	return (int)viewingGroup.size();
}

std::wstring S100_Instruction::GetDisplayPlane()
{
	return displayPlane;
}

int S100_Instruction::GetDrawingProiority()
{
	return drawingPriority;
}

int S100_Instruction::GetScaleMinimum()
{
	if (scaleMinimum.has_value())
	{
		return scaleMinimum.value();
	}

	return 0;
}
int S100_Instruction::GetScaleMaximum() 
{
	if (scaleMaximum.has_value())
	{
		return scaleMaximum.value();
	}

	return 0;
}

bool S100_Instruction::hasAlertReference()
{
	return alertReference.has_value();
}

S100_AlertReference S100_Instruction::getAlertReference()
{
	if (alertReference.has_value())
	{
		return alertReference.value();
	}

	return S100_AlertReference();
}