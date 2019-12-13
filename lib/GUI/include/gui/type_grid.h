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
    TypeGrid(wxWindow *parent);
    int row=5,column=5,row_pointer=0,col_pointer=0;


};

#endif //XMWAYLOON_TYPE_GRID_H
