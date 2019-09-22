//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#ifndef FAKEDATAGENERATOR_ENGLISH_DATE_H
#define FAKEDATAGENERATOR_ENGLISH_DATE_H
#include <map>
#include <string>

class EnglishDate{

    std::map<std::string, std::wstring> myanmarDate;

public:
    EnglishDate();
  std::wstring convertEnglishNumberToMyanmar(std::string);

};

#endif //FAKEDATAGENERATOR_ENGLISH_DATE_H
