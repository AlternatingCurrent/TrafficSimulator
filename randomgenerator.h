#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H
#include <QTimer>
#include "qmath.h"
#include <functional>
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
class RandomGenerator
{
public:
    RandomGenerator();
    int createRandomNumber(int start, int end);
    ~RandomGenerator();
private:
    mt19937::result_type seed;
};

#endif // RANDOMGENERATOR_H
