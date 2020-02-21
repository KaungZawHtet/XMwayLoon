//
// Created by Kaung Zaw Htet on 2020-02-21.
//

#include <logic/generation_task_manager/random_data_writers.h>



JSONWriter::JSONWriter(std::string *tmp_arrRanResults, GenerateInfo *tmp_objGenerateInfo)
: RootWriter(tmp_arrRanResults, tmp_objGenerateInfo) {

    this->path =this->objGenerateInfo->targetFile + ".json";
    this->file=std::ofstream(this->path);

}


XMLWriter::XMLWriter(std::string *tmp_arrRanResults, GenerateInfo *tmp_objGenerateInfo)
: RootWriter(tmp_arrRanResults,tmp_objGenerateInfo) {
    this->path =this->objGenerateInfo->targetFile + ".xml";
    this->ptrFile=fopen(path.c_str(), "w");
}


HTMLWriter::HTMLWriter(std::string *tmp_arrRanResults, GenerateInfo *tmp_objGenerateInfo)
        : RootWriter(tmp_arrRanResults, tmp_objGenerateInfo) {

    this->path =this->objGenerateInfo->targetFile + ".html";
    this->ptrFile=fopen(path.c_str(), "w");

}

CSVWriter::CSVWriter(std::string *tmp_arrRanResults, GenerateInfo *tmp_objGenerateInfo)
: RootWriter(tmp_arrRanResults,tmp_objGenerateInfo) {



    this->path =this->objGenerateInfo->targetFile + ".csv";
    this->fout.open(path, std::ios::out | std::ios::app);
}




RootWriter::RootWriter(std::string *tmp_arrRanResults, GenerateInfo *tmp_objGenerateInfo):
arrRanResults(tmp_arrRanResults),objGenerateInfo(tmp_objGenerateInfo)
{

}
