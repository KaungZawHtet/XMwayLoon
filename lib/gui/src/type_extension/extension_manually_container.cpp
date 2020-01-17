//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#include <gui/type_extension/extension_manually_container.h>


ExtensionManually_Container::ExtensionManually_Container
(wxWindow *tmp_wParent, wxBoxSizer *tmp_bsMain)
: wxControl(tmp_wParent,-1)
{

    this->wParent= tmp_wParent;
    this->bsMain=tmp_bsMain;

    stTitle=new wxStaticText(this->wParent, -1,
                             wxT("Extend Type Manually : "));
    stRecord=new wxStaticText(this->wParent, -1,
                              wxT("Record :"));
    stTypeName=new wxStaticText(this->wParent, -1,
                             wxT("Type Name : "));


}

void ExtensionManually_Container::onExtend(wxCommandEvent &event) {



}
