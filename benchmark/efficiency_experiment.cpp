//
// Created by Kaung Zaw Htet on 2019-10-24.
//


#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>


#define STR_ARRAY  "hello","world","this","is","so","good", "because","this","is","micro","benchmark","things"
typedef std::vector<std::string> vecStr;
typedef vecStr* ptrVecStr;

vecStr moveEntireRvale()
{
    std::vector<std::string> str {
            STR_ARRAY
    };
    return str;
}

ptrVecStr moveOnlyAddress()
{
    auto* str = new vecStr{
            STR_ARRAY
    };

    return str;
}

std::unique_ptr<vecStr> moveUniquePtr()
{
    std::vector<std::string> str {
            STR_ARRAY
    };

    return std::make_unique<std::vector<std::string>>(str);

}


static void BM_MoveEntireObject(benchmark::State& state) {
    vecStr receiver;

    for (auto _ : state)
    {
         receiver=moveEntireRvale();


    }

}

BENCHMARK(BM_MoveEntireObject);

static void BM_MovePointerWithoutDelete(benchmark::State& state) {
    vecStr* receiver;

    for (auto _ : state)
    {
         receiver=moveOnlyAddress();

    }
    delete receiver;
}

BENCHMARK(BM_MovePointerWithoutDelete);

static void BM_MovePointerWithDelete(benchmark::State& state) {
    vecStr* receiver;

    for (auto _ : state)
    {
        receiver=moveOnlyAddress();
        delete receiver;
    }
}
BENCHMARK(BM_MovePointerWithDelete);


static void BM_MoveUnique(benchmark::State& state) {

    for (auto _ : state)
    {
      std::unique_ptr<vecStr> receiver = moveUniquePtr();
    }
}
BENCHMARK(BM_MoveUnique);




void passValue(const std::string name){}
static void BM_PASSVALUE(benchmark::State& state) {

    for (auto _ : state)
    {
        passValue("Kaung");
    }
}
BENCHMARK(BM_PASSVALUE);





void passRef(std::string &name){}
static void BM_PASSREF(benchmark::State& state) {

    for (auto _ : state)
    {
        std::string name {"Kaung"};
        passRef(name);
    }
}
BENCHMARK(BM_PASSREF);





BENCHMARK_MAIN();

