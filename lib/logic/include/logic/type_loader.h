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



//this order is fixed. change can lead to crash
    static inline std::vector<wxString> vecAllTypes= {
            "Boolean",
            "Date",
            "Name",
            "NRC",
            "Number",
            "Pangram",
            "Ph Number"
    };

    static inline int totalCount= vecAllTypes.size();


     TypeLoader();
    static inline void load();



};



#endif //XMWAYLOON_TYPE_LOADER_H
