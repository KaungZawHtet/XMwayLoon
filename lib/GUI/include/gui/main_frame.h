#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <gui/generate_page.h>
#include <gui/extend_page.h>




class MainFrame : public wxFrame
{

private:


public:
    wxNotebook* nbMain ;
    GeneratePage *pnGenerate;
    ExtendPage *pnExtend;

    void onTabChanged(wxCommandEvent &event );

    MainFrame();
    
};

#endif // MAIN_FRAME_H