//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#ifndef XMWAYLOON_READ_ME_DIALOG_PANEL_H
#define XMWAYLOON_READ_ME_DIALOG_PANEL_H

#include <wx/wx.h>
class ReadMePanel : public wxPanel
{
public:
    static inline constexpr std::string_view strExplanation =
            R"(
Instead of whole boring story, here are short notable facts:
1. There are characteristics for every type and mentioned under type specific option columns.
2. Some types' characteristics are worth mentioning below:
)";

    static inline constexpr std::string_view strJson= R"({

})";

    wxBoxSizer *bsMain;
    wxTextCtrl *tcExample;
    wxStaticText *stExplanation;


    

    ReadMePanel(wxWindow *tmp_wParent);


};

#endif //XMWAYLOON_READ_ME_DIALOG_PANEL_H
