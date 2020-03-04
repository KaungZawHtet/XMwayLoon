//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#ifndef XMWAYLOON_READ_ME_DIALOG_PANEL_DG_H
#define XMWAYLOON_READ_ME_DIALOG_PANEL_DG_H

#include <wx/wx.h>
class DataGenerationReadMePanel : public wxPanel
{
public:
    static inline constexpr std::string_view strExplanation =
            R"(
Instead of whole boring story, here are short notable facts:
1. There are characteristics for every type and mentioned under type specific option columns.
2. Some types' characteristics are worth mentioning below:
)";

    static inline constexpr std::string_view strJson= R"(
Boolean:
    -No notable facts to be mentioned.

Date:
    -Type Specific Option 1 :
            1. You can edit date format there.
            2. %d means day, %b means month, %y means year.
            3. Eg.1 : %d-%b-%y generates like "၂၃-မေ-၂၀".
            4. For complete year, %Y can be used.
            5. Eg.2 :%d/%b/%Y generates like "၂၃/မေ/၂၀၂၀".
            6. Eg.3 :%Y_%b_%d generates like "၂၀၁၆_ဇူလိုင်_၁၂".

Name:
    -No notable facts to be mentioned.

NRC:
    -No notable facts to be mentioned.

Number:
    -Type Specific Option 3 : It's minimum number
    -Type Specific Option 4 : It's maximum number.

Pangram:
    -No notable facts to be mentioned.

Ph Number:
    -No notable facts to be mentioned.

)";

    wxBoxSizer *bsMain;
    wxTextCtrl *tcExample;
    wxStaticText *stExplanation;


    

    DataGenerationReadMePanel(wxWindow *tmp_wParent);


};

#endif //XMWAYLOON_READ_ME_DIALOG_PANEL_DG_H
