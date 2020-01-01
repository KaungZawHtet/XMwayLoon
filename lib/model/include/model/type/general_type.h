//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_GENERAL_TYPE_H
#define XMWAYLOON_GENERAL_TYPE_H

#include <string>


struct Type {

    int index;
    std::string fieldName;
};
struct AlphanumericType : public Type
{
    std::string encoding;

};

struct NumericType : public Type
{

};


#endif //XMWAYLOON_GENERAL_TYPE_H
