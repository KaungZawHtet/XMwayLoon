#ifndef GEN_PANEL_H
#define GEN_PANEL_H
#include <wx/wx.h>
#include <wx/statline.h>
#include <wx/spinctrl.h>
#include <gui/data_generation/type_grid.h>
#include <gui/data_generation/type_generation_container.h>
#include <gui/data_generation/encoding_type_container.h>
#include <gui/data_generation/output_amount_container.h>
#include <gui/data_generation/generated_file_container.h>
#include <gui/data_generation/output_format_container.h>
class GeneratePage : public wxPanel
{
public:
    GeneratePage(wxWindow*);
    wxBoxSizer *bsMain;

    TypeGenerationContainer *ctTypeGeneration;
    EncodingTypeContainer *ctEncodeingTypeContainer;
    OutputAmountContainer *ctOutputAmountContainer;
    OutputFormatContainer *ctOutputFormatContainer;
    GeneratedFileContainer *ctGeneratedFileContainer;

    wxBoxSizer *bsGenerate;
    wxButton *btnGenerate;


    std::shared_ptr<wxFont> font= std::make_shared<wxFont>();
    void createGenerateButton();


    void onGenerate(wxCommandEvent& event);
    bool validate();


private:








};

#endif // GEN_PANEL_H
