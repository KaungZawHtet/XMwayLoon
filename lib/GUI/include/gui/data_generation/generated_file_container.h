//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#ifndef XMWAYLOON_GENERATED_FILE_CONTAINER_H
#define XMWAYLOON_GENERATED_FILE_CONTAINER_H
#include <wx/statline.h>
#include <wx/wx.h>
class GenerateFileContainer : public wxControl
{
public:
    GenerateFileContainer(wxWindow *tmp_wParent, wxBoxSizer *tmp_bsMain);

    wxWindow *wParent;
    wxBoxSizer *bsMain;

    wxBoxSizer *bsGenerateFileTitle;
    wxBoxSizer *bsGenerateFile;

    wxTextCtrl *tcGenerateFile;
    wxButton *btnGenerateFile;

    wxStaticText *stGenerateFileTitle;

    wxStaticLine *st5;

    void onTarget(wxCommandEvent &event);





};
#endif //XMWAYLOON_GENERATED_FILE_CONTAINER_H
