//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#include <gui/type_extension/read_me_panel.h>

ReadMePanel::ReadMePanel(wxWindow *tmp_wParent) :
wxPanel(tmp_wParent,-1)
{

    this->bsMain =new wxBoxSizer(wxVERTICAL);
    this->stExplanation = new wxStaticText(this , -1, this->strExplanation.data());




#ifdef __APPLE__

    this->tcExample = new wxTextCtrl(this,-1,this->strJson.data()
            ,wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);
#elif __linux__

    this->tcExample = new wxTextCtrl(this,-1,L"\n{\n"
                                             L"\t\"1\": {\n"
                                             L"\t\t\"items\": [ \"ရှမ်းခေါက်ဆွဲ\", \"တိုဖူးနွေး\", \"ဝက်ခေါက်\" ],\n"
                                             L"\t\t\"name\": \"တိုင်းရင်းသားအစားအစာ\"\n"
                                             L"\t},\n"
                                             L"\t\"2\": {\n"
                                             L"\t\t\"items\": [ \"ရန္ကုန္တိုင္း\", \"ပဲခူးတိုင္း\", \"မေကြးတိုင္း\" ],\n"
                                             L"\t\t\"name\": \"တိုင်းဒေသကြီး\"\n"
                                             L"\t},\n"
                                             L"\t\"3\": {\n"
                                             L"\t\t\"items\": [ \"မင်္ဂလာပါ\", \" ေနေကာင္းလား\", \"ကျန်းမာရဲ့လား\" ],\n"
                                             L"\t\t\"name\": \"နှုတ်ဆက်စကား\"\n"
                                             L"\t}\n"
                                             L"}\n"
            ,wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);

#else

        this->tcExample = new wxTextCtrl(this,-1,this->strJson.data()
    ,wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);
#endif






    this->tcExample->SetEditable(false);

    this->bsMain->Add(this->stExplanation,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);
    this->bsMain->Add(this->tcExample,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);

    this->SetSizer(this->bsMain);


}