#include <iostream>

struct Link
{
int value;
Link* next = nullptr;
};

Link* reverse(Link* head) {
    Link* prev = nullptr;
    Link* current = head;
    Link* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void wyswietl(Link* head) {
    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    Link var1, var2, var3, var4;

    Link* head = &var1;

    var1.value = 1;
    var2.value = 2;
    var3.value = 5;
    var4.value = 9;

    var1.next = &var2;
    var2.next = &var3;
    var3.next = &var4;
    var4.next = nullptr;

    wyswietl(head);

    head = reverse(head);

    wyswietl(head);


    return 0;
}
