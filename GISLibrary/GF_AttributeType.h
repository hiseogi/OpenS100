#pragma once

#include "GF_PropertyType.h"

#include "../FeatureCatalog/Multiplicity.h"

#include <string>

namespace GF
{
	class AttributeType :
		public PropertyType
	{
	public:
		AttributeType();
		AttributeType(const AttributeType& other) : PropertyType(other) {};
		virtual ~AttributeType();

	public:

	public:
		virtual bool IsSimple() { return false; }
		virtual std::string GetValue() { return "";}
	};
}