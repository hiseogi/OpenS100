#pragma once

#include "../GeoMetryLibrary/Geometry.h"

#include "Enum_SGeometryType.h"
#include "GF_InformationType.h"

#include <vector>
#include <string>
#include <atlsafe.h>

class SSurface;
class Symbol;
class R_FeatureRecord;
class SENC_SymbolFill;

class SGeometry : public Geometry
{
public:
	SGeometry();
	SGeometry(const SGeometry& other);
	virtual ~SGeometry();

public:
	static int sizeOfPoint;

	// It also has a CPoint arrangement to minimize memory allocation and recovery.
	static POINT* viewPoints;

public:
	std::vector<GF::InformationType*> additionalInformation;

public:
	virtual SGeometry operator=(const SGeometry& other);

public:
	virtual SGeometryType GetType() { return SGeometryType::none; }
	
public:
	int GetInformationTypeCount() const;
	void AddInformationType(GF::InformationType* info);
	GF::InformationType* GetInformationType(int index) const;
};
