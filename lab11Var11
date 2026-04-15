#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Queue {
    int data[MAX_SIZE];
    int front_index = -1;
    int rear_index = -1;
};

void enqueue(Queue& q, int value) {
    if (q.rear_index == MAX_SIZE - 1) {
        cout << "Очередь полна!\n";
        return;
    }
    if (q.front_index == -1) q.front_index = 0;
    q.data[++q.rear_index] = value;
    cout << "Добавлено: " << value << endl;
}

int dequeue(Queue& q) {
    if (q.front_index == -1) {
        cout << "Очередь пуста!\n";
        return -1;
    }
    int value = q.data[q.front_index];
    if (q.front_index == q.rear_index) {
        q.front_index = q.rear_index = -1;
    } else {
        q.front_index++;
    }
    return value;
}

int front(Queue& q) {
    if (q.front_index == -1) {
        cout << "Очередь пуста!\n";
        return -1;
    }
    return q.data[q.front_index];
}

void print(Queue& q) {
    if (q.front_index == -1) {
        cout << "Очередь пуста\n";
        return;
    }
    for (int i = q.front_index; i <= q.rear_index; i++)
        cout << q.data[i] << " ";
    cout << endl;
}

int main() {
    Queue q;
    int choice, value;
    
    do {
        cout << "\n1-добавить 2-удалить 3-первый 4-показать 0-выход: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Число: ";
                cin >> value;
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) cout << "Удалено: " << value << endl;
                break;
            case 3:
                value = front(q);
                if (value != -1) cout << "Первый: " << value << endl;
                break;
            case 4:
                print(q);
                break;
        }
    } while (choice != 0);
    
    return 0;
}