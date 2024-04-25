#include <iostream>
#include <cmath>

double cosinusa(double a)
{
    return cos(a) - a;
}

double cosinusb(double a)
{
    return cos(a) - 0.5;
}

double root(double (*f)(double), double a, double b, double tolerance = 1e-10)
{
double x1;

while(std::abs(a - b) > tolerance)
{
    x1 = (a + b) / 2;

    if(std::abs(f(x1)) <= tolerance)
        break;

    else if(f(x1) * f(a) < 0)
        b = x1;
    else
        a = x1;
}

return ((a + b) / 2);
}

int main()
{
    // 1

    double a = 0;
    double b = 2;

    std::cout << root(cosinusa,a,b) << "\n";

    // 2

    a = 0;
    b = 1.5;
    std::cout << root(cosinusb,a,b);


    return 0;
}
