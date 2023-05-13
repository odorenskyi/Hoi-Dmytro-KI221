#include <iostream>
#include <cmath>
#include <string>

using namespace std;

float s_calculation(int values[])
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

    float Сelsius = 0;
    float Fahrenheit;

    for(int i = 0; i < days; i++)
        Сelsius += temperatures[i];

    Сelsius /= days;
    Fahrenheit = (1.8 * Сelsius) + 32;

    result = "Середньомісячна температура у Цельсіях: " + to_string(Сelsius) + ". Середньомісячна температура у Фаренгейтах: " + to_string(Fahrenheit);
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
