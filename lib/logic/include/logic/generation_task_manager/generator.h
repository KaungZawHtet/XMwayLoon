//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#ifndef XMWAYLOON_GENERATOR_H
#define XMWAYLOON_GENERATOR_H

#include <logic/generation_task_manager/random_data_writers.h>
#include <taskflow/taskflow.hpp>
#include <model/type/typedef.h>
#include <model/generate_info.h>
#include <vector>
#include <string>
#include <taskflow/taskflow.hpp>
#include <model/type/typedef.h>
#include <variant>
#include <logic/generation_task_manager/random_data_writers.h>
class Generator
{
public:
    tf::Executor executor;
    tf::Taskflow taskflow;


    bool isFirst=true;
    tf::Task taskStart;
    tf::Task taskRandomization;
    tf::Task taskStop;
    std::string *arrRanResults;
    int count=1;

    GenerateInfo *objGenerateInfo;

    CSVWriter *objCSVWriter= nullptr;
    HTMLWriter *objHTMLWriter= nullptr;
    JSONWriter *objJSONWriter= nullptr;
    XMLWriter *objXMLWriter= nullptr;



    explicit Generator( GenerateInfo *tmp_objGenerateInfo ,std::function<void()> funcStart);


    void prepareRanTask();
    void prepareJSONTask();
    void prepareCSVTask();
    void prepareXMLTask();
    void prepareHTMLTask();
    void connectTasks();
    bool generate(std::function<void()> func);
    tf::Taskflow* getTaskFow();

    ~Generator();


};

#endif //XMWAYLOON_GENERATOR_H
