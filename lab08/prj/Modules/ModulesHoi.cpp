#include <iostream>
#include <cmath>

using namespace std;

float s_calculation(int values[])
{
    float S = log(values[0] - values[1]) + sqrt((M_PI * pow(values[0], 2)) / (values[0] + (values[2] /(2 * pow(values[1], 2)))));
    return S;
}
