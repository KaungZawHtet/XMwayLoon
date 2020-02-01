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
1. This is how your JSON file should be structured for extension.
2. You can extend multi types at the same time. In eg:, there are 3 types to be extended.
3. Items can be either unicode or zawgyi encoded. XMwayLoon can automatically detect.
   In this example, one is unicode, one is zawgyi and the last, mixing.
)";

    static inline constexpr std::string_view strJson= R"({
  "1": {
    "items": [
      "ရှမ်းခေါက်ဆွဲ",
      "တိုဖူးနွေး",
      "ဝက်ခေါက်"
    ],
    "name": "တိုင်းရင်းသားအစားအစာ"
  },

  "2": {
    "items": [
      "ရန္ကုန္တိုင္း",
      "ပဲခူးတိုင္း",
      "မေကြးတိုင္း"
    ],
    "name": "တိုင်းဒေသကြီး"
  },

  "3": {
    "items": [
      "မင်္ဂလာပါ",
     " ေနေကာင္းလား",
      "ကျန်းမာရဲ့လား"
    ],
    "name": "နှုတ်ဆက်စကား"
  }
})";

    wxBoxSizer *bsMain;
    wxTextCtrl *tcExample;
    wxStaticText *stExplanation;


    

    ReadMePanel(wxWindow *tmp_wParent);


};

#endif //XMWAYLOON_READ_ME_DIALOG_PANEL_H
