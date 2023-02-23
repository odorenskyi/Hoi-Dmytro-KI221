#include <Windows.h>
#include <iostream>
#include <stack>

#include "..\Modules\ModulesHoi.h"

using namespace std;

void information();
bool inequality(int a, int b);
void convertTo16(int []);

int main()
{
    system("chcp 1251");
    system("cls");

    information();

    int a, b;
    cout << "\nВведіть числа a, b: ";
    cin >> a >> b;
    cout << "\nРезультат(1 - вірно, 0 - невірно) логічного виразу a + 10 >= b: " << (int)inequality(a, b) << ".\n";

    int values [3];
    cout << "\nВведіть числа x, y, z: ";
    cin >> values[0] >> values[1]  >> values[2];

    cout << "\n";
    convertTo16(values);

    cout << "\nS = " << s_calculation(values) << ".\n";

    system("pause");
    return 0;
}

void information()
{
    cout << "==================================================================================================================|\n";
    cout << "Розробник ПЗ: Гой Дмитро Олександрович; ЗВО: Центральноукраїнський національний технічний університет; Рік: 2023.©|\n";
    cout << "==================================================================================================================|\n";
}

bool inequality(int a, int b)
{
    return a + 10 >= b;
}

void convertTo16(int values[])
{
    stack <char> stack;
    string strings[3];
    char letters[3] = {'x', 'y', 'z'};
    int index, num = 0;
    int memory[3];

    for (index = 0; index < size(memory); index++)
    {
        num = values[index];
        memory[index] = num;
        num = 0;
    }

    for (index = 0; index < sizeof(values); index++)
    {
        while (values[index] >= 16)
        {
            num = values[index] % 16;
            values[index] /= 16;
            switch (num)
            {
                case 0:
                    stack.push('0');
                    break;
                case 1:
                    stack.push('1');
                    break;
                case 2:
                    stack.push('2');
                    break;
                case 3:
                    stack.push('3');
                    break;
                case 4:
                    stack.push('4');
                    break;
                case 5:
                    stack.push('5');
                    break;
                case 6:
                    stack.push('6');
                    break;
                case 7:
                    stack.push('7');
                    break;
                case 8:
                    stack.push('8');
                    break;
                case 9:
                    stack.push('9');
                    break;
                case 10:
                    stack.push('A');
                    break;
                case 11:
                    stack.push('B');
                    break;
                case 12:
                    stack.push('C');
                    break;
                case 13:
                    stack.push('D');
                    break;
                case 14:
                    stack.push('E');
                    break;
                case 15:
                    stack.push('F');
                    break;
            }
        }
        if (values[index] < 16)
        {
            switch (values[index])
            {
                case 0:
                    stack.push('0');
                    break;
                case 1:
                    stack.push('1');
                    break;
                case 2:
                    stack.push('2');
                    break;
                case 3:
                    stack.push('3');
                    break;
                case 4:
                    stack.push('4');
                    break;
                case 5:
                    stack.push('5');
                    break;
                case 6:
                    stack.push('6');
                    break;
                case 7:
                    stack.push('7');
                    break;
                case 8:
                    stack.push('8');
                    break;
                case 9:
                    stack.push('9');
                    break;
                case 10:
                    stack.push('A');
                    break;
                case 11:
                    stack.push('B');
                    break;
                case 12:
                    stack.push('C');
                    break;
                case 13:
                    stack.push('D');
                    break;
                case 14:
                    stack.push('E');
                    break;
                case 15:
                    stack.push('F');
                    break;
            }
        }
        while (!stack.empty())
        {
            strings[index].push_back(stack.top());
            stack.pop();
        }
    }

    for (index = 0; index < size(memory); index++)
    {
        cout << letters[index] << "(DEC) = "  << memory[index] << "; " << letters[index] << "(HEX) = " << strings[index] << ".\n";
    }
}
