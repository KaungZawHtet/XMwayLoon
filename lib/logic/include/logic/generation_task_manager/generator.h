//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#ifndef XMWAYLOON_GENERATOR_H
#define XMWAYLOON_GENERATOR_H


#include <taskflow/taskflow.hpp>
#include <model/type/typedef.h>
#include <model/model.h>
#include <vector>
#include <string>
#include <taskflow/taskflow.hpp>
#include <model/type/typedef.h>
#include <variant>

class Generator
{
public:
    tf::Executor executor;
    tf::Taskflow taskflow;

    tf::Task taskRandomization;
    std::vector<std::string> vecRanResults;
    std::vector<randomizer> vecRandomizers;

    GenerateInfo objGenerateInfo;



    explicit Generator( GenerateInfo tmp_objGenerateInfo );


    void generate();




};

#endif //XMWAYLOON_GENERATOR_H
