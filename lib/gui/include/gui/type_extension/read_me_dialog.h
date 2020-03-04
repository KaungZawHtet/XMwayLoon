//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#ifndef XMWAYLOON_READ_ME_DIALOG_TE_H
#define XMWAYLOON_READ_ME_DIALOG_TE_H

#include <gui/type_extension/read_me_panel.h>
#include <wx/wx.h>
class ReadMeDialog : wxDialog
{
public:

    ReadMePanel *pnlReadMe;

    ReadMeDialog(const wxString & title);
};

#endif //XMWAYLOON_READ_ME_DIALOG_TE_H
