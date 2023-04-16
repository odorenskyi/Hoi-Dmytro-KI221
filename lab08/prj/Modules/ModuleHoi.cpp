#include <iostream>
#include <cmath>

using namespace std;

float s_calculation(int values[])
{
    if(values[0] - values[1] != 0 && (2 * pow(values[1], 2)) != 0 && (values[0] + (values[2] /(2 * pow(values[1], 2)))) != 0 && (M_PI * pow(values[0], 2)) / (values[0] + (values[2] /(2 * pow(values[1], 2))) >= 0))
    {
        float S = log(values[0] - values[1]) + sqrt((M_PI * pow(values[0], 2)) / (values[0] + (values[2] /(2 * pow(values[1], 2)))));
        return S;
    }
}

void Beaufort_score(float speed)
{
    if(speed < 0.3)
        cout << "Бал Бофорта: 0. Відсутність вітру. Дим піднімається прямовисно. Листя дерев нерухомі.\n";
    if(0.3 <= speed <= 1.5)
        cout << "Бал Бофорта: 1. \"Дим пливе\". Флюгер не обертається.\n";
    if(1.6 <= speed <= 3.3)
        cout << "Бал Бофорта: 2. Рух повітря відчувається обличчям. Шелестить листя. Флюгер обертається.\n";
    if(3.4 <= speed <= 5.4)
        cout << "Бал Бофорта: 3. Тріпоче листя, хитаються дрібні гілки. Майорять прапори.\n";
    if(5.5 <= speed <= 7.9)
        cout << "Бал Бофорта: 4. Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу.\n";
    if(8.0 <= speed <= 10.7)
        cout << "Бал Бофорта: 5. Хитаються великі гілки. На воді з'являються хвилі\n";
    if(10.8 <= speed <= 13.8)
        cout << "Бал Бофорта: 6. Хитаються великі гілки.\n";
    if(13.9 <= speed <= 17.1)
        cout << "Бал Бофорта: 7. Хитаються невеликі стовбури дерев.На морі здіймаються хвилі, піняться.";
    if(17.2 <= speed <= 20.7)
        cout << "Бал Бофорта: 8. Ламаються гілки дерев. Важко йти проти вітру.\n";
    if(20.8 <= speed <= 24.4)
        cout << "Бал Бофорта: 9. Невеликі руйнування. Зриває покрівлі, руйнує димарі.\n";
    if(24.5 <= speed <= 28.4)
        cout << "Бал Бофорта: 10. Значні руйнування. Дерева вириваються з корінням.\n";
    if(28.5 <= speed <= 32.6)
        cout << "Бал Бофорта: 11. Великі руйнування.\n";
    if(32.7 <= speed)
        cout << "Бал Бофорта: 12. Призводить до спустошень.\n";
}

void average_temperature(float *temperatures)
{
    if(sizeof(temperatures) == 0)
        cout << "Помилка. Немає даних для обробки.\n";
    else
    {
        float Сelsius = 0;
        float Fahrenheit;

        for(int i = 0; i < sizeof(temperatures); i++)
        {
            Сelsius += temperatures[i];
        }

        Сelsius /= sizeof(temperatures);
        Fahrenheit = ((9/5) * Сelsius) + 32;

        cout << "Середньомісячна температура у Цельсіях: " << Сelsius << ". Середньомісячна температура у Фаренгейтах: " << Fahrenheit << ".\n";
    }
}

void amount_binary_digits(int N)
{
    if(N < 0 || N > 10008000)
        cout << "Помилка. Некоректне значення.\n";
    else
    {
        int bit = (N >> 14) & 1;
        int amount = 0;

        if(bit == 1)
        {
            while((N & 1) == 0)
            {
                amount++;
                N >>= 1;
            }

            cout << "Кількість двійкових нулів: " << amount << "\n";
        }
        else
        {
            while (N != 0)
            {
                if (N & 1)
                    amount++;
                N >>= 1;
            }
            cout << "Кількість двійкових одиниць: " << amount << "\n";
        }
    }
}
