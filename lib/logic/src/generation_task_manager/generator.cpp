//
// Created by Kaung Zaw Htet on 2019-12-30.
//

#include <logic/generation_task_manager/generator.h>


using namespace XMwayLoon::Randomizer;


Generator::Generator(GenerateInfo *tmp_objGenerateInfo)
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



}


void Generator::prepareRanTask() {

    this->taskStop= taskflow.emplace([](){}).name("stop");

    this->taskRandomization = this->taskflow.emplace([&](tf::Subflow &subflow) {
        subflow.parallel_for(0, this->objGenerateInfo->fieldCount, 1, [&](int index) {

            this->arrRanResults[index] = this->objGenerateInfo->vecRandomizers[index]->getRandom();

            std::cout << this->arrRanResults[index] << "\n";

        });
    });


}

void Generator::prepareJSONTask() {


    tf::Task taskJson = this->taskflow.emplace([&]() {


        return this->objJSONWriter->write();

    }).name("taskJSON");
    this->taskRandomization.precede(taskJson);
    taskJson.precede(this->taskRandomization,this->taskStop);
}


void Generator::prepareCSVTask() {

    tf::Task taskCSV = this->taskflow.emplace([&]() {

        return this->objCSVWriter->write();

    }).name("taskCSV");

    this->taskRandomization.precede(taskCSV);
    taskCSV.precede(this->taskRandomization,this->taskStop);

}

void Generator::prepareXMLTask() {
    tf::Task taskXML = this->taskflow.emplace([&]() {

        return   this->objXMLWriter->write();

    }).name("taskXML");
    this->taskRandomization.precede(taskXML);
    taskXML.precede(this->taskRandomization,this->taskStop);

}

void Generator::prepareHTMLTask() {

    tf::Task taskHTML = this->taskflow.emplace([&]() {
        return this->objHTMLWriter->write();

    }).name("taskHTML");


    this->taskRandomization.precede(taskHTML);
    taskHTML.precede(this->taskRandomization,this->taskStop);

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

void Generator::generate() {


    this->prepareRanTask();
    this->connectTasks();
//this->taskflow.dump(std::cout);
    this->executor.run(this->taskflow).wait();
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



