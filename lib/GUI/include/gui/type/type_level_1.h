//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_TYPE_LEVEL_1_H
#define XMWAYLOON_TYPE_LEVEL_1_H

#include <gui/data_generation/type_grid.h>

#include <wx/wx.h>
class Type
{
public:
    int colPointer=0;
    wxString typeName;
    TypeGrid *gTypeGrid;
    virtual void setTypeOnGrid()=0;
    void setNameCell();

    explicit Type( const wxString& tmp_typeName,TypeGrid *tmp_gTypeGrid)
    : typeName(tmp_typeName),gTypeGrid(tmp_gTypeGrid){};



};








#endif //XMWAYLOON_TYPE_LEVEL_1_H
