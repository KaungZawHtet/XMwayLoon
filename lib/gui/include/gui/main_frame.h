#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>
#include <wx/notebook.h>
#include <gui/data_generation/generate_page.h>
#include <gui/type_extension/extend_page.h>
#include <gui/preference_dialog.h>

#include <memory>

class MainFrame : public wxFrame
{

private:

wxDECLARE_EVENT_TABLE();
public:
    wxNotebook* nbMain ;
    GeneratePage *pnGenerate;
    ExtendPage *pnExtend;
    wxMenuBar *mbMain;
    wxMenu *mMain;



    PreferenceDialog *dPreferenceDialog;



    void onTabChanged(wxCommandEvent &event );
    void onAbout(wxCommandEvent &event);
    void onCredit(wxCommandEvent &event);
    void onPreference(wxCommandEvent &event);
 //   void onRestart(wxCommandEvent &event);
    void onResetCache(wxCommandEvent &event);



    MainFrame();
    
};

#endif // MAIN_FRAME_H
