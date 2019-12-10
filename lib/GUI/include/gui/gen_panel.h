#ifndef GEN_PANEL_H
#define GEN_PANEL_H
#include <wx/wx.h>
#include <gui/type_list.h>
#include <gui/type_listview.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <gui/record_number_spin_ctrl.h>
class GenPanel : public wxPanel
{
public:
    GenPanel(wxWindow*);
    wxBoxSizer *bsMain;

    wxStaticText *stAddTypeTitle;
    wxButton *btnAddType;
    wxComboBox *cbAddType;
    wxBoxSizer *bsAddType;
    wxBoxSizer *bsAddTypeTitle;

    wxBoxSizer *bsTypeList;
    TypeList *lcTypeList;



    wxStaticText *stRecordSizeTitle;
    wxBoxSizer *bsRecordSizeTitle;
    wxBoxSizer *bsRecordSize;
    wxRadioButton *rdRecordNumber;
    wxRadioButton *rdFileSize;
   // wxSpinCtrl *scRecordNumber;
    wxSpinCtrlDouble *scFileSize;
    std::unique_ptr<RecordNumberSpinCtrl> scRecordNumber;
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

    wxStaticLine *sl0;
    wxStaticLine *sl1;
    wxStaticLine *sl2;
    wxStaticLine *sl3;



    void createTypeAdditionGroup();
    void createOutputAmountGroup();
    void createOutputFormatGroup();
    void createEncodeTypeGroup();
    void createGenerateButton();
    void onGenerate(wxCommandEvent& event);

private:
     DECLARE_EVENT_TABLE()







};

#endif // GEN_PANEL_H
