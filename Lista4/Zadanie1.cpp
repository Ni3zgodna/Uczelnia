#include <iostream>
#include <vector>

double operator *(std::vector<double> & v, std::vector<double> & w)
{
    return v[0]*w[0] + v[1]*w[1];
}
int main()
{
    std::vector<double> v;
    std::vector<double> w;

    v.push_back( 2 );
    v.push_back( 3 );

    w.push_back( 2 );
    w.push_back( 4 );

    std::cout << v * w << "\n";

    return 0;
}
