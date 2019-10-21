//
// Created by Kaung Zaw Htet on 2019-10-22.
//

#include <benchmark/benchmark.h>
#include "../lib/ShinMwayLoon/include/english_date.h"

static void BM_EnglishDateCreation(benchmark::State& state) {
    for (auto _ : state)
    {

        Xlotgative::ShinMwayLoon::EnglishDate obj_EnglishDate;
        Xlotgative::ShinMwayLoon::ptr_string ptr= obj_EnglishDate.getRandomMyanDate("%d-%m-%Y",Xlotgative::ShinMwayLoon::Encoding::Random);



    }
}
// Register the function as a benchmark
BENCHMARK(BM_EnglishDateCreation);



BENCHMARK_MAIN();

