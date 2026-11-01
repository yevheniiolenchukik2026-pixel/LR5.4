#define UNIT_TEST
#include "clean_main.cpp"
#include <cmath>
#include <cassert>

int main()
{
    double expected, actual;
    int N;

    expected = 0.4;
    actual = F(2, 1);
    assert(fabs(expected - actual) < 1e-12);

    N = 16;
    expected = 0.5;
    assert(fabs(expected - P0(N)) < 1e-12);
    assert(fabs(expected - P1(N, 16, 1)) < 1e-12);
    assert(fabs(expected - P2(N, N, 1)) < 1e-12);
    assert(fabs(expected - P3(N, 16)) < 1e-12);
    assert(fabs(expected - P4(N, N)) < 1e-12);

    N = 15;
    expected = 0.5 * 240.0 / 481.0;
    assert(fabs(expected - P0(N)) < 1e-12);
    assert(fabs(expected - P1(N, 16, 1)) < 1e-12);
    assert(fabs(expected - P2(N, N, 1)) < 1e-12);
    assert(fabs(expected - P3(N, 16)) < 1e-12);
    assert(fabs(expected - P4(N, N)) < 1e-12);

    N = 5;
    actual = P0(N);
    assert(fabs(actual - P1(N, 16, 1)) < 1e-20);
    assert(fabs(actual - P2(N, N, 1)) < 1e-20);
    assert(fabs(actual - P3(N, 16)) < 1e-20);
    assert(fabs(actual - P4(N, N)) < 1e-20);

    cout << "Test F, P0, P1, P2, P3, P4: passed" << endl;
    return 0;
}
