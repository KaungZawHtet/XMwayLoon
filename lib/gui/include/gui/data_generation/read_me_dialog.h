//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#ifndef XMWAYLOON_READ_ME_DIALOG_DG_H
#define XMWAYLOON_READ_ME_DIALOG_DG_H

#include <gui/data_generation/read_me_panel.h>
#include <wx/wx.h>
class DataGenerationReadMeDialog : wxDialog
{
public:

    DataGenerationReadMePanel *pnlReadMe;

    DataGenerationReadMeDialog(const wxString & title);
};

#endif //XMWAYLOON_READ_ME_DIALOG_DG_H
