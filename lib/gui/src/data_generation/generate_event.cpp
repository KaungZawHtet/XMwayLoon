//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <gui/data_generation/generate_page.h>
#include <wx/statline.h>
#include <model/generate_info.h>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <logic/generation_task_manager/generator.h>
#include <thread>



using namespace std::chrono_literals;

void GeneratePage::onGenerate(wxCommandEvent &event) {

    /* wxMessageDialog *dial = new wxMessageDialog(this,
             wxString::Format(wxT("%d"),a), wxT("Error")); dial->ShowModal();*/

    if (validate()) {
        this->btnGenerate->SetLabel("Loading");

        GenerateInfo *objGenerateInfo = new GenerateInfo();


        objGenerateInfo->targetFile
                = std::string(this->ctGeneratedFileContainer->tcGeneratedFile->GetValue().mb_str());
        objGenerateInfo->objOutputFormat
                = this->ctOutputFormatContainer->objOutputFormat;
        objGenerateInfo->encodingType = this->ctEncodeingTypeContainer->targetEncodingType;


        this->cleanVec();
        this->vecRandomizer.reserve(this->ctTypeGeneration->gTypeGrid->rowPointer + 1);
        this->vecTitles.reserve(this->ctTypeGeneration->gTypeGrid->rowPointer + 1);


        int i = 0;
        //hard code in getting cell value; look like hard code in seting cell value
        std::for_each(this->ctTypeGeneration->gTypeGrid->vecTypeNames.begin(),
                      this->ctTypeGeneration->gTypeGrid->vecTypeNames.end(), [&](auto &element) {

                     if (strcmp(element.c_str(), typeid(BooleanType).name()) == 0)  this->setBooleanType(i);
                     else if (strcmp(element.c_str(), typeid(DateType).name()) == 0) this->setDateType(i);
                     else if (strcmp(element.c_str(), typeid(NameType).name()) == 0)   this->setNameType(i);
                     else if (strcmp(element.c_str(), typeid(NRCType).name()) == 0) this->setNRCType(i);
                     else if (strcmp(element.c_str(), typeid(NumberType).name()) == 0) this->setNumberType(i);
                     else if (strcmp(element.c_str(), typeid(PangramType).name()) == 0) this->setPangramType(i);
                     else if (strcmp(element.c_str(), typeid(PhNumberType).name()) == 0) this->setPhNumberType(i);
                     else  this->setCustomType(i);
                    i++;
                });

        objGenerateInfo->setRecordAmount(
                this->ctOutputAmountContainer->outputRecordAmount, this->ctOutputAmountContainer->outputFileSize,
                this->ctOutputAmountContainer->isRecordAmount);


        //actual type obj
        objGenerateInfo->vecRandomizers = vecRandomizer;
        objGenerateInfo->fieldCount = vecRandomizer.size();
        objGenerateInfo->vecTitles = vecTitles;


       /* std::function<void()> funcStart = [&]() {

        };*/

        std::function<void()> funcComplete = [&]() {
            this->btnGenerate->SetLabel("Generate");
            wxMessageDialog mdFinish =  wxMessageDialog(this,
                                                        wxT("Generation completed!"));
            mdFinish.ShowModal();
        };

        Generator objGenerator(objGenerateInfo,[](){});
        objGenerator.generate(funcComplete);




    } else {
        wxMessageDialog *dial = new wxMessageDialog(this,
                                                    wxT("There are some errors. Recheck your input."), wxT("Error"),wxICON_NONE);
        dial->ShowModal();
    }


    event.Skip();
}
