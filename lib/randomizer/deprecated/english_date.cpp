//
// Created by Kaung Zaw Htet on 2019-09-21.
//

#include "english_date.h"
#include <map>
#include <string>

EnglishDate::EnglishDate() {

    myanmarDate.insert("January", "ဇန်နဝါရီ");
    myanmarDate.insert("February", "ဖေဖဝါရီ");
    myanmarDate.insert("March", "မတ်");
    myanmarDate.insert("April", "ဧပရယ်");
    myanmarDate.insert("May", "မေ");
    myanmarDate.insert("June", "ဂျွန်");
    myanmarDate.insert("July", "ဂျူလိုင်");
    myanmarDate.insert("August", "ဩဂုတ်");
    myanmarDate.insert("September", "စက်တင်ဘာ");
    myanmarDate.insert("October", "အောက်တိုဘာ");
    myanmarDate.insert("November", "နိုဝင်ဘာ");
    myanmarDate.insert("December", "ဒီစင်ဘာ");


    myanmarDate.insert("0", "၀");
    myanmarDate.insert("1", "၁");
    myanmarDate.insert("2", "၂");
    myanmarDate.insert("3", "၃");
    myanmarDate.insert("4", "၄");
    myanmarDate.insert("5", "၅");
    myanmarDate.insert("6", "၆");
    myanmarDate.insert("7", "၇");
    myanmarDate.insert("8", "၈");
    myanmarDate.insert("9", "၉");

}

std::wstring convertEnglishNumberToMyanmar(std::string & englishNumber){

    std::wstring result;

    transfrom

}