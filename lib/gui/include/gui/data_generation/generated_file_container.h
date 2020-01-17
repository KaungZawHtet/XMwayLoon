//
// Created by Kaung Zaw Htet on 2019-12-16.
//

#ifndef XMWAYLOON_GENERATED_FILE_CONTAINER_H
#define XMWAYLOON_GENERATED_FILE_CONTAINER_H
#include <wx/statline.h>
#include <wx/wx.h>
class GeneratePage;
class GeneratedFileContainer : public wxControl
{
public:
    GeneratedFileContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain);

    GeneratePage *gpParent;
    wxBoxSizer *bsMain;

    wxBoxSizer *bsGeneratedFileTitle;
    wxBoxSizer *bsGeneratedFile;

    wxTextCtrl *tcGeneratedFile;
    wxButton *btnGeneratedFile;

    wxStaticText *stGeneratedFileTitle;
    wxStaticText *stError;

    wxStaticLine *st5;

    void onTarget(wxCommandEvent &event);





};
#endif //XMWAYLOON_GENERATED_FILE_CONTAINER_H
