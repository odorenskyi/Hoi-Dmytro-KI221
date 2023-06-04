#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

float s_calculation(float values[])
{
    if(values[0] - values[1] != 0 && (2 * pow(values[1], 2)) != 0 && (values[0] + (values[2] /(2 * pow(values[1], 2)))) != 0 && (M_PI * pow(values[0], 2)) / (values[0] + (values[2] /(2 * pow(values[1], 2))) >= 0))
    {
        float S = log(values[0] - values[1]) + sqrt((M_PI * pow(values[0], 2)) / (values[0] + (values[2] /(2 * pow(values[1], 2)))));
        return S;
    }
}

string Beaufort_score(float speed)
{
    if(speed < 0.3)
        return "��� �������: 0. ³�������� ����. ��� ��������� ����������. ����� ����� �������.";
    if(speed >= 0.3 && speed <= 1.5)
        return "��� �������: 1. \"��� �����\". ������ �� ����������.";
    if(speed >= 1.6 && speed <= 3.3)
        return "��� �������: 2. ��� ������ ���������� ��������. ��������� �����. ������ ����������.";
    if(speed >= 3.4 && speed <= 5.4)
        return "��� �������: 3. ������ �����, ��������� ���� ����. �������� �������.";
    if(speed >= 5.5 && speed <= 7.9)
        return "��� �������: 4. ��������� ���� ���� �����. ³��� ����� ��� �� ������ ������.";
    if(speed >= 8.0 && speed <= 10.7)
        return "��� �������: 5. ��������� ����� ����. �� ��� �'��������� ����.";
    if(speed >= 10.8 && speed <= 13.8)
        return "��� �������: 6. ��������� ����� ����.";
    if(speed >= 13.9 && speed <= 17.1)
        return "��� �������: 7. ��������� ������� �������� �����.�� ��� ���������� ����, �������.";
    if(speed >= 17.2 && speed <= 20.7)
        return "��� �������: 8. ��������� ���� �����. ����� ��� ����� ����.";
    if(speed >= 20.8 && speed <= 24.4)
        return "��� �������: 9. ������� ����������. ����� ������, ����� �����.";
    if(speed >= 24.5 && speed <= 28.4)
        return "��� �������: 10. ����� ����������. ������ ����������� � �������.";
    if(speed >= 28.5 && speed <= 32.6)
        return "��� �������: 11. ����� ����������.";
    if(speed >= 32.7)
        return "��� �������: 12. ���������� �� ����������.";
}

string average_temperature(float temperatures[], int days)
{
    string result = "";

    float Celsius = 0;
    float Fahrenheit;

    for(int i = 0; i < days; i++)
        Celsius += temperatures[i];

    Celsius /= days;
    Fahrenheit = (1.8 * Celsius) + 32;

    result = "�������������� ����������� � �������: " + to_string(Celsius) + ". �������������� ����������� � �����������: " + to_string(Fahrenheit);
    return result;
}

string amount_binary_digits(int N)
{
    string result = "";

    if(N < 0 || N > 10008000)
    {
        result = "�������. ���������� ��������.";
        return result;
    }
    else
    {
        int bit = (N >> 13) & 1;
        int amount = 0;

        if(bit == 1)
        {
            while((N & 1) == 0)
            {
                amount++;
                N >>= 1;
            }

            result = "ʳ������ �������� ����: " + to_string(amount);
            return result;
        }
        else
        {
            while (N != 0)
            {
                if (N & 1)
                    amount++;
                N >>= 1;
            }

            result = "ʳ������ �������� �������: " + to_string(amount);
            return result;
        }
    }
}

void task_10_1(string file)
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);

    try
    {
        ifstream file_input(file);

        if (!file_input.is_open())
            throw "�������: �� ������� ������� ������� ����.";

        ofstream file_output("Ofile.txt");

        if (!file_output.is_open())
            throw "�������: �� ������� ������� �������� ����.";

        file_output << "��������� ��: ��� ������ �������������; ���: �������������������� ������������ �������� ����������;";
        file_output << " �����: ������; ̳���: ����'����; г�: 2023.\n";

        string text = "";
        int amount_questions = 0, amount_exclamations = 0;
        bool sentences_with_vowels = false;

        getline(file_input, text);
        for(int i = 0; i < sizeof(text); i++)
        {
            switch(text[i])
            {
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                case '�':
                    sentences_with_vowels = true;
                    break;
                case '\?':
                    amount_questions++;
                    break;
                case '\!':
                    amount_exclamations++;
                    break;
            }
        }

        file_output << "\nʳ������ \"\?\": " << amount_questions << endl;
        file_output << "ʳ������ \"!\": " << amount_exclamations << "\n\n";

        if (!sentences_with_vowels)
            file_output << "������� � ����� ���� ��������:\n\t\t" << text << endl;

        file_output.close();
        file_input.close();
    }
    catch(const char *error)
    {
        cout << error << endl;
    }
}

void task_10_2(string file)
{
    try
    {
        fstream file_input(file, ios_base::in | ios_base::app);

        if (!file_input.is_open())
            throw "�������: �� ������� ������� ����.";

        string text = "";
        int i;

        getline(file_input, text);

        file_input.seekg(0, ios::end);

        file_input << endl;

        for (i = 0; i < size(text); i++)
        {
            switch(text[i])
            {
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Y";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "y";
                    else
                    {
                        file_input << "i";
                    }
                    break;
                case '�':
                    file_input << "Ts";
                    break;
                case '�':
                    file_input << "ts";
                    break;
                case '�':
                    file_input << "U";
                    break;
                case '�':
                    file_input << "u";
                    break;
                case '�':
                    file_input << "K";
                    break;
                case '�':
                    file_input << "k";
                    break;
                case '�':
                    file_input << "N";
                    break;
                case '�':
                    file_input << "n";
                    break;
                case '�':
                    file_input << "H";
                    break;
                case '�':
                    file_input << "h";
                    break;
                case '�':
                    file_input << "G";
                    break;
                case '�':
                    file_input << "g";
                    break;
                case '�':
                    file_input << "Sh";
                    break;
                case '�':
                    file_input << "sh";
                    break;
                case '�':
                    file_input << "Shch";
                    break;
                case '�':
                    file_input << "shch";
                    break;
                case '�':
                    if(text[i+1] == '�')
                        file_input << "Zgh";
                    else
                    {
                        file_input << "Z";
                    }
                    break;
                case '�':
                    if(text[i+1] == '�')
                        file_input << "zgh";
                    else
                    {
                        file_input << "z";
                    }
                    break;
                case '�':
                    file_input << "Kh";
                    break;
                case '�':
                    file_input << "kh";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Yi";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "yi";
                    else
                    {
                        file_input << "i";
                    }
                    break;
                case '�':
                    file_input << "F";
                    break;
                case '�':
                    file_input << "f";
                    break;
                case '�':
                    file_input << "V";
                    break;
                case '�':
                    file_input << "v";
                    break;
                case '�':
                    file_input << "P";
                    break;
                case '�':
                    file_input << "p";
                    break;
                case '�':
                    file_input << "R";
                    break;
                case '�':
                    file_input << "r";
                    break;
                case '�':
                    file_input << "L";
                    break;
                case '�':
                    file_input << "l";
                    break;
                case '�':
                    file_input << "D";
                    break;
                case '�':
                    file_input << "d";
                    break;
                case '�':
                    file_input << "Zh";
                    break;
                case '�':
                    file_input << "zh";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Ye";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "ye";
                    else
                    {
                        file_input << "ie";
                    }
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Ya";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "ya";
                    else
                    {
                        file_input << "ia";
                    }
                    break;
                case '�':
                    file_input << "Ch";
                    break;
                case '�':
                    file_input << "ch";
                    break;
                case '�':
                    file_input << "S";
                    break;
                case '�':
                    file_input << "s";
                    break;
                case '�':
                    file_input << "m";
                    break;
                case '�':
                    file_input << "Y";
                    break;
                case '�':
                    file_input << "y";
                    break;
                case '�':
                    file_input << "t";
                    break;
                case '�':
                    file_input << "B";
                    break;
                case '�':
                    file_input << "b";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Yu";
                    break;
                case '�':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "yu";
                    else
                    {
                        file_input << "iu";
                    }
                case '\`':
                    break;
                case '�':
                    break;
                case '�':
                    break;
                default:
                    file_input << text[i];
                    break;
            }
        }

        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);

        file_input << endl << "��� ��������: " << asctime(timeinfo);

        file_input.close();
    }
    catch(const char *error)
    {
        cout << error << endl;
    }
}

void task_10_3(float x, float y, float z, int b)
{
    float values[3] = {x, y, z};

    fstream file("file.txt", ios_base::out | ios_base::app);
    file.seekg(0, ios::end);
    file << "\n��������� ������� s_calculation: " << s_calculation(values) << endl << "����� b: " << b;

    int bin = 0, k = 1;

    while (b)
    {
        bin += (b % 2) * k;
        k *= 10;
        b /= 2;
    }
    file << "; ����� b � ������� ������: " << bin;

    file.close();
}
