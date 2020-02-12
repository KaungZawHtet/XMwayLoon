//
// Created by Kaung Zaw Htet on 2020-02-04.
//

#ifndef XMWAYLOON_ROOT_RANDOMIZER_H
#define XMWAYLOON_ROOT_RANDOMIZER_H

#include <randomizer/faster_random.h>
namespace XMwayLoon::Randomizer {



    class RootRandomizer {

    protected:
        pcg objPCG;

    public:



        virtual std::string getRandom() = 0;
        virtual void load() = 0;
    };

}

#endif //XMWAYLOON_ROOT_RANDOMIZER_H
