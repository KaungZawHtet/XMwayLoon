//
// Created by Kaung Zaw Htet on 2019-12-30.
//
#include <tinyxml2/tinyxml2.h>
#include <logic/generation_task_manager/generator.h>
#include <taskflow/taskflow.hpp>
#include <model/generate_info.h>
#include <model/type/enums.h>
#include <csv_writer/CSV_writer.h>
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

using namespace XMwayLoon::Randomizer;




Generator::Generator(GenerateInfo tmp_objGenerateInfo)
        : objGenerateInfo(std::move(tmp_objGenerateInfo)) {
}




void Generator::prepareRanTask() {



    this->arrRanResults= new std::string[this->objGenerateInfo.fieldCount];

    this->taskRandomization=this->taskflow.emplace([&](tf::Subflow &subflow) {

        subflow.parallel_for(0,this->objGenerateInfo.fieldCount,1,[&](int index){
            this->arrRanResults[index]= this->objGenerateInfo.vecRandomizers[index]->getRandom();

            std::cout<< this -> arrRanResults[index] << "\n";
            //  this->arrRanResults[index]=std::string("hello");
        });

    }).name("taskRandomization");
}

void Generator::prepareJSONTask() {


    tf::Task taskJson= this->taskflow.emplace([&](){
        json mainJson;
        json innerJson;
        string path = this->objGenerateInfo.targetFile+".json";

        //cout <<path;
        std::fstream file(path);


        for (int i = 0; i < this->objGenerateInfo.outputRecordAmount; ++i) {

            for (int j = 0; j <this->objGenerateInfo.fieldCount ; ++j) {
                innerJson[this->objGenerateInfo.vecTitles[j]] =this->arrRanResults[j];
            }
            mainJson["item"+std::to_string(i)] =innerJson;

        }
        file << mainJson;

    }).name("taskJSON");
    this->taskRandomization.precede(taskJson);

}

void Generator::writeCsvRow(std::string *arrItems, fstream &fout) {

    for (int i = 0,j=1; i < this->objGenerateInfo.fieldCount; ++j,++i) {
        fout << arrItems[i] ;
        if( j < this->objGenerateInfo.fieldCount ) fout <<  ", " ;

    }
    fout <<"\n";
}


void Generator::prepareCSVTask() {



    tf::Task taskCSV= this->taskflow.emplace([&](){
        fstream fout;
        std::string path =this->objGenerateInfo.targetFile + ".csv";
        fout.open(path.c_str(), ios::out | ios::app);
        for (int i = 0; i < this->objGenerateInfo.outputRecordAmount; ++i) {
            if(this->isFirst)this->writeCsvRow(this->objGenerateInfo.vecTitles.data(), fout);
            this->writeCsvRow( this->arrRanResults, fout);
        }
    }).name("taskCSV");

    this->taskRandomization.precede(taskCSV);


}

void Generator::prepareXMLTask() {
    tf::Task taskXML= this->taskflow.emplace([&](){

        std::string path =this->objGenerateInfo.targetFile + ".xml";
        FILE* ptrFile = fopen(path.c_str(), "w");
        tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);

        tinyxml2::XMLElement* mainElement = xml.NewElement("data");

        for (int j = 0; j < this->objGenerateInfo.outputRecordAmount; ++j) {

            std::string strItem= "item" + std::to_string(j);
            tinyxml2::XMLElement* itemElement= xml.NewElement(strItem.c_str());
            for (int i = 0; i < this->objGenerateInfo.fieldCount; ++i) {

                tinyxml2::XMLText* data = xml.NewText(this->arrRanResults[i].c_str());
                tinyxml2::XMLElement* fieldElement = xml.NewElement(this->objGenerateInfo.vecTitles[i].c_str());
                fieldElement->InsertEndChild(data);
                itemElement->InsertEndChild(fieldElement);
            }
            mainElement->InsertEndChild(itemElement);
        }

        xml.InsertEndChild(mainElement);
        xml.SaveFile(ptrFile);
        fclose(ptrFile);

    }).name("taskXML");
    this->taskRandomization.precede(taskXML);





}

void Generator::prepareHTMLTask() {

    tf::Task taskHTML= this->taskflow.emplace([&](){

        std::string path =this->objGenerateInfo.targetFile + ".html";
        FILE* ptrFile = fopen(path.c_str(), "w");
        tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
        tinyxml2::XMLElement* htmlElement = xml.NewElement("html");
        tinyxml2::XMLElement* bodyElement = xml.NewElement("body");
        tinyxml2::XMLElement* tableElement = xml.NewElement("table");

        for (int j = 0; j < this->objGenerateInfo.outputRecordAmount; ++j) {

            tinyxml2::XMLElement* trElement= xml.NewElement("tr");
            for (int i = 0; i < this->objGenerateInfo.fieldCount; ++i) {

                tinyxml2::XMLText* data = xml.NewText(this->arrRanResults[i].c_str());
                tinyxml2::XMLElement* tdElement = xml.NewElement("td");
                tdElement->InsertEndChild(data);
                trElement->InsertEndChild(tdElement);
            }
            tableElement->InsertEndChild(trElement);
        }

        bodyElement->InsertEndChild(tableElement);
        htmlElement->InsertEndChild(bodyElement);

        xml.InsertEndChild(htmlElement);
        xml.SaveFile(ptrFile);

        fclose(ptrFile);
    }).name("taskHTML");


    this->taskRandomization.precede(taskHTML);

}

void Generator::connectTasks() {

    if (this->objGenerateInfo.objOutputFormat.XML) {
        this->prepareXMLTask();
    }

    if (this->objGenerateInfo.objOutputFormat.JSON) {
        this->prepareJSONTask();
    }

    if (this->objGenerateInfo.objOutputFormat.HTML) {
        this->prepareHTMLTask();
    }

    if (this->objGenerateInfo.objOutputFormat.CSV) {
        this->prepareCSVTask();
    }

}

void Generator::generate() {

  //  std::cout<< this->objGenerateInfo.fieldCount;
this->prepareRanTask();
//this->connectTasks();
    this->  taskflow.dump(std::cout);
this->executor.run(this->taskflow).wait();
}


Generator::~Generator(){

    delete [] arrRanResults;
}



