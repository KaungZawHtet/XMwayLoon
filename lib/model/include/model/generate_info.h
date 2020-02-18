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
#include <randomizer/root_randomizer.h>


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
    int fieldCount;
    OutputFormat objOutputFormat;
    EncodingType encodingType;
    std::string targetFile;
    double outputRecordAmount;
    double outputFileSize;
    std::vector<XMwayLoon::Randomizer::RootRandomizer*> vecRandomizers;
    std::vector<std::string> vecTitles;


};


#endif //XMWAYLOON_GENERATE_INFO_H
