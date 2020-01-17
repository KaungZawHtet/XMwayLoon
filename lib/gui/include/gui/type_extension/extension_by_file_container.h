//
// Created by Kaung Zaw Htet on 2020-01-17.
//

#ifndef XMWAYLOON_EXTENSION_BY_FILE_CONTAINER_H
#define XMWAYLOON_EXTENSION_BY_FILE_CONTAINER_H

#include <wx/statline.h>
#include <wx/wx.h>

class ExtendPage;
class ExtensionByFile_Container  : public wxControl {
    ExtendPage *wParent;


    wxStaticText *stTitle;
    wxButton *btnBrowse;
    wxButton *btnExtend;
    wxTextCtrl *tcPath;
    wxBoxSizer *bsFileExtender;
    wxBoxSizer *bsTitle;
    wxBoxSizer *bsExtendBtn;



    wxBoxSizer *bsMain;
    wxStaticLine *sl0;


    void onBrowse(wxCommandEvent& event);
    void onExtend(wxCommandEvent& event);

public:
    ExtensionByFile_Container(ExtendPage *tmp_wParent, wxBoxSizer *tmp_bsMain);
};

#endif //XMWAYLOON_EXTENSION_BY_FILE_CONTAINER_H
