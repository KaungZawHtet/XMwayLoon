//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#ifndef XMWAYLOON_GENERATOR_H
#define XMWAYLOON_GENERATOR_H


#include <taskflow/taskflow.hpp>
#include <model/type/typedef.h>
#include <model/generate_info.h>
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


    bool isFirst=true;
    tf::Task taskRandomization;
    std::string *arrRanResults;

    GenerateInfo objGenerateInfo;



    explicit Generator( GenerateInfo tmp_objGenerateInfo );

    void writeCsvRow(std::string *arrItems,std::fstream &fout);
    void prepareRanTask();
    void prepareJSONTask();
    void prepareCSVTask();
    void prepareXMLTask();
    void prepareHTMLTask();
    void connectTasks();
    void generate();

    ~Generator();


};

#endif //XMWAYLOON_GENERATOR_H
