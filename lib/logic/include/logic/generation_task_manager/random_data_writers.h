//
// Created by Kaung Zaw Htet on 2020-02-21.
//

#ifndef XMWAYLOON_RANDOM_DATA_WRITERS_H
#define XMWAYLOON_RANDOM_DATA_WRITERS_H
#include <model/generate_info.h>
#include <nlohmann/json.hpp>
#include <tinyxml2/tinyxml2.h>


// for convenience
using json = nlohmann::json;

class RootWriter
{
protected:
    std::string path;
    std::string *arrRanResults;
    GenerateInfo *objGenerateInfo;

public:
    RootWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    virtual void write()=0;
};
////////////////////////////////////////





class XMLWriter :public RootWriter
{

   long iXML=0;
    FILE* ptrFile;
    tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
    tinyxml2::XMLElement* mainElement = xml.NewElement("data");
public:
    XMLWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;

};






////////////////////////////////////////
class HTMLWriter :public RootWriter
{
    long iHTML=0;
    FILE* ptrFile;
    tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
    tinyxml2::XMLElement* htmlElement = xml.NewElement("html");
    tinyxml2::XMLElement* bodyElement = xml.NewElement("body");
    tinyxml2::XMLElement* tableElement = xml.NewElement("table");
    
public:
    HTMLWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;
};




////////////////////////////////////////




class CSVWriter :public RootWriter
{
    bool isFirst=true;
    long iCSV=0;
    std::fstream fout;
    void writeCSVRow(std::string *arrItems);
public:
    CSVWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;

};





////////////////////////////////////////





class JSONWriter :public RootWriter
{
    json mainJson;
    json innerJson;
    long iJSON=0;
    std::ofstream file;
public:
    JSONWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;
};





#endif //XMWAYLOON_RANDOM_DATA_WRITERS_H
