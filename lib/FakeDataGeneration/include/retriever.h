//
// Created by Kaung Zaw Htet on 2019-09-26.
//

#ifndef FAKEDATAGENERATOR_RETRIEVER_H
#define FAKEDATAGENERATOR_RETRIEVER_H

#include <filesystem>
#include <fstream>

class  Retriever{

};

void retrieveDate()
{
    std::ifstream englishDateBinaryData("english_date.bin", std::ios::binary | std::ios::in);


    //read
    if(englishDateBinaryData.eof())
    {

    }
}

#endif //FAKEDATAGENERATOR_RETRIEVER_H
