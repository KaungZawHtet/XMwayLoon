#ifndef EXTEND_PANEL_H
#define EXTEND_PANEL_H
#include <wx/wx.h>
#include <wx/statline.h>
#include <gui/type_extension/extension_by_file_container.h>
#include <gui/type_extension/extension_manually_container.h>

class ExtendPage : public wxPanel
{


public:
    wxBoxSizer *bsMain;
    ExtensionByFile_Container *ctExtensionByFile_Container;
    ExtensionManually_Container *ctExtensionManually_Container;


    std::shared_ptr<wxFont> font= std::make_shared<wxFont>();
    explicit ExtendPage(wxWindow *wParent);
};


#endif // EXTEND_PANEL_H
