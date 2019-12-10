
#include <wx/wx.h>
#include <gui/main_frame.h>
#include <gui/gen_panel.h>
#include <gui/extend_panel.h>

MainFrame::MainFrame():
    wxFrame(nullptr, wxID_ANY, wxString("XMwayLoon"), wxDefaultPosition, wxSize(770, 540))
{
    nbMain = new wxNotebook(this,-1);
    this->pnGen = new GenPanel(nbMain);
    this->pnExtend = new ExtendPanel(nbMain);

    nbMain->AddPage(this->pnGen,"Data Generation");
    nbMain->AddPage(this->pnExtend,"Type Extension");
    Bind(wxEVT_NOTEBOOK_PAGE_CHANGED,&MainFrame::onTabChanged,this);
    Centre();
}

void MainFrame::onTabChanged(wxCommandEvent &event)
{
    wxWindow* currentPage= this->nbMain->GetCurrentPage();
    int tabId= this->nbMain->FindPage(currentPage);

    if(tabId==0) this->SetSize( wxSize(770,540) );
    if(tabId==1) this->SetSize( wxSize(600,540) );


}
