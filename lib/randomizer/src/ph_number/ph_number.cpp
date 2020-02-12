//
// Created by Kaung Zaw Htet on 2020-02-10.
//

#include <randomizer/ph_num/ph_number.h>


XMwayLoon::Randomizer::PhoneNumber::PhoneNumber(XML_RE::CountryCodeFlag tmp_ccFlag)
: ccFlag (tmp_ccFlag) {
    this->load();

}
void XMwayLoon::Randomizer::PhoneNumber::load() {

    std::random_device objRD;
    this->objPCG.seed( objRD);
}
std::string XMwayLoon::Randomizer::PhoneNumber::getPrefix() {

    switch (this->ccFlag)
    {
        case XML_RE::CountryCodeFlag::zero_nine :
            return this->prefix[0];

        case XML_RE::CountryCodeFlag::plus_nine_five :
            return this->prefix[1];
        case XML_RE::CountryCodeFlag::nine_five :
            return this->prefix[2];
        case XML_RE::CountryCodeFlag::random :
        {

            std::uniform_int_distribution<int> flagDistribution(0, 2);
            int index =flagDistribution(this->objPCG) ;
            return this->prefix[index];
        }
    }

}
