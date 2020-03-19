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
#include <randomizer/root_randomizer.h>



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

    //friend class GenInfoPackaging;


    std::vector<XMwayLoon::Randomizer::RootRandomizer*> vecRandomizer;
    std::shared_ptr<wxFont> font= std::make_shared<wxFont>();
    std::vector<std::string> vecTitles;
    void createGenerateButton();

    void cleanVec();
    ~GeneratePage() final ;

    void onGenerate(wxCommandEvent& event);
    bool validate();

    void  setBooleanType(int i)  ;
    void  setDateType(int i)  ;
    void  setNameType(int i)  ;
    void  setNRCType(int i)  ;
    void  setNumberType(int i)  ;
    void  setPangramType(int i)  ;
    void  setPhNumberType(int i)  ;
    void  setCustomType(int i)  ;


private:








};



#endif // GEN_PANEL_H
