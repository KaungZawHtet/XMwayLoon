#ifndef GEN_PANEL_H
#define GEN_PANEL_H
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <gui/type_grid.h>
#include <gui/type_generation_panel.h>
#include <gui/encoding_type_panel.h>
#include <gui/output_amount_panel.h>
#include <gui/output_format_panel.h>
class GeneratePage : public wxPanel
{
public:
    GeneratePage(wxWindow*);
    wxBoxSizer *bsMain;

    TypeGenerationPanel *pnlTypeGeneration;
    EncodingTypePanel *pnlEncodeingTypePanel;
    OutputAmountPanel *pnlOutputAmountPanel;


    wxStaticText *stRecordSizeTitle;
    wxBoxSizer *bsRecordSizeTitle;
    wxBoxSizer *bsRecordSize;
    wxRadioButton *rdRecordNumber;
    wxRadioButton *rdFileSize;
    wxSpinCtrl *scRecordNumber;
    wxSpinCtrlDouble *scFileSize;
    wxStaticText *stRecordNumberUnit;
    wxStaticText *stFileSizeUnit;
    wxStaticLine *sl1;



    wxStaticText *stFormatTypeTitle;
    wxBoxSizer *bsFormatTypeTitle;
    wxBoxSizer *bsFormatType;
    wxCheckBox *cbCSV;
    wxCheckBox *cbJSON;
    wxCheckBox *cbXML;
    wxCheckBox *cbHTML;



    wxBoxSizer *bsGenerate;
    wxButton *btnGenerate;


    wxStaticLine *sl2;




    void createOutputFormatGroup();
    void createGenerateButton();


    void onGenerate(wxCommandEvent& event);



private:








};

#endif // GEN_PANEL_H
