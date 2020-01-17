
#include <wx/wx.h>
#include <gui/type_extension/extend_page.h>
#include <wx/spinctrl.h>

ExtendPage::ExtendPage(wxWindow *wParent)
    : wxPanel(wParent, -1)
{

    this->bsMain = new wxBoxSizer(wxVERTICAL);
    this->ctExtensionByFile_Container= new ExtensionByFile_Container(this, this->bsMain);

   // this->ctOutputAmountContainer= new OutputAmountContainer(this, this->bsMain);

    this->SetSizer(this->bsMain);





}
