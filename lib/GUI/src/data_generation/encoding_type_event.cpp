//
// Created by Kaung Zaw Htet on 2019-12-23.
//
#include <wx/wx.h>
#include <gui/data_generation/encoding_type_container.h>
#include <gui/id.h>


void EncodingTypeContainer::onTargetEncode(wxCommandEvent &event) {

    int id = event.GetId();
    if (id == RD_UNICODE_ID)
    { }
    if (id == RD_ZAWGYI_ID)
    { }
    if (id == RD_RANDOM_ID)
    { }
    if (id == RD_CUSTOM_ID)
    { }
    event.Skip();

}