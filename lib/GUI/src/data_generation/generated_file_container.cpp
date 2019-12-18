//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#include <wx/wx.h>
#include <gui/data_generation/generated_file_container.h>
#include <gui/id.h>
GenerateFileContainer::GenerateFileContainer
(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain)
: wxControl(tmp_parent,-1)
{
    this->parent= tmp_parent;
    this->bsMain=tmp_bsMain;


    this->st5= new wxStaticLine(this->parent, wxID_ANY, wxPoint(-1, -1),
                                wxSize(300, 1));
    this->bsGenerateFileTitle= new wxBoxSizer(wxHORIZONTAL);
    this->bsGenerateFile= new wxBoxSizer(wxHORIZONTAL);
    this->stGenerateFileTitle= new wxStaticText(this->parent,-1,wxT("Target File : "));
    this->btnGenerateFile = new wxButton(this->parent,BTN_TARGET_ID,wxT("Target"));
    this->tcGenerateFile=new wxTextCtrl(this->parent,TC_TARGET_ID);
    this->tcGenerateFile->SetEditable(false);

    this->parent->Bind(wxEVT_BUTTON,&GenerateFileContainer::onTarget,this,BTN_TARGET_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsGenerateFileTitle->Add(this->stGenerateFileTitle);
    this->bsGenerateFile->Add(this->tcGenerateFile, 2, wxRIGHT, 8);
    this->bsGenerateFile->Add(this->btnGenerateFile, 0);

    this->bsMain->Add(this->bsGenerateFileTitle, 0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(this->bsGenerateFile, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->st5,0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(-1,0,wxTOP ,5);

}

void GenerateFileContainer::onTarget
(wxCommandEvent &event) {


wxFileDialog saveFileDialog(this, _("Generated file's location: "), "", "",
                           "", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
  wxString file= saveFileDialog.GetPath();
  this->tcGenerateFile->SetValue(file);


    event.Skip();
}