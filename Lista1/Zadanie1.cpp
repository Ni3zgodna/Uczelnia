#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n = 1000000, s = 0;

    //a
    
    s = 0;

    for(int j = 1 ; j <= n; j++)
    {
        s+= (pow((-1), j + 1)) / (2*j - 1);
    }

    cout << 4 * s << "\n";
    
    //b

    s = 1;

    for(int j = 1 ; j <= n; j++)
    {
        s*= (4 * pow(j,2)) / ((4 * pow(j,2)) - 1);
    }

    cout << 2 * s << "\n";

    s = 0;

    //c

    for(int j = 1; j <= n; j++)
    {
        s += 1 / (pow((2*j - 1), 2));
    }

    cout << sqrt(8 * s);

    return 0;
}
