#include <iostream>
using namespace std;

// вузол списка (або один елемент)
class Node {
public:
    int value; // корисні дані (useful data)
    Node* next; // адреса наступного вузла в списку

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

int main() {
    Node* head = nullptr; // спочатку список порожній

    // створюємо перший елемент і робимо його головою
    head = new Node(1);

    // додаємо другий елемент на початок
    Node* newNode = new Node(0); // новий елемент зі значенням 0
    newNode->next = head;        // новий вузол "підключає" стару голову
    head = newNode;              // голова списку тепер новий вузол

    // додаємо ще один елемент на початок
    newNode = new Node(-1);
    newNode->next = head;
    head = newNode;

    // вивід списку
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}