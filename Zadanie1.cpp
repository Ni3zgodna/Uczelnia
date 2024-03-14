#include <iostream>

int suma(const int tab[], unsigned size)
{
    int s = 0;

    for(int i = 0; i < size; i++)
        s += tab[i];
    return s;
}

void suma2(const int tab[], unsigned size, int* result)
{
    for(int i = 0; i < size; i++)
        result += tab[i];
    std::cout << result << " ";
}

void pisz(const int* tab, size_t size, std::ostream * out)
{



}


int main()
{
    const int tab[9] = {1,2,3,4,5,6,7,8,9};
    unsigned size = 5;

    int s = 0;
    int* result;
    result = &s;

    size_t size2 = 7;
    std::ostream * out;

    std::cout << suma(tab, size) << " ";

    suma2(tab, size, result);

    std::cout << s << " ";

    // std::cout << pisz(tab, size, * out) << " ";

    return 0;
}
