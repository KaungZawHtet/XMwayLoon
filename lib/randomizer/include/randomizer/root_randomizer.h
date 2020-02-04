//
// Created by Kaung Zaw Htet on 2020-02-04.
//

#ifndef XMWAYLOON_ROOT_RANDOMIZER_H
#define XMWAYLOON_ROOT_RANDOMIZER_H


namespace XMwayLoon::Randomizer {


    template <class T>
    class RootRandomizer {

    public:

        T objType;

        virtual void getRandom() = 0;
    };

}

#endif //XMWAYLOON_ROOT_RANDOMIZER_H
