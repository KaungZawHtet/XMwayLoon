//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#include <wx/wx.h>
#include <gui/data_generation/output_amount_container.h>
#include <gui/id.h>
#include <gui/data_generation/generate_page.h>
#include <dry_comparisons/dry_comparisons.h>


OutputAmountContainer::OutputAmountContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain)
:wxControl(tmp_gpParent,-1)
{

    this->bsMain=tmp_bsMain;
    this->gpParent=tmp_gpParent;


      this->bsRecordSize = new wxBoxSizer(wxHORIZONTAL);
      this->sl1 = new wxStaticLine(this->gpParent, wxID_ANY, wxPoint(-1, -1),
                                   wxSize(300, 1));
      this->bsRecordSizeTitle = new wxBoxSizer(wxHORIZONTAL);
      this->stRecordSizeTitle = new wxStaticText(this->gpParent, -1,
                                                 wxT("Output Amount : "),
                                                 wxPoint(-1, -1), wxSize(-1, -1));
    this->stRecordSizeTitle->SetFont(this->gpParent->font->Bold());


      this->stRecordNumberUnit = new wxStaticText(this->gpParent, -1,
                                                  wxT("records"));

      this->scRecordNumber = new wxSpinCtrl(this->gpParent, SC_RECORD_NUMBER_ID, wxString(""),
                                            wxPoint(-1, -1), wxSize(-1, -1), wxSP_ARROW_KEYS,
                                            1, INT_MAX, 100);
      this->outputRecordAmount=100;
   /*
    * TODO: skip for coming version

    this->rdRecordNumber = new wxRadioButton(this->gpParent, RD_RECORD_NUMBER_ID,
                                               wxT("Record Number"),wxDefaultPosition,wxDefaultSize, wxRB_GROUP);

    this->rdFileSize = new wxRadioButton(this->gpParent, RD_FILE_SIZE_ID,
                                         wxT("File Size"));
    this->stFileSizeUnit = new wxStaticText(this->gpParent, -1,
                                            wxT("MB"));
    this->scFileSize = new wxSpinCtrlDouble(this->gpParent, SC_FILE_SIZE_ID, wxString(""),
                                            wxPoint(-1, -1), wxSize(-1, -1), wxSP_ARROW_KEYS,
                                            0.1, DBL_MAX, 1);*/


     /*
      * TODO:: skip for coming version
      * this->rdRecordNumber->SetValue(true);*/
      this->gpParent->Bind(wxEVT_SPINCTRL, &OutputAmountContainer::onChangeOutputAmountType,
               this); //TODO:: handler 'this' need to change if refactoring
   /*
    * TODO:: skip for coming version
    * this->gpParent->Bind(wxEVT_RADIOBUTTON, &OutputAmountContainer::onChangeOutputAmountType,
                         this);*/

    //connect Record Size's widgets to horrizontal BoxSizer
    this->bsRecordSizeTitle->Add(this->stRecordSizeTitle, 0);
    /*
     * TODO:: skip for coming version
     * this->bsRecordSize->Add(this->rdRecordNumber, 0, wxRIGHT, 20);*/
    this->bsRecordSize->Add(this->scRecordNumber, 0); //In case of cus, getBoxSizer should be called
    this->bsRecordSize->Add(this->stRecordNumberUnit, 0, wxRIGHT, 100);

    /**
     * TODO: skip for coming version
    this->bsRecordSize->Add(this->rdFileSize, 0, wxRIGHT, 20);
    this->bsRecordSize->Add(this->scFileSize, 0);
    this->bsRecordSize->Add(this->stFileSizeUnit, 0);*/


    //---
    this->bsMain->Add(this->bsRecordSizeTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsRecordSize, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(sl1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
}


void OutputAmountContainer::onChangeOutputAmountType(wxCommandEvent &event) {
    int id = event.GetId();



     if (id == rollbear::any_of{SC_RECORD_NUMBER_ID,RD_RECORD_NUMBER_ID })
    {
     //   this->scFileSize->SetValue(1);
        this->outputRecordAmount= this->scRecordNumber->GetValue();
        this->isRecordAmount=true;

        std::cout<< "Record Amount :"<<this->outputRecordAmount << "\n";
    }
    /*
     TODO : skip for coming version
     if (id == rollbear::any_of{ SC_FILE_SIZE_ID ,RD_FILE_SIZE_ID })
    {
        this->scRecordNumber->SetValue(100);
        this->outputFileSize=this->scFileSize->GetValue();
        this->isRecordAmount=false;

        std::cout<< "Ouput size:"<<this->outputFileSize <<"\n";
    }
*/


    event.Skip();
}
