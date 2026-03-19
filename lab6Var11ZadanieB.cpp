#include <iostream>
#include <string>

using namespace std;

struct student {
    string name;
    int age;
};

void changeName(student* s, string newName) {
    if (s != NULL) {
        cout << "Старое имя: " << s->name << endl;
        s->name = newName;
        cout << "Новое имя: " << s->name << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    student myStudent;
    myStudent.name = "Алексей";
    myStudent.age = 18;

    cout << "Начальное имя: " << myStudent.name << endl;

    char choice;
    do {
        string newName;
        cout << "\nВведите новое имя студента: ";
        getline(cin, newName);

        changeName(&myStudent, newName);

        cout << "\nХотите изменить имя еще раз? (y/n): ";
        cin >> choice;
        cin.ignore();  

    } while (choice == 'y' || choice == 'Y');

    cout << "\nФинальное имя: " << myStudent.name << endl;

    return 0;
}