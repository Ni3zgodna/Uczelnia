#include <iostream>
#include <vector>
#include <string>

bool isOptimalMove(const std::vector<int>& piles) 
{
    int xorSum = 0;

    for (int pile : piles) 
    {
        xorSum ^= pile;
    }

    return xorSum != 0;
}

void makeOptimalMove(std::vector<int>& piles) 
{
    int xorSum = 0;
    for (int pile : piles) 
    {
        xorSum ^= pile;
    }

    for (size_t i = 0; i < piles.size(); ++i) 
    {
        int xorResult = piles[i] ^ xorSum;
        if (xorResult < piles[i]) 
        {
            int stonesToRemove = piles[i] - xorResult;
            std::cout << "z rzędu nr " << (i + 1) << " zabierz " << stonesToRemove << " kamienie\n";
            piles[i] = xorResult;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    
    if (argc < 2 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") 
    {
        std::cout << "Program pomaga wygrać w grę nim.\n" << "składnia:\n"<< "nim liczba_1 liczba_2 ...\n" << "gdzie liczba_1,... to liczby kamieni w kolejnych rzędach\n";
        return 0;
    }

    std::vector<int> piles;

    for (int i = 1; i < argc; ++i) 
    {
        piles.push_back(std::stoi(argv[i])); 
    }

    if (isOptimalMove(piles)) 
    {
        makeOptimalMove(piles);
    } 
    else 
    {
        std::cout << "rób co chcesz, strategia wygrywająca nie istnieje\n";
    }

    return 0;
}