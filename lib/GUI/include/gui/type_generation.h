//
// Created by Kaung Zaw Htet on 2019-12-13.
//

#ifndef XMWAYLOON_TYPE_GENERATION_H
#define XMWAYLOON_TYPE_GENERATION_H

#include <wx/wx.h>
#include <gui/type_grid.h>

class TypeGeneration //: public wxWindow
{
public:
    wxString encoding[3]={"Unicode","Zawgyi","Random"};
    wxString telecom[5]={"MPT","Telenor","Ooredoo","MyTel","Random"};
    wxString numType[2]= {"floating","integer"};
    wxString numSign[2]= {"positive","negative"};


    wxString myanBool[2]={"မှန်/မှား","၁/၀"};
    wxString myanBoolN[2]={"၁၂၈","၂၅၅"};

    wxWindow *parent;

    wxStaticText *stAddTypeTitle;
    wxButton *btnAddType;
    wxComboBox *cbAddType;
    wxBoxSizer *bsAddType;
    wxBoxSizer *bsAddTypeTitle;


    wxBoxSizer *bsTypeGrid;
    TypeGrid *gTypeGrid;

    wxBoxSizer *bsMain;
    wxStaticLine *sl0;


    TypeGeneration(wxWindow *parent,wxBoxSizer *tmp_bsMain);
    void onAddType(wxCommandEvent& event);

  //  virtual bool AcceptsFocus() const;
  //  virtual bool AcceptsFocusFromKeyboard() const;

/*private:
DECLARE_EVENT_TABLE()*/

};

#endif //XMWAYLOON_TYPE_GENERATION_H
