#pragma once

#include "PT_Locale.h"
#include "URI.h"
#include "S100_SupportFileFormat.h"
#include "S100_ResourcePurpose.h"
#include "S100_SupportFileRevisionStatus.h"
#include "S100_SupportFileSpecification.h"
#include "XML_Collection.h"
#include <memory>
#include <vector>
#include <string>
#include "pugiSupportClass.h"
#include "S100_SE_DigitalSignatureReference.h"
#include "S100_SE_DigitalSignature.h"

namespace S100 {
    class S100_SupportFileDiscoveryMetadata : public xmlParseable
    {
    public:
        URI FileName;
        S100_SupportFileRevisionStatus RevisionStatus;
        int EditionNumber;
        std::shared_ptr<S100_Date> IssueDate;
        std::shared_ptr<S100_SupportFileSpecification> SupportFileSpecification;
        S100_SupportFileFormat DataType;
        std::shared_ptr<std::string> OtherDataTypeDescription;
        std::shared_ptr<std::string> Comment;
        bool CompressionFlag;
        S100_SE_DigitalSignatureReference DigitalSignatureReference;
        std::vector<S100_SE_DigitalSignature> DigitalSignatureValue;
        std::shared_ptr<PT_Locale> DefaultLocale;
        std::vector<std::string> SupportedResource;
        std::shared_ptr<S100_ResourcePurpose>  ResourcePurpose;

        void GetContents(pugi::xml_node& node) override;
    };
}
