//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_ENCODING_TYPE_CONTAINER_H
#define XMWAYLOON_ENCODING_TYPE_CONTAINER_H

#include <wx/wx.h>
#include <wx/statline.h>
class EncodingTypeContainer : public wxControl
{

public:
    EncodingTypeContainer(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain);


    wxWindow *parent;
    wxBoxSizer *bsMain;
    wxStaticText *stEncodeTypeTitle;
    wxBoxSizer *bsEncodeTypeTitle;
    wxBoxSizer *bsEncodeType;
    wxRadioButton *rdUnicode;
    wxRadioButton *rdZawgyi;
    wxRadioButton *rdRandom;
    wxRadioButton *rdCustom;
    wxStaticLine *sl3;

    void onTargetUnicode(wxCommandEvent& event);
    void onTargetZawgyi(wxCommandEvent& event);
    void onTargetRandom(wxCommandEvent& event);
    void onTargetCustom(wxCommandEvent& event);


};

#endif //XMWAYLOON_ENCODING_TYPE_CONTAINER_H
