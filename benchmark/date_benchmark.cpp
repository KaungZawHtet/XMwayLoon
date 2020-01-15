//
// Created by Kaung Zaw Htet on 2019-11-20.
//


#include <benchmark/benchmark.h>
#include <randomizer/date_randomizer.h>

static void create_BM(benchmark::State& state) {


    for (auto _ : state)
    {
        XMwayLoon::Randomizer::Date obj_Date;


    }
}

BENCHMARK(create_BM);

static void processWhole_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::Date obj_Date;
    for (auto _ : state)
    {
        std::string str= obj_Date.getRandomMyanDate("%d-%B-%Y",XMwayLoon::Randomizer::Encoding::Random);

    }
}
//BENCHMARK(processWhole_BM);

static void convertEngDateToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::Date obj_Date;
    for (auto _ : state)
    {
        std::string str= obj_Date.convertEngDateToMyan("12 January 2018",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertEngDateToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

static void convertCompleteEngMonthToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::Date obj_Date;
    for (auto _ : state)
    {
        std::string str= obj_Date.convertCompleteEngMonthToMyan("January",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertCompleteEngMonthToMyan_BM);
//////////////////////////////////////////////////////////////////////////////////////////////////


static void convertShortEngMonthToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::Date obj_Date;
    for (auto _ : state)
    {
        std::string str= obj_Date.convertShortEngMonthToMyan("Jan",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertShortEngMonthToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

// TODO: problem with benchmarking
static void generateRandomEngDate_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::Date obj_Date;
    for (auto _ : state)
    {
        std::string str= obj_Date.generateRandomEngDate("%d-%B-%Y");

    }
}
//BENCHMARK(generateRandomEngDate_BM);


//////////////////////////////////////////////////////////////////////////////////////////////////

BENCHMARK_MAIN();

