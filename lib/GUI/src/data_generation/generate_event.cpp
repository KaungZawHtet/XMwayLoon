//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#include <gui/data_generation/generate_page.h>
#include <wx/statline.h>
#include <model/model.h>


void GeneratePage::onGenerate(wxCommandEvent &event) {
    // int a = this->scRecordNumber->GetValue();

    /* wxMessageDialog *dial = new wxMessageDialog(this,
             wxString::Format(wxT("%d"),a), wxT("Error")); dial->ShowModal();*/

    GenerateInfo objGenerateInfo;


    objGenerateInfo.targetFile
    =std::string(this->ctGenerateFileContainer->tcGenerateFile->GetValue().mb_str());
    objGenerateInfo.objOutputFormat
    =this->ctOutputFormatContainer->objOutputFormat;
    objGenerateInfo.outputRecordAmount=this->ctOutputAmountContainer->outputRecordAmount;
    objGenerateInfo.outputFileSize=this->ctOutputAmountContainer->outputFileSize;
    objGenerateInfo.encodingType=this->ctEncodeingTypeContainer->targetEncodingType;

    int rowPointer=this->ctTypeGeneration->gTypeGrid->rowPointer;

    for(int i=0;i<rowPointer;i++)
    {

    }









    event.Skip();
}
