#include <iostream>
#include <cstdlib>

int Sortowanie(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if ((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
        return x - y;

    else if (x % 2 == 0 && y % 2 != 0)
        return -1;

    else
        return 1;

}

int main() {

    int tab[] = {1, 4, 7, 2, 5, 9, 2, 8};
    int n = sizeof(tab) / sizeof(tab[0]);

    std::qsort(tab, n, sizeof(int), Sortowanie);

    for (int i = 0; i < n; i++)
        std::cout << tab[i] << " ";

    return 0;
}
