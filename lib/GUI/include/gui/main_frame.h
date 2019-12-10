#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <gui/gen_panel.h>
#include <gui/extend_panel.h>




class MainFrame : public wxFrame
{

private:


public:
    wxNotebook* nbMain ;
    GenPanel *pnGen;
    ExtendPanel *pnExtend;

    void onTabChanged(wxCommandEvent &event );

    MainFrame();
    
};

#endif // MAIN_FRAME_H
