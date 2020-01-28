
#include <wx/wx.h>
#include <gui/type_extension/extend_page.h>
#include <wx/spinctrl.h>

ExtendPage::ExtendPage(wxWindow *wParent)
    : wxPanel(wParent, -1)
{


    this->bsMain = new wxBoxSizer(wxVERTICAL);
    cbExtensionBook= new wxChoicebook(this,-1);
    this->ctExtensionByFile_Container= new ExtensionByFile_Container(cbExtensionBook);
    this->ctExtensionManually_Container= new ExtensionManually_Container(cbExtensionBook);


    this->cbExtensionBook->AddPage(this->ctExtensionManually_Container,"Extend Manually");
    this->cbExtensionBook->AddPage(this->ctExtensionByFile_Container,"Extend By JSON");



    this->bsMain->Add(this->cbExtensionBook,0,wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);


    this->SetSizer(this->bsMain);





}
