//
// Created by Kaung Zaw Htet on 2020-02-14.
//

#include <gtest/gtest.h>
#include <taskflow/taskflow.hpp>


TEST(ParallelTest,increment)
{

    tf::Executor executor;
    tf::Taskflow taskflow;
    int a=0;

    taskflow.emplace(
            [&] () {
                ++a;
                std::cerr << "TaskA : "<<a;
                std::cerr<<"\n";

            std::cerr<<"\n";
            },
            [&] () {
                ++a;
                std::cerr << "TaskB : "<<a;
                std::cerr<<"\n";
            },
            [&] () {
                ++a;
                std::cerr << "TaskC : "<<a;
                std::cerr<<"\n";
            },
            [&] () {
                ++a;
                std::cerr << "TaskD : "<<a;
                std::cerr<<"\n";
            },
    [&] () {
        ++a;
        std::cerr << "TaskE : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskF : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskG : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskH : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskI : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskJ : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskK : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskL : "<<a;
        std::cerr<<"\n";
    },
    [&] () {
        ++a;
        std::cerr << "TaskM : "<<a;
        std::cerr<<"\n";
    }
    );


    executor.run(taskflow).wait();

    std::cerr<< a;


}



TEST(ParallelTest,vec)
{

    tf::Executor executor;
    tf::Taskflow taskflow;
   std::vector<int> a ;

   a.reserve(13);
    tf::Task tkAdd = taskflow.emplace([&] (tf::Subflow& subflow) {

        subflow.emplace([&](){
            a.push_back(1);
        }).name("B1");

        subflow.emplace([&](){
            a.push_back(2);
        }).name("B2");

        subflow.emplace([&](){
            a.push_back(3);
        }).name("B3");

        subflow.emplace([&](){
            a.push_back(4);
        }).name("B4");

        subflow.emplace([&](){
            a.push_back(5);
        }).name("B5");

        subflow.emplace([&](){
            a.push_back(6);
        }).name("B6");

        subflow.emplace([&](){
            a.push_back(7);
        }).name("B7");

        subflow.emplace([&](){
            a.push_back(8);
        }).name("B8");

        subflow.emplace([&](){
            a.push_back(9);
        }).name("B9");

        subflow.emplace([&](){
            a.push_back(10);
        }).name("B10");

        subflow.emplace([&](){
            a.push_back(11);
        }).name("B11");

        subflow.emplace([&](){
            a.push_back(12);
        }).name("B12");

        subflow.emplace([&](){
            a.push_back(13);
        }).name("B13");


    }).name("add");

    tf::Task tkPrint = taskflow.emplace([&](){

        std::for_each(a.begin(),a.end(),[](auto element){
            std::cerr<< element << std::endl;
        });
    }).name("print");

    tkAdd.precede(tkPrint);







    executor.run(taskflow);





}