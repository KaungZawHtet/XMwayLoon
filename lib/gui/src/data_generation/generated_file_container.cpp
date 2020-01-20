//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#include <wx/wx.h>
#include <gui/data_generation/generated_file_container.h>
#include <gui/id.h>
#include <gui/data_generation/generate_page.h>
GeneratedFileContainer::GeneratedFileContainer
(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain)
: wxControl(reinterpret_cast<wxWindow *>(tmp_gpParent), -1)
{
    this->gpParent= tmp_gpParent;
    this->bsMain=tmp_bsMain;


    this->st5= new wxStaticLine(this->gpParent, wxID_ANY, wxPoint(-1, -1),
                                wxSize(300, 1));
    this->bsGeneratedFileTitle= new wxBoxSizer(wxHORIZONTAL);
    this->bsGeneratedFile= new wxBoxSizer(wxHORIZONTAL);
    this->stGeneratedFileTitle= new wxStaticText(this->gpParent, -1, wxT("Target File : "));
    this->stGeneratedFileTitle->SetFont(this->gpParent->font->Bold());
    this->btnGeneratedFile = new wxButton(this->gpParent, BTN_TARGET_ID, wxT("Target"));
    this->tcGeneratedFile=new wxTextCtrl(this->gpParent, TC_TARGET_ID);
    this->tcGeneratedFile->SetEditable(false);
    this->stError= new wxStaticText(this->gpParent,-1,wxT(""));


    this->gpParent->Bind(wxEVT_BUTTON, &GeneratedFileContainer::onTarget, this, BTN_TARGET_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsGeneratedFileTitle->Add(this->stGeneratedFileTitle, 0, wxRIGHT, 8);
    this->bsGeneratedFileTitle->Add(this->stError);
    this->bsGeneratedFile->Add(this->tcGeneratedFile, 2, wxRIGHT, 8);
    this->bsGeneratedFile->Add(this->btnGeneratedFile, 0);

    this->bsMain->Add(this->bsGeneratedFileTitle, 0, wxLEFT | wxTOP, 9);
    this->bsMain->Add(this->bsGeneratedFile, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->st5,0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(-1,0,wxTOP ,5);

}

void GeneratedFileContainer::onTarget
(wxCommandEvent &event) {


wxFileDialog saveFileDialog(this, _("Generated file's location: "), "", "",
                           "", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
  wxString file= saveFileDialog.GetPath();
  this->tcGeneratedFile->SetValue(file);


    event.Skip();
}