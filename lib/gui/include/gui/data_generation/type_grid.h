//
// Created by Kaung Zaw Htet on 2019-12-12.
//

#ifndef XMWAYLOON_TYPE_GRID_H
#define XMWAYLOON_TYPE_GRID_H

#include <variant>
#include <model/type/alphanumeric_type.h>
#include <model/type/numeric_type.h>
#include <wx/wx.h>
#include <wx/grid.h>
#include <any>

class TypeGrid : public wxGrid {
public:
    TypeGrid(wxWindow *wParent);

    int rows = 6, columns = 7, rowPointer = 0, colPointer = 0;
    bool doesDataExist = false;




    std::vector<std::string> vecTypeNames;


};

#endif //XMWAYLOON_TYPE_GRID_H
