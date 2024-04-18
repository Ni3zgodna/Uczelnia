#include <iostream>

struct Link
{
int value;
Link* next = nullptr;
};

size_t size(const Link* head)
{
    int s = 0;

    while(head != nullptr)
    {
        s++;
        head = head->next;
    }

    return s;
}

size_t sum(const Link* head)
{
    int s = 0;

    while(head != nullptr)
    {
        s += head->value;
        head = head->next;
    }

    return s;
}

void release(Link** phead)
{
 Link* head = *phead;
 if(head->next != nullptr)
 {
    release(&head->next);
    delete head->next;
 }
 *phead = nullptr;
}

int main()
{
    Link var1, var2, var3;

    var1.value = 1;
    var2.value = 2;
    var3.value = 3;


    var1.next = &var2;
    var2.next = &var3;
    var3.next = nullptr;

    std::cout << size(&var1) << " ";
    std::cout << sum(&var1) << " ";

    // 2

    release(&var1.next);



    return 0;
}
