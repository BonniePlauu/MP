#include "pch.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include "Auxil.h"
#include "Boat.h"

#define SPACE(n) std::setw(n) << " "
#define MAX_M 8

int main()
{
    setlocale(LC_ALL, "rus");

    auxil::start();

    const short N = 8;
    int v[N], c[N];

    for (int i = 0; i < N; i++)
    {
        v[i] = auxil::iget(100, 200);
        c[i] = auxil::iget(10, 100);
    }

    int minv[MAX_M], maxv[MAX_M];
    short r[MAX_M];

    std::cout << std::endl << "=================================================";
    std::cout << std::endl << "   ИССЛЕДОВАНИЕ ВРЕМЕННОЙ ЗАВИСИМОСТИ";
    std::cout << std::endl << "=================================================";
    std::cout << std::endl << "- контейнеров (фиксировано): " << N;
    std::cout << std::endl << "\n   Мест | Время (мс) | Кол-во размещений";
    std::cout << std::endl << "   -----|------------|-------------------";

    clock_t t1, t2;

    for (int m = 4; m <= MAX_M; m++)
    {
        for (int i = 0; i < m; i++)
        {
            minv[i] = auxil::iget(50, 120);
            maxv[i] = auxil::iget(150, 850);
        }

        unsigned __int64 count = 1;
        for (int i = 0; i < m; i++)
            count *= (N - i);

        t1 = clock();
        int profit = boat_centering(m, minv, maxv, N, v, c, r);
        t2 = clock();

        std::cout << std::endl << "   " << std::setw(3) << m << " | "
            << std::setw(10) << (t2 - t1) << " | "
            << std::setw(17) << count;
    }

    std::cout << std::endl << "\n\n=== АНАЛИЗ РЕЗУЛЬТАТОВ ===";
    std::cout << std::endl << "При увеличении количества мест время растет экспоненциально,";
    std::cout << std::endl << "так как количество размещений A(8,m) = 8!/(8-m)!";

    std::cout << std::endl << "\n\nЗначения количества размещений:";
    std::cout << std::endl << "A(8,4) = 8*7*6*5 = 1680";
    std::cout << std::endl << "A(8,5) = 8*7*6*5*4 = 6720";
    std::cout << std::endl << "A(8,6) = 8*7*6*5*4*3 = 20160";
    std::cout << std::endl << "A(8,7) = 8*7*6*5*4*3*2 = 40320";
    std::cout << std::endl << "A(8,8) = 8*7*6*5*4*3*2*1 = 40320";

    std::cout << std::endl << "\nПрактические результаты подтверждают эту зависимость.";
    std::cout << std::endl << "=================================================";
    std::cout << std::endl;

    system("pause");
    return 0;
}