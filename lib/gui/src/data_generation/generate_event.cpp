//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <gui/data_generation/generate_page.h>
#include <wx/statline.h>
#include <model/generate_info.h>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <model/type/typedef.h>
#include <logic/generation_task_manager/generator.h>

void GeneratePage::onGenerate(wxCommandEvent &event) {
    // int a = this->scRecordNumber->GetValue();

    /* wxMessageDialog *dial = new wxMessageDialog(this,
             wxString::Format(wxT("%d"),a), wxT("Error")); dial->ShowModal();*/

    if(validate())
    {
        GenerateInfo objGenerateInfo;


        objGenerateInfo.targetFile
                = std::string(this->ctGeneratedFileContainer->tcGeneratedFile->GetValue().mb_str());
        objGenerateInfo.objOutputFormat
                = this->ctOutputFormatContainer->objOutputFormat;
        objGenerateInfo.outputRecordAmount = this->ctOutputAmountContainer->outputRecordAmount;
        objGenerateInfo.outputFileSize = this->ctOutputAmountContainer->outputFileSize;
        objGenerateInfo.encodingType = this->ctEncodeingTypeContainer->targetEncodingType;


        this->cleanVec();
        this->vecRandomizer.reserve(this->ctTypeGeneration->gTypeGrid->rowPointer + 1);

        std::vector<std::string> vecTitles;
        vecTitles.reserve(this->ctTypeGeneration->gTypeGrid->rowPointer + 1);


        int i = 0;
        //hard code in getting cell value; look like hard code in seting cell value
        std::for_each(this->ctTypeGeneration->gTypeGrid->vecTypeNames.begin(),
                      this->ctTypeGeneration->gTypeGrid->vecTypeNames.end(), [&](auto &element) {

                    if (strcmp(element.c_str(), typeid(BooleanType).name()) == 0) {

                        BooleanType objBooleanType;

                        objBooleanType.index = i;
                        std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
                        objBooleanType.setEncoding(  tmp_encode );
                        objBooleanType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        std::string tmp_type( this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
                        objBooleanType.setType(tmp_type );



                        vecTitles.emplace_back(objBooleanType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::BooleanRandomizer(objBooleanType));

                    } else if (strcmp(element.c_str(), typeid(DateType).name()) == 0) {
                        DateType objDateType;

                        objDateType.index=i;
                        std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
                        objDateType.setEncoding(  tmp_encode );
                        objDateType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objDateType.format=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);

                        vecTitles.emplace_back(objDateType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::DateRandomizer(objDateType));
                    } else if (strcmp(element.c_str(), typeid(NameType).name()) == 0) {

                        NameType objNameType;
                        objNameType.index=i;
                        std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
                        objNameType.setEncoding(  tmp_encode );
                        objNameType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        std::string strGender{this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).c_str() };
                        objNameType.gender=XML_RE::genderMap[strGender];

                        vecTitles.emplace_back(objNameType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NameRandomizer(objNameType));
                    } else if (strcmp(element.c_str(), typeid(NRCType).name()) == 0) {

                        NRCType objNRCType;

                        objNRCType.index=i;
                        std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
                        objNRCType.setEncoding(  tmp_encode );
                        objNRCType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        std::string tmp(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
                        objNRCType.setType(tmp);

                        vecTitles.emplace_back(objNRCType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NRCRandomizer(objNRCType));
                    } else if (strcmp(element.c_str(), typeid(NumberType).name()) == 0) {
                        NumberType objNumberType;

                        objNumberType.index=i;

                        objNumberType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        std::string tmpSystem(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
                        objNumberType.setSystem(tmpSystem);
                        objNumberType.prefix=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5);
                        objNumberType.postfix=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 6);

                        std::string tmpMin(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 7).mb_str());
                        std::string tmpMax(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 8).mb_str());
                        objNumberType.setMin(tmpMin);
                        objNumberType.setMax(tmpMax);

                        vecTitles.emplace_back(objNumberType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NumberRandomizer(objNumberType));
                    } else if (strcmp(element.c_str(), typeid(PangramType).name()) == 0) {

                        PangramType objPangramType;

                        objPangramType.index=i;
                        std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
                        objPangramType.setEncoding(  tmp_encode );
                        objPangramType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        vecTitles.emplace_back(objPangramType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::PangramRandomizer(objPangramType));
                    } else if (strcmp(element.c_str(), typeid(PhNumberType).name()) == 0) {
                        PhNumberType objPhNumberType;

                        objPhNumberType.index=i;

                        objPhNumberType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        std::string tmp_countryCodeFlat(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
                        objPhNumberType.setCountryCodeFlag(tmp_countryCodeFlat);
                        std::string tmp_telecom(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5).mb_str());
                        objPhNumberType.setTelecom(tmp_telecom);

                        vecTitles.emplace_back(objPhNumberType.fieldName);
                        this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::PhoneNumberRandomizer(objPhNumberType));
                    } else {

                    }
                    i++;
                });

        //just type names
     //   objGenerateInfo.vecTypeNames=this->ctTypeGeneration->gTypeGrid->vecTypeNames; // dont move for safety

        //actual type obj
        objGenerateInfo.vecRandomizers=vecRandomizer;
        objGenerateInfo.fieldCount =vecRandomizer.size();

        objGenerateInfo.vecTitles=std::move(vecTitles);

        Generator objGenerator(objGenerateInfo);
        objGenerator.generate();

    } else
    {
        wxMessageDialog *dial = new wxMessageDialog(this,
                                                    wxT("This is error"), wxT("Error")); dial->ShowModal();
    }







    event.Skip();
}
