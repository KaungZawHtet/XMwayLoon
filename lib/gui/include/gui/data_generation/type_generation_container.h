//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#ifndef XMWAYLOON_TYPE_GENERATION_CONTAINER_H
#define XMWAYLOON_TYPE_GENERATION_CONTAINER_H

#include <wx/wx.h>
#include <gui/data_generation/type_grid.h>
#include <gui/type_loader.h>
#include <wx/statline.h>
class GeneratePage;
//this class depend on TypeLoader
class TypeGenerationContainer
{
public:


    GeneratePage *gpParent;

    wxStaticText *stAddTypeTitle;
    wxButton *btnAddType;
    wxButton *btnRemoveType;
    wxButton *btnReadMe;
    wxComboBox *cbAddType;
    wxBoxSizer *bsAddType;
    wxBoxSizer *bsAddTypeTitle;


    wxBoxSizer *bsTypeGrid;
    TypeGrid *gTypeGrid;

    wxBoxSizer *bsMain;
    wxStaticLine *sl0;
    wxStaticText *stError;


    TypeLoader objTypeLoader;



    TypeGenerationContainer(GeneratePage *tmp_gpParent, wxBoxSizer *tmp_bsMain);
    void onAddType(wxCommandEvent& event);
    void onRemoveType(wxCommandEvent& event);
    void onReadMe(wxCommandEvent& event);



private:
//DECLARE_EVENT_TABLE()

};

#endif //XMWAYLOON_TYPE_GENERATION_CONTAINER_H
