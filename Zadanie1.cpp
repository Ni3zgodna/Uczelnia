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
    *result = 0;
    for(int i = 0; i < size; i++)
        *result += tab[i];
}
void pisz(const int* tab, size_t size, std::ostream& out)
{
    for(size_t i = 0; i < size; i++)
        out << tab[i] << " ";
}

void iota(int tab[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
        tab[i] = i;
}

void reverse(int* tab, size_t size)
{
    int pomocnicza;

    for (size_t i = 0; i < size / 2; i++)
    {
        pomocnicza = tab[i];
        tab[i] = tab[size - i - 1];
        tab[size - i - 1] = pomocnicza;
    }
}

int iloczyn_skalarny(const int tab1[], const int tab2[], size_t size)
{
    int s = 0;
    for (size_t i = 0; i < size; i++)
        s += tab1[i] * tab2[i];

    return s;
}

int main()
{
    int tab[] = {1,2,3,4,5,6,7,8,9};
    unsigned size = sizeof(tab) / sizeof(tab[0]);


    //a

    std::cout << suma(tab, size) << "\n";


    //b

    int result;

    suma2(tab, size, &result);
    std::cout << result << "\n";


    //c

    pisz(tab, size, std::cout);
    std::cout << "\n";


    //d

    iota(tab, size);
    for (unsigned i = 0; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << "\n";


    //e

    reverse(tab, size);
    for (unsigned i = 0; i < size; i++)
        std::cout << tab[i] << " ";
    std::cout << "\n";


    //f

    int tab1[] = {1, 2};
    int tab2[] = {3, 4};
    unsigned size1 = sizeof(tab1) / sizeof(tab1[0]);

    std::cout << iloczyn_skalarny(tab1, tab2, size1);

    return 0;
}
