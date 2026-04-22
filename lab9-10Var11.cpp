#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct list {
    int field;
    struct list* next;
    struct list* prev;
};

struct list* create_node(int val) {
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->field = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct list* push_back(struct list* root, int val) {
    struct list* node = create_node(val);
    if (root == NULL) return node;

    struct list* p = root;
    while (p->next != NULL) p = p->next;
    p->next = node;
    node->prev = p;
    return root;
}

struct list* copy_list_func(struct list* root) {
    if (root == NULL) return NULL;

    struct list* new_root = NULL;
    struct list* p = root;

    while (p != NULL) {
        new_root = push_back(new_root, p->field);
        p = p->next;
    }
    return new_root;
}

void print_list(struct list* lst) {
    while (lst != NULL) {
        cout << lst->field << " ";
        lst = lst->next;
    }
    cout << endl;
}

void free_list(struct list* lst) {
    struct list* tmp;
    while (lst != NULL) {
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}

int main() {
    srand(time(NULL));

    struct list* original = NULL;
    for (int i = 0; i < 7; i++) {
        original = push_back(original, rand() % 100);
    }

    cout << "Исходный список:     ";
    print_list(original);

    struct list* copy = copy_list_func(original);

    cout << "Скопированный список: ";
    print_list(copy);

    free_list(original);
    free_list(copy);

    return 0;
}