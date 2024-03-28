#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 1000000;
    double suma = 0;

    std::cout.precision(10);
    //a
    
    suma = 0;

    for(int j = 1 ; j <= n; j++)
    {
        suma += (pow((-1), j + 1)) / (2*j - 1);
    }

    cout << 4.0 * suma << "\n";
    
    //b

    suma = 1;

    for(int j = 1 ; j <= n; j++)
    {
        suma *= (4.0 * j * j) / (4.0 * j * j - 1.0);
    }

    cout << 2.0 * suma << "\n";

    suma = 0;

    //c

    for(int j = 1; j <= n; j++)
    {
        double tmp = 2.0 * j -1;
        suma += 1.0 / (tmp * tmp);
    }

    cout << sqrt(8.0 * suma) << "\n";

    return 0;
}
