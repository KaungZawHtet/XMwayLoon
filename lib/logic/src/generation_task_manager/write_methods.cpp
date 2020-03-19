//
// Created by Kaung Zaw Htet on 2020-02-21.
//

#include <logic/generation_task_manager/random_data_writers.h>


tinyxml2::XMLElement *HTMLWriter::writeHTMLRow(const char *tag,std::string *arrItems ) {

    tinyxml2::XMLElement* trElement= xml.NewElement("tr");
    for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {
        // std::cout<<this->arrRanResults[i]<< std::endl;
        tinyxml2::XMLText* data = xml.NewText(arrItems[i].c_str());
        // std::cout<<"HTML::" <<data<<"\n";
        tinyxml2::XMLElement* tdElement = xml.NewElement(tag);
        tdElement->SetAttribute("border","1px solid black");
        tdElement->InsertEndChild(data);
        trElement->InsertEndChild(tdElement);
    }

    return trElement;
}


void HTMLWriter::write() {


    if(this->isFirst)
    {
        this->tableElement->InsertEndChild(this->writeHTMLRow("th",this->objGenerateInfo->vecTitles.data()));
    this->isFirst= false;
    }

    this->tableElement->InsertEndChild(this->writeHTMLRow("td",this->arrRanResults));



    if(this->iHTML == this->objGenerateInfo->outputRecordAmount)
        {
        std::cout<< "Writing HTML under progress  : \n";
            this->bodyElement->InsertEndChild(this->tableElement);
            this->htmlElement->InsertEndChild(this->bodyElement);

            this->xml.InsertEndChild(this->htmlElement);
            this->xml.SaveFile(this->ptrFile);
            fclose(this->ptrFile);
            std::cout<< "Finished HTML writing! \n";
        }

    ++(this->iHTML);

}



void XMLWriter::write() {




        std::string strItem= "item" + std::to_string(this->iXML);
        tinyxml2::XMLElement* itemElement= xml.NewElement(strItem.c_str());
        for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {


            tinyxml2::XMLText* data = xml.NewText(this->arrRanResults[i].c_str());
            tinyxml2::XMLElement* fieldElement = xml.NewElement(this->objGenerateInfo->vecTitles[i].c_str());
            fieldElement->InsertEndChild(data);
            itemElement->InsertEndChild(fieldElement);
        }
        this->mainElement->InsertEndChild(itemElement);




    if(this->iXML == this->objGenerateInfo->outputRecordAmount)
    {
        xml.InsertEndChild(mainElement);
        std::cout<<"Writing XML under progress : \n";
        xml.SaveFile(ptrFile);
        fclose(ptrFile);
        std::cout<<"Finished XML writing! \n";
    }

    ++(this->iXML);


}



void CSVWriter::write() {



        // std::cout<<"CSV::" <<this->arrRanResults[i]<<"\n";
        if(this->isFirst)   {
            this->writeCSVRow(this->objGenerateInfo->vecTitles.data());
            this->isFirst=false;
        }
        this->writeCSVRow(this->arrRanResults );
        ++(this->iCSV);


}

void CSVWriter::writeCSVRow(std::string *arrItems) {


    for (int i = 0; i < this->objGenerateInfo->fieldCount; ++i) {
        fout << arrItems[i] ;
        if( (i+1) < this->objGenerateInfo->fieldCount ) fout <<  "," ;

    }
    fout <<"\n";
}

void JSONWriter::write() {



        for (int j = 0; j <this->objGenerateInfo->fieldCount ; ++j) {

            this->innerJson[this->objGenerateInfo->vecTitles[j]] =this->arrRanResults[j];


        }

        this->mainJson["item"+std::to_string(this->iJSON)] =innerJson;



        if(this->iJSON == this->objGenerateInfo->outputRecordAmount)
        {
            std::cout<< "Writing JSON under progress : \n";
            file << mainJson;
            std::cout<<"Finished JSON writing! \n";
        }



        ++(this->iJSON);






}