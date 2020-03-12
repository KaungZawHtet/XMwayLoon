//
// Created by Kaung Zaw Htet on 2020-01-16.
//
#include <gui/data_generation/generate_page.h>

bool GeneratePage::validate() {

    bool doesTypeExist= !this->ctTypeGeneration->gTypeGrid->vecTypeNames.empty();

    bool doesLocationExist=this->ctGeneratedFileContainer->tcGeneratedFile->GetValue()!="";
    bool doesFormatExist
    = (this->ctOutputFormatContainer->cbXML->GetValue()
            or this->ctOutputFormatContainer->cbJSON->GetValue()
            or this->ctOutputFormatContainer->cbHTML->GetValue()
            or this->ctOutputFormatContainer->cbCSV->GetValue());

    if(!doesLocationExist)
    {
        this->ctGeneratedFileContainer->stError->SetLabelText("Fill a location for generated file");
        this->ctGeneratedFileContainer->stError->SetForegroundColour(wxColor(*wxRED));

    } else this->ctGeneratedFileContainer->stError->SetLabelText("");


    if(!doesFormatExist)
    {
        this->ctOutputFormatContainer->stError->SetLabelText("Select at least one file format");
        this->ctOutputFormatContainer->stError->SetForegroundColour(wxColor(*wxRED));
    } else  this->ctOutputFormatContainer->stError->SetLabelText("");

    if(!doesTypeExist)
    {
        this->ctTypeGeneration->stError->SetLabelText("add at least one type");
        this->ctTypeGeneration->stError->SetForegroundColour(wxColor(*wxRED));
    } else  this->ctTypeGeneration->stError->SetLabelText("");


    if(doesFormatExist and doesLocationExist and doesTypeExist) return true;
    else return false;

}

void GeneratePage::cleanVec() {
    std::for_each(this->vecRandomizer.begin(),this->vecRandomizer.end(),[](auto &item){
        delete item;
    });
    this->vecRandomizer.clear();
    this->vecTitles.clear();

}

GeneratePage::~GeneratePage() {
this->cleanVec();
}
