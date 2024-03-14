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
    int s = * result;
    for(int i = 0; i < size; i++)
        s += tab[i];

    *result = s;
}

void pisz(const int* tab, size_t size, std::ostream *out)
{
    for(int i = 0; i < size; i++);
        // s += tab[i];
}


int main()
{
    const int tab[9] = {1,2,3,4,5,6,7,8,9};
    unsigned size = 5;

    //a

    std::cout << suma(tab, size) << " ";

    //b

    int s = 0;
    int* result;
    result = &s;

    suma2(tab, size, result);
    std::cout << s << " ";

    //c

    std::ostream * out;
    size_t size2 = 7;



    pisz(tab, size, out);

    return 0;
}
