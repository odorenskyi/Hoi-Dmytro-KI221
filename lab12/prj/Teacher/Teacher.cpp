#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <windows.h>
#include "..\ModulesHoi.h"

using namespace std;

bool fileLocation();

int main()
{
    SetConsoleOutputCP(1251);

    if (!fileLocation())
        return 0;
    else
    {
        ClassLab12_Hoi table;

        ifstream TestCases("../TestSuite/TestCases.txt");
        ofstream TestResult("../TestSuite/TestResult.txt");

        if (TestCases.is_open() && TestResult.is_open())
        {
            string line;
            float number;
            vector<float> Numbers;
            unsigned short int counter = 1;

            while (getline(TestCases, line, '\n'))
            {
                istringstream buffer(line);

                while (buffer >> number)
                    Numbers.push_back(number);

                if (table.changeLenA(Numbers[0]) && table.changeLenB(Numbers[1]))
                {
                    TestResult << "Test Suite " << to_string(counter) << "\nДовжина великої піввісі = " << to_string(table.getLenA())
                    << "\tДовжина малої піввіс = " << to_string(table.getLenB()) << "\nResult = " << to_string(table.getS()) << "\n\n";
                }
                else
                {
                    TestResult << "Test Suite " << to_string(counter) << "\nНекоректне значення!\n\n";
                }

                Numbers.clear();
                counter++;
            }

            TestCases.close();
            TestResult.close();

            cout << "Тестування успішно виконано.";
            cin.get();

            return 0;
        }
        else
        {
            cout << "Не вдалося відкрити файли.";
            cin.get();

            return 0;
        }
    }
}

bool fileLocation()
{
    string file = __FILE__;

    size_t check = file.find("Git BMTP\\Hoi-Dmytro-KI221\\lab12\\prj");

    if (check == string::npos)
    {
        ofstream fileResult("../../TestSuite/TestResult.txt");

        fileResult << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";

        for (int i = 0; i < 100; i++)
        {
            cout << "\a";
        }

        fileResult.close();

        return false;
    }
    else
        return true;
}
