//
// Created by Kaung Zaw Htet on 2020-01-17.
//
#include <gui/type_extension/extension_by_file_container.h>
#include <gui/id.h>
#include <wx/dialog.h>
#include <gui/type_extension/extend_page.h>
ExtensionByFile_Container::ExtensionByFile_Container
(ExtendPage *tmp_wParent, wxBoxSizer *tmp_bsMain)
: wxControl(tmp_wParent,-1)
{

    this->wParent= tmp_wParent;
    this->bsMain=tmp_bsMain;
    //allocate Type Addition group
    this->bsTitle = new wxBoxSizer(wxHORIZONTAL);
    this->bsExtendBtn = new wxBoxSizer(wxHORIZONTAL);
    this->bsFileExtender = new wxBoxSizer(wxHORIZONTAL);
    this->sl0 = new wxStaticLine(this->wParent, wxID_ANY, wxPoint(-1, -1),
                                 wxSize(300, 1));

    this->stTitle = new wxStaticText(this->wParent, -1,
                                            wxT("Extend Type by json file : "));


    this->stTitle->SetFont(this->wParent->font->Bold());
    this->btnBrowse = new wxButton(this->wParent, BTN_BROWSE_BY_FILE_ID, wxT("Browse"));
    this->btnExtend = new wxButton(this->wParent, BTN_EXTEND_BY_FILE_ID, wxT("Extend"));

    this->tcPath = new wxTextCtrl(this->wParent, TC_PATH_BY_FILE_ID,wxT(""),
                                     wxPoint(-1,-1),wxSize(-1,-1));
    this->tcPath->SetEditable(false);

    //this->Connect(BTN_ADD_TYPE_ID,wxEVT_BUTTON,wxCommandEventHandler(TypeGenerationContainer::onAddType));
    this->wParent->Bind(wxEVT_BUTTON, &ExtensionByFile_Container::onBrowse, this, BTN_BROWSE_BY_FILE_ID);
    this->wParent->Bind(wxEVT_BUTTON, &ExtensionByFile_Container::onExtend, this, BTN_EXTEND_BY_FILE_ID);

    //connect Type Addition's widgets to horrizontal BoxSizer
    this->bsTitle->Add(this->stTitle);
    this->bsFileExtender->Add(this->tcPath, 2, wxRIGHT, 8);
    this->bsFileExtender->Add(this->btnBrowse, 0);
    this->bsExtendBtn->Add(this->btnExtend, 0);
    //---
    this->bsMain->Add(this->bsTitle, 0, wxLEFT | wxTOP, 9); //title should be one less pixel
    this->bsMain->Add(this->bsFileExtender, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
    this->bsMain->Add(this->bsExtendBtn,0,  wxALIGN_RIGHT | wxRIGHT | wxTOP, 10);


    this->bsMain->Add(sl0, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

}

void ExtensionByFile_Container::onBrowse(wxCommandEvent &event) {
    
    wxFileDialog loadFileDialog(this, _("Choose your json file to extend : ")
            , "", "","", wxFD_FILE_MUST_EXIST);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
   
    this->tcPath->SetValue(loadFileDialog.GetPath());


    event.Skip();
}

void ExtensionByFile_Container::onExtend(wxCommandEvent &event) {


}
