#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    const int N = 5, INF = 1e8;
    int D[N][N] = {
        {INF, 12,  31, 15,  10},
        {13,   INF, 24, 28, 56},
        {19,  24,   INF, 72, 49},
        {40,  43,  36,   INF, 24},
        {73,  44,  45,  24,  INF}
    };

    vector<int> p(N - 1);
    iota(p.begin(), p.end(), 1);

    int min_c = INF;
    vector<int> best;

    do {
        int c = D[0][p[0]] + D[p.back()][0];
        for (int i = 0; i < N - 2; ++i) c += D[p[i]][p[i + 1]];

        cout << "1";
        for (int x : p) cout << " -> " << x + 1;
        cout << " -> 1  cost = " << c << endl;

        if (c < min_c) { min_c = c; best = p; }

    } while (next_permutation(p.begin(), p.end()));

    cout << "\nBest route: 1";
    for (int x : best) cout << " -> " << x + 1;
    cout << " -> 1\nMin cost = " << min_c << endl;

    return 0;
}