//
// Created by Kaung Zaw Htet on 2020-02-03.
//

#ifndef XMWAYLOON_CONNECTOR_H
#define XMWAYLOON_CONNECTOR_H

#include <memory>
template <typename R,typename T,typename TN>
struct connector
{
public:
    int index;
    TN typeName;
    T type;
    R randomizer;

    connector(int tmp_index,TN tmp_typeName,T tmp_type,R tmp_randomizer) :
            index(std::move(tmp_index)), typeName (std::move(tmp_typeName))
            ,  type (std::move(tmp_type)),randomizer (std::move(tmp_randomizer))
    {

    }


};







#endif //XMWAYLOON_CONNECTOR_H
