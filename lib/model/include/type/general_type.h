//
// Created by Kaung Zaw Htet on 2019-12-22.
//

#ifndef XMWAYLOON_GENERAL_TYPE_H
#define XMWAYLOON_GENERAL_TYPE_H

struct Type {
    std::string typeName;
};
struct AlphanumericType : public Type
{
    std::string encoding;

};

struct NumericType
{

};


#endif //XMWAYLOON_GENERAL_TYPE_H
