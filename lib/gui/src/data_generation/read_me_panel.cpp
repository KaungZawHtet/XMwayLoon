//
// Created by Kaung Zaw Htet on 2020-01-29.
//

#include <gui/data_generation/read_me_panel.h>

DataGenerationReadMePanel::DataGenerationReadMePanel(wxWindow *tmp_wParent) :
wxPanel(tmp_wParent,-1)
{

    this->bsMain =new wxBoxSizer(wxVERTICAL);
    this->stIntro = new wxStaticText(this , -1, this->strIntro.data());

#ifdef __APPLE__

    this->tcExample = new wxTextCtrl(this,-1,
                                  this->strDetail.data(),wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);
#elif __linux__
    
this->tcExample = new wxTextCtrl(this,-1,
L"Boolean:\n"
    L"\t-No notable facts to be mentioned.\n\n"
L"Date:\n"
    L"\t-Type Specific Option 1 :\n"
            L"\t\t1. You can edit date format there.\n"
            L"\t\t2. %d means day, %b means month, %y means year.\n"
            L"\t\t3. Eg.1 : %d-%b-%y generates like \"၂၃-မေ-၂၀\".\n"
            L"\t\t4. For complete year, %Y can be used.\n"
            L"\t\t5. Eg.2 : %d/%b/%Y generates like \"၂၃/မေ/၂၀၂၀\".\n"
            L"\t\t6. Eg.3 : %Y_%b_%d generates like \"၂၀၁၆_ဇူလိုင်_၁၂\".\n\n"
L"Name:\n"
    L"\t-No notable facts to be mentioned.\n\n"
L"NRC:\n"
    L"\t-No notable facts to be mentioned.\n\n"
L"Number:\n"
    L"\t-Type Specific Option 3 : It's minimum number as digit.\n"
    L"\t-Type Specific Option 4 : It's maximum number as digit.\n\n"
L"Pangram:\n"
    L"\t-No notable facts to be mentioned.\n\n"
L"Ph Number:\n"
    L"\t-No notable facts to be mentioned.\n"
    ,wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);

#else

    this->tcExample = new wxTextCtrl(this,-1,
                                  this->strDetail.data(),wxDefaultPosition,wxSize(-1,600),wxTE_MULTILINE);

#endif





    this->tcExample->SetEditable(false);

    this->bsMain->Add(this->stIntro,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);
    this->bsMain->Add(this->tcExample,0,wxLEFT|wxRIGHT |wxEXPAND|wxTOP, 10);

    this->SetSizer(this->bsMain);


}