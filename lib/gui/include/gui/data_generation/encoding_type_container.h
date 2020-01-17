//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_ENCODING_TYPE_CONTAINER_H
#define XMWAYLOON_ENCODING_TYPE_CONTAINER_H


#include <wx/wx.h>
#include <wx/statline.h>
#include <model/generate_info.h>
class GeneratePage;


class EncodingTypeContainer : public wxControl
{

public:
    EncodingTypeContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain);


    GeneratePage *gpParent;



    wxBoxSizer *bsMain;
    wxStaticText *stEncodeTypeTitle;
    wxBoxSizer *bsEncodeTypeTitle;
    wxBoxSizer *bsEncodeType;
    wxRadioButton *rdUnicode;
    wxRadioButton *rdZawgyi;
    wxRadioButton *rdRandom;
    wxRadioButton *rdCustom;
    wxStaticLine *sl3;

    EncodingType targetEncodingType;


    void onTargetEncode(wxCommandEvent& event);


};

#endif //XMWAYLOON_ENCODING_TYPE_CONTAINER_H
