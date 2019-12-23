//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_MODEL_H
#define XMWAYLOON_MODEL_H

#include <string>




struct OutputFormat {
    std::string CSV;
    std::string JSON;
    std::string XML;
    std::string HTML;

};

struct GenerateInfo
{
    OutputFormat objOutputFormat;
    std::string encodingType;
    std::string targetFile;
    std::string outputAmount;

};


#endif //XMWAYLOON_MODEL_H
