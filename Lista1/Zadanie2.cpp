#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long double t;
    long double odpowiedzi[30];

    //a

    for(int i = 0; i <= 30; i++)
    {
        if(i == 0)
            t = 1.0 / sqrt(3);
        else
            t = (sqrt(pow(t,2)+1) - 1) / t;

        odpowiedzi[i] = 6 * pow(2,i) * t;
        cout << odpowiedzi[i] << "\n";
    }

    cout << "\n";

    //b

    for(int i = 0; i <= 30; i++)
    {
        if(i == 0)
            t = 1.0 / sqrt(3);
        else
            t = t / (sqrt(pow(t,2) + 1) + 1);

        odpowiedzi[i] = 6 * pow(2,i) * t;
        cout << odpowiedzi[i] << "\n";
    }


    return 0;
}