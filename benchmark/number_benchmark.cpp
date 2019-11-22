//
// Created by Kaung Zaw Htet on 2019-11-21.
//


#include <benchmark/benchmark.h>
#include "../lib/ShinMwayLoon/include/number.h"

static void create_BM(benchmark::State& state) {


    for (auto _ : state)
    {
        Xlotgative::ShinMwayLoon::Number obj_Number;


    }
}

BENCHMARK(create_BM);

BENCHMARK_MAIN();