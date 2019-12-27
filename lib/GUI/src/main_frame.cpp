
#include <wx/wx.h>
#include <gui/main_frame.h>
#include <gui/data_generation/generate_page.h>
#include <gui/type_extension/extend_page.h>
#include <gui/id.h>
#include <wx/aboutdlg.h>


MainFrame::MainFrame():
    wxFrame(nullptr, wxID_ANY
            , wxString("XMwayLoon")
            , wxDefaultPosition, wxSize(770, 630),
            wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)
            )
{
    this->mbMain = new wxMenuBar();
    this->mMain = new  wxMenu();

    this->mMain->Append(MENU_ITEM_CREDIT_ID, _("Credit"));


    this->mMain->Append(wxID_ABOUT, _("About"));
    this->mMain->Append(wxID_HELP, _("Help"));
    this->mMain->Append(wxID_PREFERENCES, _("Preferences"));
    this->mMain->Append(wxID_EXIT, _("Exit"));

    this->mbMain->Append(this->mMain, _("File"));

    SetMenuBar(this->mbMain);


    nbMain = new wxNotebook(this,-1);
    this->pnGenerate = new GeneratePage(nbMain);
    this->pnExtend = new ExtendPage(nbMain);

    nbMain->AddPage(this->pnGenerate, "Data Generation");
    nbMain->AddPage(this->pnExtend,"Type Extension");
  //  Bind(wxEVT_NOTEBOOK_PAGE_CHANGED,&MainFrame::onTabChanged,this);
    this->SetAutoLayout(false);
    Centre();
}

void MainFrame::onTabChanged(wxCommandEvent &event)
{
    wxWindow* currentPage= this->nbMain->GetCurrentPage();
    int tabId= this->nbMain->FindPage(currentPage);

    if(tabId==0) this->SetSize( wxSize(770,630) );
    if(tabId==1) this->SetSize( wxSize(600,540) );

    event.Skip();

}

void MainFrame::onAbout(wxCommandEvent &event) {

    wxAboutDialogInfo info;

    info.SetName(L"XMwayLoon");
    info.SetVersion(L"1.0.0");
    info.SetDescription(L"XMwayLoon is the open project designed for Burmese data randomization.");
    info.SetCopyright(L"Copyright (c) 2020 Xlotgative");
    info.SetWebSite(L"https://github.com/KaungZawHtet/XMwayLoon");

    wxArrayString developers;
    developers.Add(L"Kaung Zaw Htet");
    info.SetDevelopers(developers);

    wxArrayString docWriters;
    docWriters.Add(L"Kaung Zaw Htet");
    info.SetDocWriters(docWriters);

    info.SetLicence(
            L"Permission is hereby granted, free of charge, to any person obtaining a "
            L"copy of this software and associated documentation files (the \"Software\"), "
            L"to deal in the Software without restriction, including without limitation "
            L"the rights to use, copy, modify, merge, publish, distribute, sublicense, "
            L"and / or sell copies of the Software, and to permit persons to whom the "
            L"Software is furnished to do so, subject to the following conditions :\n"
            L"\n"
            L"The above copyright notice and this permission notice shall be included in "
            L"all copies or substantial portions of the Software.\n"
            L"\n"
            L"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
            L"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
            L"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL "
            L"THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
            L"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING "
            L"FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS "
            L"IN THE SOFTWARE.");

    wxAboutBox(info);

    event.Skip();
}

void MainFrame::onCredit(wxCommandEvent &event) {

    wxAboutDialogInfo info;

    info.SetName(L"Credit");
    info.SetDescription
            (L"We want to say thank you to the open source community.");

    // info.SetCopyright(L"From Xlotgative with love.");

    wxArrayString developers;
    developers.Add(L"Xavier Leclercq");
    info.SetDevelopers(developers);

    wxAboutBox(info);
    event.Skip();

}

void MainFrame::onPreference(wxCommandEvent &event) {

this->dPreferenceDialog = new PreferenceDialog("Preference");
this->dPreferenceDialog->Show();
    event.Skip();
}


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(MENU_ITEM_CREDIT_ID, MainFrame::onCredit)
                EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
                EVT_MENU(wxID_PREFERENCES, MainFrame::onPreference)
wxEND_EVENT_TABLE()