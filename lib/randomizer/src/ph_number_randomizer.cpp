//
// Created by Kaung Zaw Htet on 2019-09-23.
//

#include <randomizer/ph_number_randomizer.h>
#include <regex>
#include <randomizer/typedef.h>



/*
XMwayLoon_PhoneNumberRandomizer::PhoneNumberRandomizer() :

{


}
*/

std::string XMwayLoon_PhoneNumberRandomizer::getRandom() {

  switch (this->objPhNumberType.telecom)
  {
      case XML_RE::Telecom::MPT:
          return  this->vecTelecom[0]->getRandom();

      case XML_RE::Telecom::Mytel:
          return  this->vecTelecom[1]->getRandom();

      case XML_RE::Telecom::Ooredoo:
          return  this->vecTelecom[2]->getRandom();

      case XML_RE::Telecom::Telenor:
          return this->vecTelecom[3]->getRandom();

      case XML_RE::Telecom::Random:
      {
          std::uniform_int_distribution<> telecomDistribution(0, 3);
          int index =telecomDistribution(this->objPCG) ;

         return this->vecTelecom[index]->getRandom();

      }



  }
}
void XMwayLoon_PhoneNumberRandomizer::load() {

    std::random_device objRD;
    this->objPCG.seed( objRD);
}
XMwayLoon_PhoneNumberRandomizer::~PhoneNumberRandomizer() {

    for (int j = 0; j < 4 ; ++j) {
       delete this->vecTelecom[j];
    }

}


XMwayLoon_PhoneNumberRandomizer::PhoneNumberRandomizer(PhNumberType tmp_objPhNumberType)
: objPhNumberType(std::move(tmp_objPhNumberType))


{
    this->vecTelecom.reserve(4);
this->vecTelecom={
new MPT(this->objPhNumberType.countryCode),
new MyTel(this->objPhNumberType.countryCode),
new Ooredoo(this->objPhNumberType.countryCode),
new Telenor(this->objPhNumberType.countryCode)
};
   this->load();


}

