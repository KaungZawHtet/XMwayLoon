//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_GENERAL_TYPE_H
#define XMWAYLOON_GENERAL_TYPE_H

#include <string>
#include <model/type/enums.h>

struct Type {

    int index;
    std::string fieldName;
};
struct AlphanumericType : public Type
{
    XML_RE::Encoding encoding;

   void setEncoding(std::string tmp){
       this->encoding= XML_RE::encodingMap[tmp];

    }

};

struct NumericType : public Type
{

};


#endif //XMWAYLOON_GENERAL_TYPE_H
