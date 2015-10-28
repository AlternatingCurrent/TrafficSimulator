#include "randomgenerator.h"
#include <QTimer>
#include "qmath.h"
#include <functional>
#include <iostream>
#include <time.h>
#include <chrono>
#include <QDebug>
using namespace std;
RandomGenerator::RandomGenerator()
{

    seed = time(0);
}

int RandomGenerator::createRandomNumber(int start, int end)
{

    // mt19937 mt_rand(time(0));
    //mt19937::result_type seed = time(0);
    std::function<int()> randomNumber = std::bind(std::uniform_int_distribution<int>(start,end),
                                          mt19937(seed));
    qDebug()<< "result" << randomNumber() ;
    return randomNumber();

}

RandomGenerator::~RandomGenerator()
{

}

