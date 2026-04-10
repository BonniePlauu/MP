#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <iomanip>

using namespace std;

// 1. Рекурсивное решение
long long OptimalM_Rec(int i, int j, const vector<int>& p) {
    if (i == j) return 0;
    long long min_val = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long count = OptimalM_Rec(i, k, p) +
            OptimalM_Rec(k + 1, j, p) +
            (long long)p[i - 1] * p[k] * p[j];
        if (count < min_val) min_val = count;
    }
    return min_val;
}

// 2. Динамическое программирование
long long OptimalM_DP(int n, const vector<int>& p, vector<vector<int>>& s) {
    vector<vector<long long>> m(n + 1, vector<long long>(n + 1, 0));
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = LLONG_MAX;
            for (int k = i; k <= j - 1; k++) {
                long long q = m[i][k] + m[k + 1][j] + (long long)p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> p = { 10, 11, 29, 42, 19, 30, 20 };
    int n = p.size() - 1;

    cout << "Размерности матриц: ";
    for (int i = 0; i < n; i++) cout << "(" << p[i] << "x" << p[i + 1] << ") ";
    cout << endl << endl;

    auto startRec = chrono::high_resolution_clock::now();
    long long resRec = OptimalM_Rec(1, n, p);
    auto endRec = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedRec = endRec - startRec;

    cout << "--- Рекурсивное решение ---" << endl;
    cout << "Минимальное кол-во операций: " << resRec << endl;
    cout << "Время выполнения: " << fixed << setprecision(6) << elapsedRec.count() << " сек" << endl << endl;

    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    auto startDP = chrono::high_resolution_clock::now();
    long long resDP = OptimalM_DP(n, p, s);
    auto endDP = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedDP = endDP - startDP;

    cout << "--- Динамическое программирование ---" << endl;
    cout << "Минимальное кол-во операций: " << resDP << endl;
    cout << "Время выполнения: " << fixed << setprecision(6) << elapsedDP.count() << " сек" << endl << endl;

    cout << "Матрица S (индексы разбиения):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(3) << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}