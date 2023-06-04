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
        return "Бал Бофорта: 0. Відсутність вітру. Дим піднімається прямовисно. Листя дерев нерухомі.";
    if(speed >= 0.3 && speed <= 1.5)
        return "Бал Бофорта: 1. \"Дим пливе\". Флюгер не обертається.";
    if(speed >= 1.6 && speed <= 3.3)
        return "Бал Бофорта: 2. Рух повітря відчувається обличчям. Шелестить листя. Флюгер обертається.";
    if(speed >= 3.4 && speed <= 5.4)
        return "Бал Бофорта: 3. Тріпоче листя, хитаються дрібні гілки. Майорять прапори.";
    if(speed >= 5.5 && speed <= 7.9)
        return "Бал Бофорта: 4. Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу.";
    if(speed >= 8.0 && speed <= 10.7)
        return "Бал Бофорта: 5. Хитаються великі гілки. На воді з'являються хвилі.";
    if(speed >= 10.8 && speed <= 13.8)
        return "Бал Бофорта: 6. Хитаються великі гілки.";
    if(speed >= 13.9 && speed <= 17.1)
        return "Бал Бофорта: 7. Хитаються невеликі стовбури дерев.На морі здіймаються хвилі, піняться.";
    if(speed >= 17.2 && speed <= 20.7)
        return "Бал Бофорта: 8. Ламаються гілки дерев. Важко йти проти вітру.";
    if(speed >= 20.8 && speed <= 24.4)
        return "Бал Бофорта: 9. Невеликі руйнування. Зриває покрівлі, руйнує димарі.";
    if(speed >= 24.5 && speed <= 28.4)
        return "Бал Бофорта: 10. Значні руйнування. Дерева вириваються з корінням.";
    if(speed >= 28.5 && speed <= 32.6)
        return "Бал Бофорта: 11. Великі руйнування.";
    if(speed >= 32.7)
        return "Бал Бофорта: 12. Призводить до спустошень.";
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

    result = "Середньомісячна температура у Цельсіях: " + to_string(Celsius) + ". Середньомісячна температура у Фаренгейтах: " + to_string(Fahrenheit);
    return result;
}

string amount_binary_digits(int N)
{
    string result = "";

    if(N < 0 || N > 10008000)
    {
        result = "Помилка. Некоректне значення.";
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

            result = "Кількість двійкових нулів: " + to_string(amount);
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

            result = "Кількість двійкових одиниць: " + to_string(amount);
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
            throw "Помилка: не вдалося відкрити вхідний файл.";

        ofstream file_output("Ofile.txt");

        if (!file_output.is_open())
            throw "Помилка: не вдалося відкрити вихідний файл.";

        file_output << "Розробник ПЗ: Гой Дмитро Олександрович; ЗВО: Центральноукраїнський національний технічний університет;";
        file_output << " Країна: Україна; Місто: Знам'янка; Рік: 2023.\n";

        string text = "";
        int amount_questions = 0, amount_exclamations = 0;
        bool sentences_with_vowels = false;

        getline(file_input, text);
        for(int i = 0; i < sizeof(text); i++)
        {
            switch(text[i])
            {
                case 'а':
                case 'А':
                case 'у':
                case 'У':
                case 'е':
                case 'Е':
                case 'й':
                case 'Й':
                case 'о':
                case 'О':
                case 'є':
                case 'Є':
                case 'и':
                case 'И':
                case 'я':
                case 'Я':
                case 'ю':
                case 'Ю':
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

        file_output << "\nКількість \"\?\": " << amount_questions << endl;
        file_output << "Кількість \"!\": " << amount_exclamations << "\n\n";

        if (!sentences_with_vowels)
            file_output << "Речення в якому немає голосних:\n\t\t" << text << endl;

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
            throw "Помилка: не вдалося відкрити файл.";

        string text = "";
        int i;

        getline(file_input, text);

        file_input.seekg(0, ios::end);

        file_input << endl;

        for (i = 0; i < size(text); i++)
        {
            switch(text[i])
            {
                case 'Й':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Y";
                    break;
                case 'й':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "y";
                    else
                    {
                        file_input << "i";
                    }
                    break;
                case 'Ц':
                    file_input << "Ts";
                    break;
                case 'ц':
                    file_input << "ts";
                    break;
                case 'У':
                    file_input << "U";
                    break;
                case 'у':
                    file_input << "u";
                    break;
                case 'К':
                    file_input << "K";
                    break;
                case 'к':
                    file_input << "k";
                    break;
                case 'Н':
                    file_input << "N";
                    break;
                case 'н':
                    file_input << "n";
                    break;
                case 'Г':
                    file_input << "H";
                    break;
                case 'г':
                    file_input << "h";
                    break;
                case 'Ґ':
                    file_input << "G";
                    break;
                case 'ґ':
                    file_input << "g";
                    break;
                case 'Ш':
                    file_input << "Sh";
                    break;
                case 'ш':
                    file_input << "sh";
                    break;
                case 'Щ':
                    file_input << "Shch";
                    break;
                case 'щ':
                    file_input << "shch";
                    break;
                case 'З':
                    if(text[i+1] == 'г')
                        file_input << "Zgh";
                    else
                    {
                        file_input << "Z";
                    }
                    break;
                case 'з':
                    if(text[i+1] == 'г')
                        file_input << "zgh";
                    else
                    {
                        file_input << "z";
                    }
                    break;
                case 'Х':
                    file_input << "Kh";
                    break;
                case 'х':
                    file_input << "kh";
                    break;
                case 'Ї':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Yi";
                    break;
                case 'ї':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "yi";
                    else
                    {
                        file_input << "i";
                    }
                    break;
                case 'Ф':
                    file_input << "F";
                    break;
                case 'ф':
                    file_input << "f";
                    break;
                case 'В':
                    file_input << "V";
                    break;
                case 'в':
                    file_input << "v";
                    break;
                case 'П':
                    file_input << "P";
                    break;
                case 'п':
                    file_input << "p";
                    break;
                case 'Р':
                    file_input << "R";
                    break;
                case 'р':
                    file_input << "r";
                    break;
                case 'Л':
                    file_input << "L";
                    break;
                case 'л':
                    file_input << "l";
                    break;
                case 'Д':
                    file_input << "D";
                    break;
                case 'д':
                    file_input << "d";
                    break;
                case 'Ж':
                    file_input << "Zh";
                    break;
                case 'ж':
                    file_input << "zh";
                    break;
                case 'Є':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Ye";
                    break;
                case 'є':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "ye";
                    else
                    {
                        file_input << "ie";
                    }
                    break;
                case 'Я':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Ya";
                    break;
                case 'я':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "ya";
                    else
                    {
                        file_input << "ia";
                    }
                    break;
                case 'Ч':
                    file_input << "Ch";
                    break;
                case 'ч':
                    file_input << "ch";
                    break;
                case 'С':
                    file_input << "S";
                    break;
                case 'с':
                    file_input << "s";
                    break;
                case 'м':
                    file_input << "m";
                    break;
                case 'И':
                    file_input << "Y";
                    break;
                case 'и':
                    file_input << "y";
                    break;
                case 'т':
                    file_input << "t";
                    break;
                case 'Б':
                    file_input << "B";
                    break;
                case 'б':
                    file_input << "b";
                    break;
                case 'Ю':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "Yu";
                    break;
                case 'ю':
                    if(text[i-1] == ' ' || i == 0)
                        file_input << "yu";
                    else
                    {
                        file_input << "iu";
                    }
                case '\`':
                    break;
                case 'Ь':
                    break;
                case 'ь':
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

        file_input << endl << "Час дозапису: " << asctime(timeinfo);

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
    file << "\nРезультат функції s_calculation: " << s_calculation(values) << endl << "Число b: " << b;

    int bin = 0, k = 1;

    while (b)
    {
        bin += (b % 2) * k;
        k *= 10;
        b /= 2;
    }
    file << "; Число b в двійковій системі: " << bin;

    file.close();
}
