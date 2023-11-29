#pragma once

#include "../FeatureCatalog/AttributeBinding.h"

#include "Enum_SGeometryType.h"
#include "R_FeatureRecord.h"

#include <vector>

#define DB2_V72_FIX_BYTE_ORDER(x) ((((x)&0x31) == (x)) ? ((x)&0x1) : (x))

typedef enum
{
	XDR = 0, /**< MSB/Sun/Motorola: Most Significant Byte First   */
	NDR = 1  /**< LSB/Intel/Vax: Least Significant Byte First      */
} ByteOrder;

class S100Layer;
class S101Cell;
class FeatureCatalogue;
class R_FeatureRecord;
class SGeometry;

class S101Creator
{
public:
	S101Creator(GISLibrary::D2D1Resources* D2);
	S101Creator(S101Cell* enc);
	S101Creator(FeatureCatalogue* fc, S101Cell* enc);
	~S101Creator();

public:
	FeatureCatalogue* fc = nullptr;
	S101Cell* enc = nullptr;
	S100Layer* layer = nullptr;
	GISLibrary::D2D1Resources* D2 = nullptr;

public:
	void Set(FeatureCatalogue* fc, S101Cell* enc);
	void SetFC(FeatureCatalogue* fc);
	void SetENC(S101Cell* enc);

	S100Layer* CreateLayer(std::string name, FeatureCatalogue* fc, PortrayalCatalogue* pc);
	S100Layer* CreateLayer(std::wstring name, FeatureCatalogue* fc, PortrayalCatalogue* pc);

	R_FeatureRecord* AddFeature(std::string code);
	R_FeatureRecord* AddFeature(std::wstring code);
	R_FeatureRecord* AddFeature(R_FeatureRecord* feature);

	R_InformationRecord* AddInformation(std::string code);
	R_InformationRecord* AddInformation(std::wstring code);

	bool DeleteFeature(int rcid);

	ATTR* AddSimpleAttribute(R_FeatureRecord* feature, std::string code, std::string value);
	ATTR* AddSimpleAttribute(R_FeatureRecord* feature, std::wstring code, std::wstring value);

	ATTR* AddSimpleAttribute(R_InformationRecord* information, std::string code, std::string value);
	ATTR* AddSimpleAttribute(R_InformationRecord* information, std::wstring code, std::wstring value);

	ATTR* AddSimpleAttribute(R_FeatureRecord* feature, ATTR* parentATTR, std::string code, std::string value);
	ATTR* AddSimpleAttribute(R_FeatureRecord* feature, ATTR* parentATTR, std::wstring code, std::wstring value);

	ATTR* AddSimpleAttribute(R_InformationRecord* information, ATTR* parentATTR, std::string code, std::string value);
	ATTR* AddSimpleAttribute(R_InformationRecord* information, ATTR* parentATTR, std::wstring code, std::wstring value);

	ATTR* AddComplexAttribute(R_FeatureRecord* feature, std::string code);
	ATTR* AddComplexAttribute(R_FeatureRecord* feature, std::wstring code);

	ATTR* AddComplexAttribute(R_InformationRecord* information, std::string code);
	ATTR* AddComplexAttribute(R_InformationRecord* information, std::wstring code);

	ATTR* AddComplexAttribute(R_FeatureRecord* feature, ATTR* parentATTR, std::string code);
	ATTR* AddComplexAttribute(R_FeatureRecord* feature, ATTR* parentATTR, std::wstring code);

	ATTR* AddComplexAttribute(R_InformationRecord* information, ATTR* parentATTR, std::string code);
	ATTR* AddComplexAttribute(R_InformationRecord* information, ATTR* parentATTR, std::wstring code);

	SGeometry* SetGeometry(R_FeatureRecord* feature, SGeometryType type, unsigned char* value, int size);
	SGeometry* SetPointGeometry(R_FeatureRecord* feature, unsigned char* value, int size);
	SGeometry* SetMultiPointGeometry(R_FeatureRecord* feature, unsigned char* value, int size);
	SGeometry* SetCurveGeometry(R_FeatureRecord* feature, unsigned char* value, int size);
	SGeometry* SetCompositeCurveGeometry(R_FeatureRecord* feature, unsigned char* value, int size);
	SGeometry* SetSurfaceGeometry(R_FeatureRecord* feature, unsigned char* value, int size);

	RecordName NewFeatureRecordName();
	RecordName NewInformationRecordName();
	RecordName NewPointRecordName();
	RecordName NewMultiPointRecordName();
	RecordName NewCurveRecordName();
	RecordName NewCompositeCurveRecordName();
	RecordName NewSurfaceRecordName();

	int GetATIXofNewRootAttribute(R_FeatureRecord* feature, int numericCode);
	int GetATIXofNewRootAttribute(R_InformationRecord* information, int numericCode);

	int GetATIXofNewChildAttribute(R_FeatureRecord* feature, ATTR* parentATTR, int numericCode);
	int GetATIXofNewChildAttribute(R_InformationRecord* information, ATTR* parentATTR, int numericCode);

	R_PointRecord* ConvertInsertVectorRecord(SPoint* geom);
	R_MultiPointRecord* ConvertInsertVectorRecord(SMultiPoint* geom);
	R_CurveRecord* ConvertInsertVectorRecord(SCurve* geom);
	R_CompositeRecord* ConvertInsertVectorRecord(SCompositeCurve* geom);
	R_SurfaceRecord* ConvertInsertVectorRecord(SSurface* geom);


	std::list<AttributeBinding*> GetAddableAttributes(R_FeatureRecord* feature);
	std::list<AttributeBinding*> GetAddableAttributes(R_FeatureRecord* feature, ATTR* parentATTR);

	void AddDefaultChildAttributes(R_FeatureRecord* feature);
	void AddDefaultChildAttributes(R_FeatureRecord* feature, ATTR* attr);

private:
	S101Cell* CreateENC(std::wstring name);
};

class S101GeometryFactory
{
public:
	static SGeometry* createFromWkb(void*, size_t = static_cast<size_t>(-1));
	static SGeometry* createGeometry(SGeometryType);
	static void destroyGeometry(SGeometry*);

	static Record* createRecord(GISLibrary::RCNM);
	static void destroyRecord(Record*);
};

class S101FieldFactory
{
public:
	static F_ATTR* createAttribute();
	static void destoryAttribute(F_ATTR*);
	static F_INAS* createInformationAssociation();
	static void destoryInformationAssociation(F_INAS*);
	static F_SPAS* createSpatialAssociation();
	static void destorySpatialAssociation(F_SPAS*);
	static F_FASC* createFeatureAssociation();
	static void destoryFeatureAssociation(F_FASC*);
	static F_MASK* createMaskedSpatialType();
	static void destoryMaskedSpatialType(F_MASK*);
};

class S101GeometryUtil
{
public:
	static SGeometryType ReadWKBGeometryType(const unsigned char*);
};