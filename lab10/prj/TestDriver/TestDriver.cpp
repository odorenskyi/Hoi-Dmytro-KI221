#include <iostream>
#include <string>
#include "..\..\..\lab08\prj\Modules\ModulesHoi.h"

using namespace std;

int main()
{

    string f_input_10_1[2] =
    {
        "file_input_1(1).txt",
        "file_input_1(2).txt"
    };

    string f_input_10_2[2] =
    {
        "file_input_2(1).txt",
        "file_input_2(2).txt"
    };


    int f_input_10_3[4][4] = {
        {1, 1, 1, 1},
        {2, 1, 3, 4},
        {5, 2, 11, 16},
        {3, 2, 5, 25},
    };


    for(int i = 0; i < size(f_input_10_3); i++)
    {
        if (i < size(f_input_10_1))
            task_10_1(f_input_10_1[i]);

        if (i < size(f_input_10_2))
            task_10_2(f_input_10_2[i]);

        task_10_3(f_input_10_3[i][0], f_input_10_3[i][1], f_input_10_3[i][2], f_input_10_3[i][3]);

        cout << "Натисніть Enter, щоб перейти к іншому випадку: ";
        cin.get();
    }

    return 0;
}
