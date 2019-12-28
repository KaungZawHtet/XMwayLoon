//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_MODEL_H
#define XMWAYLOON_MODEL_H
#include <boost/hana.hpp>
#include <string>
#include <any>
#include <vector>

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
    double outputRecordAmount=NULL;
    double outputFileSize=NULL;
    std::vector<std::vector<std::string>> types;

};


#endif //XMWAYLOON_MODEL_H
