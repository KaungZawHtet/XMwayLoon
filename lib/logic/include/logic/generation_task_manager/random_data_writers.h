//
// Created by Kaung Zaw Htet on 2020-02-21.
//

#ifndef XMWAYLOON_RANDOM_DATA_WRITERS_H
#define XMWAYLOON_RANDOM_DATA_WRITERS_H
#include <model/generate_info.h>
#include <nlohmann/json.hpp>
#include <parallel_hashmap/phmap.h>
#include <tinyxml2/tinyxml2.h>
#include <fifo_map/fifo_map.h>

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

   long iXML=1;
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
    long iHTML=1;
    bool isFirst=true;
    FILE* ptrFile;
    tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);
    tinyxml2::XMLElement* htmlElement = xml.NewElement("html");
    tinyxml2::XMLElement* bodyElement = xml.NewElement("body");
    tinyxml2::XMLElement* tableElement = xml.NewElement("table");

    
public:
    HTMLWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;
    tinyxml2::XMLElement* writeHTMLRow(const char *tag,std::string *arrItems );
};




////////////////////////////////////////




class CSVWriter :public RootWriter
{
    bool isFirst=true;
    long iCSV=1;
    std::fstream fout;
    void writeCSVRow(std::string *arrItems);
public:
    CSVWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;

};





////////////////////////////////////////





class JSONWriter :public RootWriter
{



// A workaround to give to use fifo_map as map, we are just ignoring the 'less' compare
    template<class K, class V, class dummy_compare, class A>
    using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
    using my_json = nlohmann::basic_json<my_workaround_fifo_map>;

    my_json mainJson;
    my_json innerJson;
    long iJSON=1;
    std::ofstream file;
public:
    JSONWriter(std::string *tmp_arrRanResults,GenerateInfo *tmp_objGenerateInfo);
    void write() override;
};





#endif //XMWAYLOON_RANDOM_DATA_WRITERS_H
