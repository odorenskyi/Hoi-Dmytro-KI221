#include <iostream>
#include <cmath>



using namespace std;

int main()
{
    int TestValuesX[] = { 1, 2, 430, 1, -3, 12, 124, 15, 12, 10000 };
    int TestValuesY[] = { 1, 0, 398, 0, -5, 11, 100, 10004, 1011, 0 };
    int TestValuesZ[] = { 1, 3, 34, 4, -2, 12, 52, 528, 1, 1 };

    for (int i = 0; i < 10; i++)
    {
        float S = log(TestValuesX[i] - TestValuesY[i]) + sqrt((M_PI * pow(TestValuesX[i], 2)) / (TestValuesX[i] + (TestValuesZ[i] /(2 * pow(TestValuesY[i], 2)))));
        cout << S << "\n";
    }
}
