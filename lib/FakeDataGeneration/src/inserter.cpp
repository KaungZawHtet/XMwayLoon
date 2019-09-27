//
// Created by Kaung Zaw Htet on 2019-09-24.
//

#include "../include/inserter.h"
#include "../include/english_date.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include "../include/english_date.h"



/*void Xlotgative::Inserter::insertGeneralInfo() {

    std::string a;



    std::cout<<"Enter general info: ";
    //std::cin.get(str2,100);
    //std:: cout<< str2;


}*/

/*void Xlotgative::Inserter::initializeEnglishDateInfo(){

   *//* Xlotgative::EnglishDate objEnglishDate;

    std::string filename = "initial_date.txt";
    objEnglishDate.saveMyanmarKeywords(filename);*//*





*//*    Xlotgative::EnglishDate objEnglishDate;


    ofstream englishDateBinaryData("english_date.bin", std::ios::binary | std::ios::out);

    for(std::pair<std::string, pair <string,string>> element  : objEnglishDate.getData())
    {



        cout<< element.first<<endl;
        cout<<element.second.first<<endl;
        cout<<element.second.second<<endl;

        englishDateBinaryData.write(reinterpret_cast<char *>(&(element.first)), sizeof(element.first));
        englishDateBinaryData.write(reinterpret_cast<char *>(&(element.second.first)), sizeof(element.second.first));
        englishDateBinaryData.write(reinterpret_cast<char *>(&(element.second.second)), sizeof(element.second.second));

        englishDateBinaryData.close();


    }*//*


    *//*englishDateBinaryData.write(reinterpret_cast<char*>(ptrMyanmarDateKeywords) , sizeof(ptrMyanmarDateKeywords));
*//*




}*/

 /*Inserter::Inserter() {
     phoneNumberBinaryData("ph_number.bin", std::ios::in | std::ios::out);
     englishDateBinaryData("english_date.bin", std::ios::in | std::ios::out);
     generalBinaryData("general_data.bin", std::ios::in | std::ios::out);
}*/

