#ifndef GEN_PANEL_H
#define GEN_PANEL_H
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <gui/type_grid.h>
#include <gui/type_generation_container.h>
#include <gui/encoding_type_container.h>
#include <gui/output_amount_container.h>
#include <gui/output_format_container.h>
class GeneratePage : public wxPanel
{
public:
    GeneratePage(wxWindow*);
    wxBoxSizer *bsMain;

    TypeGenerationContainer *ctTypeGeneration;
    EncodingTypeContainer *ctEncodeingTypeContainer;
    OutputAmountContainer *ctOutputAmountContainer;
    OutputFormatContainer *ctOutputFormatContainer;

    wxBoxSizer *bsGenerate;
    wxButton *btnGenerate;


    void createGenerateButton();


    void onGenerate(wxCommandEvent& event);



private:








};

#endif // GEN_PANEL_H
