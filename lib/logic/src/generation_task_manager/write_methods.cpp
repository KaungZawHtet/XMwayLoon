//
// Created by Kaung Zaw Htet on 2020-02-21.
//

#include <logic/generation_task_manager/random_data_writers.h>

int HTMLWriter::write() {

    while ( this->iHTML < this->objGenerateInfo->outputRecordAmount) {

        tinyxml2::XMLElement* trElement= xml.NewElement("tr");
        for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {
            std::cout<<this->arrRanResults[i]<< std::endl;
            tinyxml2::XMLText* data = xml.NewText(this->arrRanResults[i].c_str());
            // std::cout<<"HTML::" <<data<<"\n";
            tinyxml2::XMLElement* tdElement = xml.NewElement("td");
            tdElement->InsertEndChild(data);
            trElement->InsertEndChild(tdElement);
        }
        this->tableElement->InsertEndChild(trElement);

        ++(this->iHTML);

        if ((this->iHTML+1) == this->objGenerateInfo->outputRecordAmount) return 1;
        else return 0;
    }

    this->bodyElement->InsertEndChild(this->tableElement);
    this->htmlElement->InsertEndChild(this->bodyElement);

    this->xml.InsertEndChild(this->htmlElement);
    this->xml.SaveFile(this->ptrFile);
    fclose(this->ptrFile);

}



int XMLWriter::write() {


    while ( this->iXML < this->objGenerateInfo->outputRecordAmount) {

        std::string strItem= "item" + std::to_string(this->iXML+1);
        tinyxml2::XMLElement* itemElement= xml.NewElement(strItem.c_str());
        for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {


            tinyxml2::XMLText* data = xml.NewText(this->arrRanResults[i].c_str());
            tinyxml2::XMLElement* fieldElement = xml.NewElement(this->objGenerateInfo->vecTitles[i].c_str());
            fieldElement->InsertEndChild(data);
            itemElement->InsertEndChild(fieldElement);
        }
        this->mainElement->InsertEndChild(itemElement);

        ++(this->iXML);

        if ((this->iXML+1) == this->objGenerateInfo->outputRecordAmount) return 1;
        else return 0;
    }

    xml.InsertEndChild(mainElement);
    xml.SaveFile(ptrFile);
    fclose(ptrFile);


}



int CSVWriter::write() {


    while (this->iCSV < this->objGenerateInfo->outputRecordAmount) {
        // std::cout<<"CSV::" <<this->arrRanResults[i]<<"\n";
        if(this->isFirst)   {
            this->writeCSVRow(this->objGenerateInfo->vecTitles.data());
            this->isFirst=false;
        }
        this->writeCSVRow(this->arrRanResults );
        ++(this->iCSV);

        if ((this->iCSV+1) == this->objGenerateInfo->outputRecordAmount) return 1;
        else return 0;
    }
}

void CSVWriter::writeCSVRow(std::string *arrItems) {


    for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {
        fout << arrItems[i] ;
        if( (i+1) < this->objGenerateInfo->fieldCount ) fout <<  "," ;

    }
    fout <<"\n";
}

int JSONWriter::write() {

    while (this->iJSON < this->objGenerateInfo->outputRecordAmount) {

        for (int j = 0; j <this->objGenerateInfo->fieldCount ; ++j) {
            this->innerJson[this->objGenerateInfo->vecTitles[j]] =this->arrRanResults[j];

        }
        this->mainJson["item"+std::to_string(1+this->iJSON)] =innerJson;

        ++(this->iJSON);

        if ((this->iJSON+1) == this->objGenerateInfo->outputRecordAmount) return 1;
        else return 0;

    }
    file << mainJson;
}