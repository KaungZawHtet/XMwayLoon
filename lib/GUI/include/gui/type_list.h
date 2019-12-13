#ifndef TYPE_LIST_H
#define TYPE_LIST_H
#include <wx/listctrl.h>
#include <wx/wx.h>

class TypeList: public wxListCtrl{


public:
    TypeList(wxWindow *parent);
    //wxString OnGetItemText(long item, long column) const ;

};


#endif // TYPE_LIST_H
