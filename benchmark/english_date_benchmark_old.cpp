//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <benchmark/benchmark.h>
#include <randomizer/english_date_old.h>

static void create_BM(benchmark::State& state) {


    for (auto _ : state)
    {
        XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;


    }
}

BENCHMARK(create_BM);

static void processWhole_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%B-%Y",XMwayLoon::Randomizer::Encoding::Random);

    }
}
//BENCHMARK(processWhole_BM);

static void convertEngDateToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.convertEngDateToMyan("12 January 2018",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertEngDateToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

static void convertCompleteEngMonthToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.convertCompleteEngMonthToMyan("January",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertCompleteEngMonthToMyan_BM);
//////////////////////////////////////////////////////////////////////////////////////////////////


static void convertShortEngMonthToMyan_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.convertShortEngMonthToMyan("Jan",XMwayLoon::Randomizer::Encoding::Random);

    }
}
BENCHMARK(convertShortEngMonthToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

// TODO: problem with benchmarking
static void generateRandomEngDate_BM(benchmark::State& state) {

    XMwayLoon::Randomizer::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        XMwayLoon::Randomizer::ptr_string ptr= obj_EnglishDate.generateRandomEngDate("%d-%B-%Y");

    }
}
//BENCHMARK(generateRandomEngDate_BM);


//////////////////////////////////////////////////////////////////////////////////////////////////

BENCHMARK_MAIN();

