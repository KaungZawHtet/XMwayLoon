//
// Created by Kaung Zaw Htet on 2019-12-18.
//

#ifndef XMWAYLOON_TYPE_LEVEL_3_H
#define XMWAYLOON_TYPE_LEVEL_3_H


#include <gui/type/type_level_2.h>

struct Boolean : public AlphaNumericType
{



};
struct Date : public AlphaNumericType
{

};
struct IPAddress : public NumericType
{

};

struct NRC : public AlphaNumericType
{

};
struct Number : public NumericType
{

};



#endif //XMWAYLOON_TYPE_LEVEL_3_H
