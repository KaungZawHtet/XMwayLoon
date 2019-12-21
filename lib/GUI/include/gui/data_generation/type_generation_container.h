//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#ifndef XMWAYLOON_TYPE_GENERATION_CONTAINER_H
#define XMWAYLOON_TYPE_GENERATION_CONTAINER_H

#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>
#include <logic/type_loader.h>
#include <wx/statline.h>
class TypeGenerationContainer : public wxPanel
{
public:


    wxWindow *parent;

    wxStaticText *stAddTypeTitle;
    wxButton *btnAddType;
    wxButton *btnRemoveType;
    wxComboBox *cbAddType;
    wxBoxSizer *bsAddType;
    wxBoxSizer *bsAddTypeTitle;


    wxBoxSizer *bsTypeGrid;
    TypeGrid *gTypeGrid;

    wxBoxSizer *bsMain;
    wxStaticLine *sl0;

    TypeLoader objTypeLoader;


    TypeGenerationContainer(wxWindow *tmp_parent, wxBoxSizer *tmp_bsMain);
    void onAddType(wxCommandEvent& event);
    void onRemoveType(wxCommandEvent& event);



private:
//DECLARE_EVENT_TABLE()

};

#endif //XMWAYLOON_TYPE_GENERATION_CONTAINER_H
