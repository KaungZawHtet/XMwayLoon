//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <benchmark/benchmark.h>
#include "../lib/ShinMwayLoon/include/english_date.h"

static void create_BM(benchmark::State& state) {


    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;


    }
}

BENCHMARK(create_BM);

static void processWhole_BM(benchmark::State& state) {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%B-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);

    }
}
//BENCHMARK(processWhole_BM);

static void convertEngDateToMyan_BM(benchmark::State& state) {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.convertEngDateToMyan("12 January 2018",Xlotgative::ShinMwayLoon::Encoding::Random);

    }
}
BENCHMARK(convertEngDateToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

static void convertCompleteEngMonthToMyan_BM(benchmark::State& state) {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.convertCompleteEngMonthToMyan("January",Xlotgative::ShinMwayLoon::Encoding::Random);

    }
}
BENCHMARK(convertCompleteEngMonthToMyan_BM);
//////////////////////////////////////////////////////////////////////////////////////////////////


static void convertShortEngMonthToMyan_BM(benchmark::State& state) {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.convertShortEngMonthToMyan("Jan",Xlotgative::ShinMwayLoon::Encoding::Random);

    }
}
BENCHMARK(convertShortEngMonthToMyan_BM);

//////////////////////////////////////////////////////////////////////////////////////////////////

// TODO: problem with benchmarking
static void generateRandomEngDate_BM(benchmark::State& state) {

    Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.generateRandomEngDate("%d-%B-%Y");

    }
}
//BENCHMARK(generateRandomEngDate_BM);


//////////////////////////////////////////////////////////////////////////////////////////////////

BENCHMARK_MAIN();

