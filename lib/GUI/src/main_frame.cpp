
#include <wx/wx.h>
#include <gui/main_frame.h>
#include <gui/generate_page.h>
#include <gui/extend_page.h>

MainFrame::MainFrame():
    wxFrame(nullptr, wxID_ANY
            , wxString("XMwayLoon")
            , wxDefaultPosition, wxSize(770, 540),
            wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)
            )
{
    nbMain = new wxNotebook(this,-1);
    this->pnGenerate = new GeneratePage(nbMain);
    this->pnExtend = new ExtendPage(nbMain);

    nbMain->AddPage(this->pnGenerate, "Data Generation");
    nbMain->AddPage(this->pnExtend,"Type Extension");
    Bind(wxEVT_NOTEBOOK_PAGE_CHANGED,&MainFrame::onTabChanged,this);
    this->SetAutoLayout(false);
    Centre();
}

void MainFrame::onTabChanged(wxCommandEvent &event)
{
    wxWindow* currentPage= this->nbMain->GetCurrentPage();
    int tabId= this->nbMain->FindPage(currentPage);

    if(tabId==0) this->SetSize( wxSize(770,540) );
    if(tabId==1) this->SetSize( wxSize(600,540) );


}
