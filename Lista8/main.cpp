#include <iostream>
#include <vector>
#include <complex>
#include "timer.h"

template <typename T>
std::ostream& operator<<(std::ostream& wyjscie, const std::vector<T>& wektor) {

    wyjscie << "[";

    for (int i = 0; i < wektor.size(); i++) {
        wyjscie << wektor[i];
        if (i != wektor.size() - 1) {
            wyjscie << ", ";
        }
    }

    wyjscie << "]";

    return wyjscie;
}

int silnia(int n)
{
    if (n == 0)
        return 1;
    return n * silnia(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    std::vector<int> wek_1 = {5, 82, 35};
    std::cout << wek_1 << "\n";


    std::vector<double> wek_2 = {1.7, 6.1, 3.4};
    std::cout << wek_2 << "\n";


    std::vector<std::complex<double>> wek_3 = {{1.7, 6.1}, {3.4, 4.0}, {5.2, 10.8}};
    std::cout << wek_3 << "\n";

    Timer timer;
    timer.start();

    for (int i = 30; i >= 0; i--)
        std::cout << i << "! = " << silnia(i) << "\n";

    for (int i = 0; i <= 35; i++)
        std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << std::endl;

    std::cout << "Koniec programu\n";
    std::cout << timer.get_elapsed_seconds() << std::endl;
}
