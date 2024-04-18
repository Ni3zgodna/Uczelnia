#include <iostream>

struct Link
{
int value;
Link* next = nullptr;
};

void reverse(Link* poprzednia)
{
}

int main()
{
    Link var1, var2, var3, var4;

    var1.value = 1;
    var2.value = 2;
    var3.value = 5;
    var4.value = 9;

    var1.next = &var2;
    var2.next = &var3;
    var3.next = &var4;
    var4.next = nullptr;

    reverse(&var1);

    return 0;
}
