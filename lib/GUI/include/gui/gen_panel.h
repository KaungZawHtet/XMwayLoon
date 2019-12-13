#ifndef GEN_PANEL_H
#define GEN_PANEL_H
#include <wx/wx.h>
#include <gui/type_list.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <gui/type_grid.h>
#include <gui/type_generation.h>
class GenPanel : public wxPanel
{
public:
    GenPanel(wxWindow*);
    wxBoxSizer *bsMain;

    TypeGeneration *objTypeGeneration;




    wxStaticText *stRecordSizeTitle;
    wxBoxSizer *bsRecordSizeTitle;
    wxBoxSizer *bsRecordSize;
    wxRadioButton *rdRecordNumber;
    wxRadioButton *rdFileSize;
    wxSpinCtrl *scRecordNumber;
    wxSpinCtrlDouble *scFileSize;
    wxStaticText *stRecordNumberUnit;
    wxStaticText *stFileSizeUnit;


    wxStaticText *stFormatTypeTitle;
    wxBoxSizer *bsFormatTypeTitle;
    wxBoxSizer *bsFormatType;
    wxCheckBox *cbCSV;
    wxCheckBox *cbJSON;
    wxCheckBox *cbXML;
    wxCheckBox *cbHTML;

    wxStaticText *stEncodeTypeTitle;
    wxBoxSizer *bsEncodeTypeTitle;
    wxBoxSizer *bsEncodeType;
    wxRadioButton *rdUnicode;
    wxRadioButton *rdZawgyi;
    wxRadioButton *rdRandom;
    wxRadioButton *rdCustom;

    wxBoxSizer *bsGenerate;
    wxButton *btnGenerate;

    wxStaticLine *sl1;
    wxStaticLine *sl2;
    wxStaticLine *sl3;



    void createTypeAdditionGroup();
    void createOutputAmountGroup();
    void createOutputFormatGroup();
    void createEncodeTypeGroup();
    void createGenerateButton();


    void onGenerate(wxCommandEvent& event);
    void onChangeOutputAmountType(wxCommandEvent& event);
    void onTargetUnicode(wxCommandEvent& event);
    void onTargetZawgyi(wxCommandEvent& event);
    void onTargetRandom(wxCommandEvent& event);
    void onTargetCustom(wxCommandEvent& event);

private:
     DECLARE_EVENT_TABLE()







};

#endif // GEN_PANEL_H
