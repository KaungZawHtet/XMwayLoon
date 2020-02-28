//
// Created by Kaung Zaw Htet on 2020-02-26.
//


#include <gui/data_generation/generate_page.h>

void GeneratePage::setBooleanType(int i) {

    BooleanType objBooleanType;

    objBooleanType.index = i;
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objBooleanType.setEncoding(tmp_encode);
    objBooleanType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

    std::string tmp_type(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
    objBooleanType.setType(tmp_type);


    this->vecTitles.emplace_back(objBooleanType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::BooleanRandomizer(objBooleanType));

}

void GeneratePage::setDateType(int i) {
    DateType objDateType;

    objDateType.index = i;
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objDateType.setEncoding(tmp_encode);
    objDateType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
    objDateType.format = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4);

    this->vecTitles.emplace_back(objDateType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::DateRandomizer(objDateType));
}

void GeneratePage::setNameType(int i) {
    NameType objNameType;
    objNameType.index = i;
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objNameType.setEncoding(tmp_encode);
    objNameType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

    std::string strGender{this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).c_str()};
    objNameType.gender = XML_RE::genderMap[strGender];

    this->vecTitles.emplace_back(objNameType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NameRandomizer(objNameType));
}

void GeneratePage::setNRCType(int i) {
    NRCType objNRCType;

    objNRCType.index = i;
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objNRCType.setEncoding(tmp_encode);
    objNRCType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

    std::string tmp(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
    objNRCType.setType(tmp);

    this->vecTitles.emplace_back(objNRCType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NRCRandomizer(objNRCType));
}

void GeneratePage::setNumberType(int i) {
    NumberType objNumberType;

    objNumberType.index = i;

    objNumberType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
    std::string tmpSystem(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
    objNumberType.setSystem(tmpSystem);
    objNumberType.prefix = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5);
    objNumberType.postfix = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 6);

    std::string tmpMin(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 7).mb_str());
    std::string tmpMax(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 8).mb_str());
    objNumberType.setMin(tmpMin);
    objNumberType.setMax(tmpMax);

    this->vecTitles.emplace_back(objNumberType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::NumberRandomizer(objNumberType));
}

void GeneratePage::setPangramType(int i) {
    PangramType objPangramType;

    objPangramType.index = i;
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objPangramType.setEncoding(tmp_encode);
    objPangramType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);

    this->vecTitles.emplace_back(objPangramType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::PangramRandomizer(objPangramType));
}

void GeneratePage::setPhNumberType(int i) {
    PhNumberType objPhNumberType;

    objPhNumberType.index = i;

    objPhNumberType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);
    std::string tmp_countryCodeFlat(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 4).mb_str());
    objPhNumberType.setCountryCodeFlag(tmp_countryCodeFlat);
    std::string tmp_telecom(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 5).mb_str());
    objPhNumberType.setTelecom(tmp_telecom);

    this->vecTitles.emplace_back(objPhNumberType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::PhoneNumberRandomizer(objPhNumberType));
}

void GeneratePage::setCustomType(int i) {
    CustomType objCustomType;

    objCustomType.index = i;
    objCustomType.typeName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 1);
    std::string tmp_encode(this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 2).mb_str());
    objCustomType.setEncoding(tmp_encode);
    objCustomType.fieldName = this->ctTypeGeneration->gTypeGrid->GetCellValue(i, 3);


    this->vecTitles.emplace_back(objCustomType.fieldName);
    this->vecRandomizer.emplace_back(new XMwayLoon::Randomizer::CustomRandomizer(objCustomType));
}
