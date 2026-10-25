#include <iostream>
#include <windows.h>
using namespace std;

void insertElement(int*& arr, int& size, int value, int position) {
    if (position < 0) position = 0;
    if (position > size) position = size;

    int* newArr = new int[size + 1];

    for (int i = 0; i < position; ++i) {
        newArr[i] = arr[i];
    }

    newArr[position] = value;

    for (int i = position; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size++;
}

void removeLastElement(int*& arr, int& size) {
    if (size == 0) return;

    int* newArr = new int[size - 1];

    for (int i = 0; i < size - 1; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    size--;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 3;
    int* arr = new int[size] {10, 20, 30};

    cout << "Початковий масив: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\n";

    insertElement(arr, size, 5, 0);   
    insertElement(arr, size, 15, 2);

    cout << "Після додавання елементів: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\n";

    removeLastElement(arr, size);   

    cout << "Після видалення останнього елемента: ";
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\n";

    delete[] arr;
}
