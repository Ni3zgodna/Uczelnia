#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long double down(long double N)
{
    long double s = 0;

    for(int i = 1; i <= N; i++)
    {
        s += 1.0 / i;
    }

    return s;
}

long double up(long double N)
{
    long double s = 0;

    for(int i = N; i > 0; i--)
    {
        s += 1.0 / i;
    }

    return s;
}

int main()
{
    long double N;

    N = 100;

    cout << down(N) << " " << up(N) << " " << up(N) - down(N) << "\n";

    N = 100000;

    cout << down(N) << " " << up(N) << " " << up(N) - down(N) << "\n";

    N = 100000000;

    cout << down(N) << " " << up(N) << " " << up(N) - down(N) << "\n";


    return 0;
}