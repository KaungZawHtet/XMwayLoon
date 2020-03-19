//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <wx/wx.h>
#include <gui/data_generation/encoding_type_container.h>
#include <gui/id.h>
#include <gui/data_generation/type_grid.h>
#include <gui/data_generation/generate_page.h>

void EncodingTypeContainer::onTargetEncode(wxCommandEvent &event) {

    int id = event.GetId();


    if (id == RD_UNICODE_ID)
    {
        int rowPointer = this->gpParent->ctTypeGeneration->gTypeGrid->rowPointer ;
        for (int i=0;i<rowPointer;i++)
        {
            wxString value=  this->gpParent->ctTypeGeneration->gTypeGrid->GetCellValue(i,2);
            if(value.Cmp("-"))this->gpParent->ctTypeGeneration->gTypeGrid->SetCellValue(i,2,"Unicode");

        }
        targetEncodingType = EncodingType::unicode;
    }
    if (id == RD_ZAWGYI_ID)
    {
       int rowPointer = this->gpParent->ctTypeGeneration->gTypeGrid->rowPointer ;
       for (int i=0;i<rowPointer;i++)
       {
         wxString value=  this->gpParent->ctTypeGeneration->gTypeGrid->GetCellValue(i,2);
           if(value.Cmp("-")) this->gpParent->ctTypeGeneration->gTypeGrid->SetCellValue(i,2,"Zawgyi");

       }
        targetEncodingType = EncodingType::zawgyi;

    }
    if (id == RD_RANDOM_ID)
    {
        int rowPointer = this->gpParent->ctTypeGeneration->gTypeGrid->rowPointer ;
        for (int i=0;i<rowPointer;i++)
        {
            wxString value=  this->gpParent->ctTypeGeneration->gTypeGrid->GetCellValue(i,2);
            if(value.Cmp("-"))  this->gpParent->ctTypeGeneration->gTypeGrid->SetCellValue(i,2,"Random");

        }
        targetEncodingType = EncodingType::uniform_random;
    }
    if (id == RD_CUSTOM_ID)
    { }
    event.Skip();

}