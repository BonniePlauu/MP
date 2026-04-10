#pragma once

namespace auxil
{
    void start();               // инициализация генератора случайных чисел
    double dget(double, double); // случайное число в диапазоне [a, b]
    int iget(int, int);         // случайное целое в диапазоне [a, b]
}