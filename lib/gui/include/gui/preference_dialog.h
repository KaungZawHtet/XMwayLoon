//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#ifndef XMWAYLOON_PREFERENCE_DIALOG_H
#define XMWAYLOON_PREFERENCE_DIALOG_H

#include <wx/wx.h>

class PreferenceDialog: public wxDialog {



public:
    PreferenceDialog(const wxString& title);
    wxPanel *pnlPreferennce;
    wxBoxSizer *bsMain;
    wxBoxSizer *bsDirTitle;
    wxBoxSizer *bsDir;
    wxStaticBoxSizer *sbsMain;

    wxStaticBox *sbDir;
    wxTextCtrl *tcDir;
    wxButton *btnDir;




};

#endif //XMWAYLOON_PREFERENCE_DIALOG_H
