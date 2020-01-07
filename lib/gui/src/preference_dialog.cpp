//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#include <wx/wx.h>
#include <gui/preference_dialog.h>


PreferenceDialog::PreferenceDialog(const wxString &title)
        : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230))
{

    //TODO:: Problems in preference file directory;
    this->pnlPreferennce = new wxPanel(this, -1);
    this->bsMain = new wxBoxSizer(wxVERTICAL);
   // this->bsDirTitle=new wxBoxSizer(wxHORIZONTAL);


    this->sbDir = new wxStaticBox(this->pnlPreferennce , -1, wxT("Data Directory"),
                                  wxPoint(5, 5), wxSize(240, 150));
    this->sbsMain = new wxStaticBoxSizer(this->sbDir, wxVERTICAL);



    this->bsDir=new wxBoxSizer(wxHORIZONTAL);
    this->tcDir = new wxTextCtrl(this->pnlPreferennce, -1);
    this->btnDir = new wxButton(this->pnlPreferennce, -1);

    this->bsDir->Add(this->tcDir, 2, wxRIGHT, 8);
    this->bsDir->Add(this->btnDir);
    this->sbsMain->Add(this->bsDir);
    this->bsMain->Add(this->bsDir);

    SetSizer(this->bsDir);

    Centre();
    ShowModal();
    Destroy();

}