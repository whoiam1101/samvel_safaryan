#include "my_random.h"
#include <random>
#include <ctime>

std::mt19937 generator(time(nullptr));

int _myRandom(int a, int b) {
    return generator() % (b - a + 1) + a;
}