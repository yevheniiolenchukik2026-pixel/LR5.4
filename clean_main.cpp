#include <iostream>
#include <iomanip>

using namespace std;

const int B = 16;

double F(const int i, const int N)
{
    return 1.0 * i * N / (1.0 * i * i + 1.0 * N * N);
}

double P0(const int N)
{
    double p;
    int i;
    p = 1;
    for (i = N; i <= B; i++)
        p = p * F(i, N);
    return p;
}

double P1(const int N, const int i, double t)
{
    t = t * F(i, N);
    if (i <= N)
        return t;
    else
        return P1(N, i - 1, t);
}

double P2(const int N, const int i, double t)
{
    t = t * F(i, N);
    if (i >= B)
        return t;
    else
        return P2(N, i + 1, t);
}

double P3(const int N, const int i)
{
    if (i < N)
        return 1;
    else
        return F(i, N) * P3(N, i - 1);
}

double P4(const int N, const int i)
{
    if (i > B)
        return 1;
    else
        return F(i, N) * P4(N, i + 1);
}

#ifndef UNIT_TEST
int main()
{
    int N;

    cout << "N = ";
    cin >> N;

    cout << setprecision(10);
    cout << "(iter)        P0 = " << P0(N) << endl;
    cout << "(down --)     P1 = " << P1(N, B, 1) << endl;
    cout << "(down ++)     P2 = " << P2(N, N, 1) << endl;
    cout << "(up --)       P3 = " << P3(N, B) << endl;
    cout << "(up ++)       P4 = " << P4(N, N) << endl;

    return 0;
}
#endif
