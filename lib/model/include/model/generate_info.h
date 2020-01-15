//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_GENERATE_INFO_H
#define XMWAYLOON_GENERATE_INFO_H
#include <boost/hana.hpp>
#include <string>
#include <any>
#include <vector>
#include <model/type/typedef.h>
#include <randomizer/typedef.h>



namespace hana = boost::hana;
struct OutputFormat {
    bool CSV;
    bool JSON;
    bool XML;
    bool HTML;

};

enum class EncodingType{
    unicode=1,zawgyi=2,uniform_random=3,custom=4
};

struct GenerateInfo
{
    OutputFormat objOutputFormat;
    EncodingType encodingType;
    std::string targetFile;
    double outputRecordAmount=-1;
    double outputFileSize=-1;
    std::vector<type> vecTypes;
    std::vector<std::string> vecTypeNames;

};


#endif //XMWAYLOON_GENERATE_INFO_H
