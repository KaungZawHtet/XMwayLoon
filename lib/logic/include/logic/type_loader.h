//
// Created by Kaung Zaw Htet on 2019-12-15.
//

#ifndef XMWAYLOON_TYPE_LOADER_H
#define XMWAYLOON_TYPE_LOADER_H


#include <array>
#include <string>
#include <wx/wx.h>

#include <nlohmann/json.hpp>
// for convenience
using json = nlohmann::json;
class TypeLoader
{

public:




    wxString defaultType[7]= {
            "Boolean",
            "Date",
            "Name",
            "NRC",
            "Number",
            "Pangram",
            "Ph Number"
    };
    int totalCount= sizeof(defaultType)/sizeof(defaultType[0]);


    void load();



};



#endif //XMWAYLOON_TYPE_LOADER_H
