//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#include <logic/generation_task_manager/generator.h>


using namespace XMwayLoon::Randomizer;


Generator::Generator(GenerateInfo *tmp_objGenerateInfo,std::function<void()> funcStart)
        : objGenerateInfo(tmp_objGenerateInfo) {


    this->arrRanResults = new std::string[this->objGenerateInfo->fieldCount];

    if (this->objGenerateInfo->objOutputFormat.XML) {
        this->objXMLWriter = new XMLWriter(this->arrRanResults, this->objGenerateInfo);
    }

    if (this->objGenerateInfo->objOutputFormat.JSON) {
        this->objJSONWriter = new JSONWriter(this->arrRanResults, this->objGenerateInfo);
    }

    if (this->objGenerateInfo->objOutputFormat.HTML) {
        this->objHTMLWriter = new HTMLWriter(this->arrRanResults, this->objGenerateInfo);
    }



    if (this->objGenerateInfo->objOutputFormat.CSV) {
        this->objCSVWriter = new CSVWriter(this->arrRanResults, this->objGenerateInfo);
    }

    this->taskStart= taskflow.emplace(funcStart).name("start");


    this->taskStop= taskflow.emplace([](){}).name("stop");

}


void Generator::prepareRanTask() {



    this->taskRandomization = this->taskflow.emplace([&](tf::Subflow &subflow) {
        subflow.parallel_for(0, this->objGenerateInfo->fieldCount, 1, [&](int index) {

            this->arrRanResults[index] = this->objGenerateInfo->vecRandomizers[index]->getRandom();

            //std::cout << this->arrRanResults[index] << "\n";

        });
    });

    this->taskStart.precede(this->taskRandomization);


}

void Generator::prepareJSONTask() {


    tf::Task taskJson = this->taskflow.emplace([&]() {

         this->objJSONWriter->write();

    }).name("taskJSON");
    this->taskRandomization.precede(taskJson);
    taskJson.precede(this->taskStop);
}


void Generator::prepareCSVTask() {

    tf::Task taskCSV = this->taskflow.emplace([&]() {

         this->objCSVWriter->write();

    }).name("taskCSV");

    this->taskRandomization.precede(taskCSV);
    taskCSV.precede(this->taskStop);

}

void Generator::prepareXMLTask() {
    tf::Task taskXML = this->taskflow.emplace([&]() {

           this->objXMLWriter->write();

    }).name("taskXML");
    this->taskRandomization.precede(taskXML);
    taskXML.precede(this->taskStop);

}

void Generator::prepareHTMLTask() {

    tf::Task taskHTML = this->taskflow.emplace([&]() {
         this->objHTMLWriter->write();

    }).name("taskHTML");


    this->taskRandomization.precede(taskHTML);
    taskHTML.precede(this->taskStop);

}

void Generator::connectTasks() {

    if (this->objGenerateInfo->objOutputFormat.XML) {
        this->prepareXMLTask();
    }

    if (this->objGenerateInfo->objOutputFormat.JSON) {
        this->prepareJSONTask();
    }

    if (this->objGenerateInfo->objOutputFormat.HTML) {
        this->prepareHTMLTask();
    }

    if (this->objGenerateInfo->objOutputFormat.CSV) {
        this->prepareCSVTask();
    }

}

void Generator::generate(std::function<void()> func) {


    this->prepareRanTask();
    this->connectTasks();
//this->taskflow.dump(std::cout);
    executor.run_n(taskflow, this->objGenerateInfo->outputRecordAmount,func).get();
}

tf::Taskflow* Generator::getTaskFow(){
    return &(this->taskflow);
}


Generator::~Generator() {

    //this->taskflow.clear();
    delete this->objGenerateInfo;
    if(this->objCSVWriter!= nullptr)delete this->objCSVWriter;
    if(this->objHTMLWriter!= nullptr)delete this->objHTMLWriter;
    if(this->objJSONWriter!= nullptr)delete this->objJSONWriter;
    if(this->objXMLWriter!= nullptr) delete this->objXMLWriter;
    delete[] arrRanResults;
}



