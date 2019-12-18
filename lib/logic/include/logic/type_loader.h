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
            "Number",
            "Pangram",
            "Boolean",
            "NRC",
            "Date",
            "IP Address",
            "Ph Number"
    };
    int totalCount= sizeof(defaultType)/sizeof(defaultType[0]);



};



#endif //XMWAYLOON_TYPE_LOADER_H
