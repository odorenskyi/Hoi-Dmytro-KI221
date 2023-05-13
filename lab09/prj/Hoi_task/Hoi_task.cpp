#include <iostream>
#include <windows.h>
#include "..\..\..\lab08\prj\Modules\ModulesHoi.h"

using namespace std;

int main()
{
    SetConsoleCP(65001); SetConsoleOutputCP(65001);

    bool status = true;
    char func;

    while (status)
    {
        cout << "Введіть \'7\' для того щоб викликати функцію s_calculation, \'5\' для виклику функції задачі 9.1, \'4\' для виклику функції задачі 9.2";
        cout << ", \'3\' для виклику функції задачі 9.3: ";

        cin >> func;
        while(func != '7' && func != '5' && func != '4' && func != '3')
        {
            cout << "\a";
            cin >> func;
        }

        switch(func)
        {
            case '7':
            {
                int values [3];

                cout << "\nВведіть числа x, y, z: ";
                cin >> values[0] >> values[1]  >> values[2];

                cout << "\nS = " << s_calculation(values) << ".\n\n";
                break;
            }
            case '5':
            {
                float speed;

                cout << "\nВведіть швидкість вітру: ";
                cin >> speed;

                cout << Beaufort_score(speed) << endl << endl;
                break;
            }
            case '4':
            {
                int days;

                cout << "\nВведіть кількість днів у місяці: ";
                cin >> days;

                float temperatures[days];

                cout << "\nВведіть температуру за кожен день через \"Enter\": ";
                for (int i = 0; i < days; i++)
                {
                    cin >> temperatures[i];
                }

                cout << average_temperature(temperatures, days) << endl << endl;
                break;
            }
            case '3':
            {
                int N;

                cout << "\nВведіть ціле число від 0 до 10008000 включно: ";
                cin >> N;

                cout << amount_binary_digits(N) << endl << endl;
                break;
            }
        }

        char choice;

        cout << "Введіть \"t\", \"T\", \"С\" щоб завершити роботу, або будь-яку іншу букву щоб почати знову: ";
        cin >> choice;

        if(choice == 't' || choice == 'T' || choice == 'C')
        {
            status = false;
        }
        else {cout << endl;}
    }
}
