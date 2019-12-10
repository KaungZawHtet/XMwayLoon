

#include <wx/wx.h>
#include <gui/main_frame.h>
#include <gui/type_list.h>

TypeList::TypeList(wxPanel *parent)
    :wxListCtrl(parent,wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxLC_REPORT|wxLC_VIRTUAL)
{

    // Add first column
        wxListItem col0;
        col0.SetId(0);
        col0.SetText( _("Type") );
        col0.SetWidth(70);
        InsertColumn(0, col0);

        // Add second column
        wxListItem col1;
        col1.SetId(1);
        col1.SetText( _("Encode") );
        col1.SetWidth(50);
        InsertColumn(1, col1);

        // Add third column
        wxListItem col2;
        col2.SetId(2);
        col2.SetText( _("Type Specific Customization 1") );
        col2.SetWidth(170);
        InsertColumn(2, col2);


        // Add third column
        wxListItem col3;
        col3.SetId(3);
        col3.SetText( _("Type Specific Customization 2") );
        col3.SetWidth(170);
        InsertColumn(3, col3);

        // Add fifth column
        wxListItem col4;
        col4.SetId(4);
        col4.SetText( _("Type Specific Customization 3") );
        col4.SetWidth(170);
        InsertColumn(4, col4);

        // Add fifth column
        wxListItem col5;
        col5.SetId(5);
        col5.SetText( _("") );
        col5.SetWidth(100);
        InsertColumn(5, col5);



        //This should reflect your data
        SetItemCount(15);


}

wxString TypeList::OnGetItemText(long item, long column) const{
    //Use item and column to return the correct data for that particular cell. This example just returns "bawls" no matter what
return _("bawls");
}

