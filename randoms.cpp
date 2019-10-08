#include <iostream>
#include <random>
#include "randoms.h"
using namespace std;

static default_random_engine generator(time(0));

int intRandom(int min, int max) {
    uniform_int_distribution<unsigned> distribution(min, max);

    return distribution(generator);
}

double doubleRandom(double mean, double stddev) {
    normal_distribution<double> distribution(mean, stddev);

    return distribution(generator);
}
