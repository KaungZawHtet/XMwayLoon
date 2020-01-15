//
// Created by Kaung Zaw Htet on 2019-12-14.
//

#ifndef XMWAYLOON_OUTPUT_FORMAT_CONTAINER_H
#define XMWAYLOON_OUTPUT_FORMAT_CONTAINER_H

#include <model/generate_info.h>
#include <wx/wx.h>
#include <wx/statline.h>
class OutputFormatContainer : public wxControl
{
public:
    OutputFormatContainer(wxWindow *tmp_wParent,wxBoxSizer *tmp_bsMain);

    wxStaticText *stFormatTypeTitle;
    wxBoxSizer *bsFormatTypeTitle;
    wxBoxSizer *bsFormatType;
    wxCheckBox *cbCSV;
    wxCheckBox *cbJSON;
    wxCheckBox *cbXML;
    wxCheckBox *cbHTML;

    wxWindow *wParent;
    wxBoxSizer *bsMain;
    wxStaticLine *sl2;

    OutputFormat objOutputFormat;

    void onChecked ( wxCommandEvent &event);

private:


};

#endif //XMWAYLOON_OUTPUT_FORMAT_CONTAINER_H
