#include "pch.h"
#include "Boat.h"
#include "Combi.h"

namespace boatfnc
{
    bool checkWeights(combi::accomodation& s, const int minv[], const int maxv[], const int v[])
    {
        int i = 0;
        while (i < s.m && v[s.ntx(i)] <= maxv[i] && v[s.ntx(i)] >= minv[i])
            i++;
        return (i == s.m);
    }

    int calcProfit(combi::accomodation& s, const int c[])
    {
        int rc = 0;
        for (int i = 0; i < s.m; i++)
            rc += c[s.ntx(i)];
        return rc;
    }

    void copyResult(short m, short* r1, const short* r2)
    {
        for (int i = 0; i < m; i++)
            r1[i] = r2[i];
    }
}

int boat_centering(
    short m,
    int minv[],
    int maxv[],
    short n,
    const int v[],
    const int c[],
    short r[]
)
{
    combi::accomodation acc(n, m);
    int maxProfit = 0;
    int currentProfit = 0;
    short state = acc.getfirst();

    while (state > 0)
    {
        if (boatfnc::checkWeights(acc, minv, maxv, v))
        {
            currentProfit = boatfnc::calcProfit(acc, c);
            if (currentProfit > maxProfit)
            {
                maxProfit = currentProfit;
                boatfnc::copyResult(m, r, acc.sset);
            }
        }
        state = acc.getnext();
    }

    return maxProfit;
}