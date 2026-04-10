#include "pch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Auxil.h"
#include "Boat.h"
#include "Combi.h"

void task5()
{
    std::cout << "\n========== ЗАДАНИЕ 5 ==========\n";

    int v[8], c[8];
    int minv[5], maxv[5];
    short r[5];

    auxil::start();

    for (int i = 0; i < 8; i++)
    {
        v[i] = auxil::iget(100, 200);
        c[i] = auxil::iget(10, 100);
    }

    for (int i = 0; i < 5; i++)
    {
        minv[i] = auxil::iget(50, 120);
        maxv[i] = auxil::iget(150, 850);
    }

    std::cout << "\nКонтейнеры:\n";
    for (int i = 0; i < 8; i++)
        std::cout << "  " << i << ": вес=" << v[i] << " доход=" << c[i] << "\n";

    std::cout << "\nОграничения:\n";
    for (int i = 0; i < 5; i++)
        std::cout << "  место " << i << ": мин=" << minv[i] << " макс=" << maxv[i] << "\n";

    clock_t t1 = clock();
    int profit = boat_centering(5, minv, maxv, 8, v, c, r);
    clock_t t2 = clock();

    std::cout << "\nРезультат: доход=" << profit << "\n";
    std::cout << "Выбраны контейнеры:";
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        std::cout << " " << r[i];
        sum += v[r[i]];
    }
    std::cout << "\nОбщий вес=" << sum << " кг";
    std::cout << "\nВремя=" << (t2 - t1) << " мс";
    std::cout << "\n";
}

void task6()
{
    std::cout << "\n========== ЗАДАНИЕ 6 ==========\n";

    int v[8], c[8];
    auxil::start();

    for (int i = 0; i < 8; i++)
    {
        v[i] = auxil::iget(100, 200);
        c[i] = auxil::iget(10, 100);
    }

    std::cout << "\n  m  время варианты\n";
    std::cout << "------------------\n";

    for (int m = 4; m <= 8; m++)
    {
        int minv[8], maxv[8];
        short r[8];

        for (int i = 0; i < m; i++)
        {
            minv[i] = auxil::iget(50, 120);
            maxv[i] = auxil::iget(150, 850);
        }

        unsigned long long cnt = 1;
        for (int i = 0; i < m; i++)
            cnt *= (8 - i);

        clock_t t1 = clock();
        int profit = boat_centering(m, minv, maxv, 8, v, c, r);
        clock_t t2 = clock();

        std::cout << "  " << m << "   " << (t2 - t1) << "    " << cnt << "\n";
    }
    std::cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    task5();
    task6();

    std::cout << "\nГотово. Нажмите Enter...";
    std::cin.get();
    return 0;
}