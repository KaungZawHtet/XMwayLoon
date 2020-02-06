//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_ROW_TYPE_LEVEL_1_H
#define XMWAYLOON_ROW_TYPE_LEVEL_1_H

#include <gui/data_generation/type_grid.h>

#include <wx/wx.h>
class Row
{
public:
    int colPointer=0;
    wxString typeName;
    wxString fieldName;
    TypeGrid *gTypeGrid;
    virtual void setTypeOnGrid()=0;
    void setNameCell();
    void setBlankCell(int &rowPointer,int &colPointer);
    void setComboBox (int &rowPointer,int &colPointer , wxString  *arr,int &size );
    void setTextCtrl(int &rowPointer,int &colPointer,wxString prompt);

    explicit Row( const wxString& tmp_typeName,TypeGrid *tmp_gTypeGrid)
    : typeName(tmp_typeName),gTypeGrid(tmp_gTypeGrid){};



};








#endif //XMWAYLOON_ROW_TYPE_LEVEL_1_H
