#pragma once

namespace combi
{
    // Генератор подмножеств
    struct subset
    {
        short n;
        short sn;
        short* sset;
        unsigned __int64 mask;

        subset(short n = 1);
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 count();
        void reset();
    };

    // Генератор сочетаний
    struct xcombination
    {
        short n;
        short m;
        short* sset;
        unsigned __int64 nc;

        xcombination(short n = 1, short m = 1);
        void reset();
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 count() const;
    };

    // Генератор перестановок (алгоритм Джонсона-Троттера)
    struct permutation
    {
        const static bool L = true;
        const static bool R = false;

        short n;
        short* sset;
        bool* dart;
        unsigned __int64 np;

        permutation(short n = 1);
        void reset();
        __int64 getfirst();
        __int64 getnext();
        short ntx(short i);
        unsigned __int64 count() const;
    };

    // Генератор размещений
    struct accomodation
    {
        short n;
        short m;
        short* sset;
        xcombination* cgen;
        permutation* pgen;
        unsigned __int64 na;

        accomodation(short n = 1, short m = 1);
        void reset();
        short getfirst();
        short getnext();
        short ntx(short i);
        unsigned __int64 count() const;
    };
}