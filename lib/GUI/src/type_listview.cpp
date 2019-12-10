
#include <wx/wx.h>
#include <gui/type_listview.h>
#include <gui/main_frame.h>

TypeListView::TypeListView(wxPanel *parent):
    wxListView(parent, wxID_ANY,
               wxDefaultPosition, wxSize(600, -1))
{

    this->AppendColumn("Column 1");
    this-AppendColumn("Column 2");
     this-AppendColumn("Column 3");
     this-AppendColumn("Column 4");
     this-AppendColumn("Column 5");

}
