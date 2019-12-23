//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_MODEL_H
#define XMWAYLOON_MODEL_H

#include <string>
#include <any>
#include <vector>


struct OutputFormat {
    bool CSV;
    bool JSON;
    bool XML;
    bool HTML;

};

enum class EncodingType{
    unicode,zawgyi,random,custom
};

struct GenerateInfo
{
    OutputFormat objOutputFormat;
    EncodingType encodingType;
    std::string targetFile;
    double outputRecordAmount=NULL;
    double outputFileSize=NULL;
    std::vector<std::any> types;

};


#endif //XMWAYLOON_MODEL_H
