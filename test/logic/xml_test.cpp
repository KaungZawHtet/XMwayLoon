//
// Created by Kaung Zaw Htet on 2020-01-06.
//
#include <gtest/gtest.h>
#include <tinyxml2/tinyxml2.h>
#include <model/db/initializer.h>
#include <string>


TEST(XMLTest, writeXML1) {

    std::string path = Initializer::directory+"/key.xml";

    FILE* ptrFile = fopen(path.c_str(), "w");
    tinyxml2::XMLPrinter printer(ptrFile);
    std::vector<std::string> title= {"id","name","email","age"};
    std::vector<std::string> data= {"6","Mya","r@gmail.com","21"};

    printer.OpenElement( "data" );

    for (int i = 0; i < 4; ++i) {
        printer.OpenElement( title[i].c_str() );
        printer.PushText(data[i].c_str());
        printer.OpenElement( title[i].c_str()  );
        printer.CloseElement();
    }
    printer.OpenElement( "data" );
    printer.CloseElement();
    //printer.OpenElement( "item1" );
   // printer.OpenElement( "item2" );





    fclose(ptrFile);


}

TEST(XMLTest, writeXML2) {
    std::string path = Initializer::directory+"/key.xml";
    FILE* ptrFile = fopen(path.c_str(), "w");


    tinyxml2::XMLDocument xml=  tinyxml2::XMLDocument(true, tinyxml2::COLLAPSE_WHITESPACE);

    std::vector<std::string> title= {"id","name","email","age"};
    std::vector<std::string> data= {"6","Mya","r@gmail.com","21"};


    tinyxml2::XMLElement* mainElement = xml.NewElement("data");
    tinyxml2::XMLElement* dataElement;

    for (int j = 0; j < 4; ++j) {

        tinyxml2::XMLElement* itemElement= xml.NewElement("item");
        for (int i = 0; i < 4; ++i) {

            tinyxml2::XMLText* xmltext = xml.NewText(data[i].c_str());
            dataElement = xml.NewElement(title[i].c_str());
            dataElement->InsertEndChild(xmltext);
            itemElement->InsertEndChild(dataElement);
        }
        mainElement->InsertEndChild(itemElement);
    }

   // tinyxml2::XMLPrinter *printer = new tinyxml2::XMLPrinter(0, false, 0);
    //printer->PushHeader(false, true);

    xml.InsertEndChild(mainElement);
    xml.SaveFile(ptrFile);

    //xml.Print(&printer);


    fclose(ptrFile);
}