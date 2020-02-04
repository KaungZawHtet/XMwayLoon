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


        std::vector<type> vecTypes;
        vecTypes.reserve(this->ctTypeGeneration->gTypeGrid->rowPointer + 1);

        int i = 0;
        //hard code in getting cell value; look like hard code in seting cell value
        std::for_each(this->ctTypeGeneration->gTypeGrid->vecTypeNames.begin(),
                      this->ctTypeGeneration->gTypeGrid->vecTypeNames.end(), [&](auto &element) {

                    if (strcmp(element.c_str(), typeid(BooleanType).name()) == 0) {

                        BooleanType objBooleanType;

                        objBooleanType.index = i;
                        objBooleanType.encoding = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2);
                        objBooleanType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objBooleanType.type = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);

                        vecTypes.emplace_back(objBooleanType);

                    } else if (strcmp(element.c_str(), typeid(DateType).name()) == 0) {
                        DateType objDateType;

                        objDateType.index=i;
                        objDateType.encoding=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2);
                        objDateType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objDateType.format=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);

                        vecTypes.emplace_back(objDateType);
                    } else if (strcmp(element.c_str(), typeid(NameType).name()) == 0) {

                        NameType objNameType;
                        objNameType.index=i;
                        objNameType.encoding=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2);
                        objNameType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        std::string strGender{this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).c_str() };
                        objNameType.gender=genderMap[strGender];

                        vecTypes.emplace_back(objNameType);
                    } else if (strcmp(element.c_str(), typeid(NRCType).name()) == 0) {

                        NRCType objNRCType;

                        objNRCType.index=i;
                        objNRCType.encoding=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2);
                        objNRCType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objNRCType.type=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);

                        vecTypes.emplace_back(objNRCType);
                    } else if (strcmp(element.c_str(), typeid(NumberType).name()) == 0) {
                        NumberType objNumberType;

                        objNumberType.index=i;

                        objNumberType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objNumberType.type=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);
                        objNumberType.prefix=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5);
                        objNumberType.postfix=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 6);

                        vecTypes.emplace_back(objNumberType);
                    } else if (strcmp(element.c_str(), typeid(PangramType).name()) == 0) {

                        PangramType objPangramType;

                        objPangramType.index=i;
                        objPangramType.encoding=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2);
                        objPangramType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

                        vecTypes.emplace_back(objPangramType);
                    } else if (strcmp(element.c_str(), typeid(PhNumberType).name()) == 0) {
                        PhNumberType objPhNumberType;

                        objPhNumberType.index=i;

                        objPhNumberType.fieldName=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
                        objPhNumberType.countryCode=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);
                        objPhNumberType.telecom=this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5);

                        vecTypes.emplace_back(objPhNumberType);
                    } else {

                    }
                    i++;
                });

        //just type names
        objGenerateInfo.vecTypeNames=this->ctTypeGeneration->gTypeGrid->vecTypeNames; // dont move for safety

        //actual type obj
        objGenerateInfo.vecTypes=std::move(vecTypes) ;

        Generator objGenerator(objGenerateInfo);
        objGenerator.generate();

    }







    event.Skip();
}
