//
// Created by Kaung Zaw Htet on 2019-12-12.
//

#ifndef XMWAYLOON_TYPE_GRID_H
#define XMWAYLOON_TYPE_GRID_H

#include <wx/wx.h>
#include <wx/grid.h>
class TypeGrid : public wxGrid
{
public:
    TypeGrid(wxWindow *wParent);
    int row=5,column=5,rowPointer=0,colPointer=0;
    bool doesDataExist= false;


};

#endif //XMWAYLOON_TYPE_GRID_H
