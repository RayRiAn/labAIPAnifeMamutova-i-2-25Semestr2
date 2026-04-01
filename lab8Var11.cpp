#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct item {
    int data;
    item* next;
};

item* Add(item* head, int value) {
    item* tmp = new item;
    tmp->data = value;
    tmp->next = head;
    return tmp;
}

void Print(item* head) {
    for (item* p = head; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

item* Split(item* head, int index, item*& second) {
    if (!head || index <= 0) {
        second = (index == 0) ? head : nullptr;
        return (index == 0) ? nullptr : head;
    }

    item* p = head;
    for (int i = 0; i < index - 1 && p->next; i++)
        p = p->next;

    second = p->next;
    p->next = nullptr;
    return head;
}

void Delete(item*& head) {
    while (head) {
        item* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    item* list = nullptr;
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        list = Add(list, rand() % 100 + 1);

    cout << "Список: ";
    Print(list);

    int index;
    cout << "Индекс для разделения: ";
    cin >> index;

    item* list2 = nullptr;
    item* list1 = Split(list, index, list2);

    cout << "Первая часть: ";
    Print(list1);
    cout << "Вторая часть: ";
    Print(list2);

    Delete(list1);
    Delete(list2);

    return 0;
}
