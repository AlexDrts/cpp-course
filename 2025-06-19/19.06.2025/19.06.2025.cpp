#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

class Array {
	unsigned int capacity = 10; // при створенні масиву, він одразу для себе робить запас пам'яті на 10 елементів
	int* data = new int[capacity];
	unsigned int length = 0; // фактична (реальна) кількість елементів, присутніх у масиві

public:
	Array() {}

	void AddToBack(int value) {
		if (length < capacity) // якщо виділенної зарання пам'яті ВИСТАЧАЄ для додавання чергового елемента
			data[length] = value;
		else { // АЛЕ ЯКЩО МІСЦЯ ВЖЕ НЕ ВИСТАЧАЄ, ТО
			// треба перевиділити пам'ять
			capacity *= 2; // збільшуємо запас пам'яті у 2 рази (можна і в 1.5, можна і в 1.2)
			// якщо був запас 10 елементів, то стане 20
			// якщо запас був 20 елементів, то стане 40, і тд
			int* temp = new int[capacity]; // новий масив буде в 2 рази більше по пам'яті
			// але в старому масиві все ще усього length елементів, тому цикл треба написати так, щоб зачепити лише старі елементи зі старого масиву
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			// в новий масив в кінець пишеться наступний елемент
			temp[length] = value;
			delete[] data; // в цілях запобігання витокам пам'яті, чистимо пам'ять від старого масиву
			data = temp; // переставляємо покажчик на новий масив
		}
		length++;
	}

	void AddToFront(int value) {
		if (length < capacity) { // ще є вільна пам'ять під черговий елмент
			// перевиділяти пам'ять на 1 елемент кожен раз - погана ідея (якщо елементів буде більше ніж 300000+ то все буде відбуватися максимально повільно)
			// при тому що пам'ять вже виділена (є кепесіті), то доведеться зробити зсув для всіх існуючих елементів на 1 вправо
			for (int i = length - 1; i >= 0; i--) { // зсув іде справа наліво (тому що якщо робити його зліва направо, з початку масива в кінець) то можна втратити існуючі елементи
				data[i + 1] = data[i];
			}
			data[0] = value;
		}
		else { // АЛЕ ЯКЩО МІСЦЯ ВЖЕ НЕ ВИСТАЧАЄ, ТО
			// треба перевиділити пам'ять
			capacity *= 2; // збільшуємо запас пам'яті у 2 рази (можна і в 1.5, можна і в 1.2)
			int* temp = new int[capacity]; // новий масив буде в 2 рази більше по пам'яті
			// але в старому масиві все ще усього length елементів, тому цикл треба написати так, щоб зачепити лише старі елементи зі старого масиву
			for (int i = 0; i < length; i++) {
				temp[i + 1] = data[i];
			}
			// в новий масив в початок (по індексу 0) пишеться новий елемент
			temp[0] = value;
			delete[] data; // в цілях запобігання витокам пам'яті, чистимо пам'ять від старого масиву
			data = temp; // переставляємо покажчик на новий масив
		}
		length++;
	}

	// переписати метод, тому що він не враховує кепесіті!!!
	void RemoveFromBack() {
		if (length == 0) {
			cout << "The array is empty, there is nothing to delete!\n";
			return;
		}
		// тепер ми просто зменшуємо length (без перевиділення пам'яті, бо capacity враховується)
		length--;
	}

	// RemoveFromFront – видаляє елемент з початку динамічного масиву
	void RemoveFromFront() {
		if (length == 0) {
			cout << "The array is empty, there is nothing to delete!\n";
			return;
		}
		// робимо зсув усіх елементів вліво
		for (int i = 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	// Insert(value, index) – вставляє нове значення по вказаному індексу
	void Insert(int value, int index) {
		if (index < 0 || index > length) {
			cout << "Incorrect index!\n";
			return;
		}
		// перевірка на наявність вільного місця
		if (length == capacity) {
			capacity *= 2;
			int* temp = new int[capacity];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
		// зсув елементів вправо
		for (int i = length; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
		length++;
	}

	// RemoveByIndex(index) – видалити елемент по індексу
	void RemoveByIndex(int index) {
		if (index < 0 || index >= length) {
			cout << "Incorrect index!\n";
			return;
		}
		// зсуваємо усі елементи вліво
		for (int i = index; i < length - 1; i++) {
			data[i] = data[i + 1];
		}
		length--;
	}

	// RemoveByValue(value) – видаляє всі елементи з вказаним значенням
	void RemoveByValue(int value) {
		int newLen = 0;
		for (int i = 0; i < length; i++) {
			if (data[i] != value) {
				data[newLen++] = data[i];
			}
		}
		length = newLen;
	}

	// Sort – відсортувати масив
	void Sort() {
		std::sort(data, data + length);
	}

	// Reverse – змінити порядок на протилежний
	void Reverse() {
		for (int i = 0; i < length / 2; i++) {
			swap(data[i], data[length - 1 - i]);
		}
	}

	// Shuffle – перемішати елементи випадковим чином
	void Shuffle() {
		for (int i = 0; i < length; i++) {
			int r = rand() % length;
			swap(data[i], data[r]);
		}
	}

	// переписати Print (додати інформацію про ленс та кепесіті)
	void Print() const {
		cout << "Length = " << length << ", Capacity = " << capacity << "\n";
		if (length == 0) {
			cout << "The array is empty.!\n";
		}
		else {
			cout << "array elements: ";
			for (int i = 0; i < length; i++)
			{
				cout << data[i] << " ";
			}
			cout << "\n";
		}
	}

	~Array() {
		cout << "D-TOR\n";
		if (data != nullptr) {
			delete[] data;
		}
	}

	// переписати!!! кепесіті не враховано!!!
	Array(const Array& original) {
		cout << "COPY C-TOR\n";
		this->length = original.length;
		this->capacity = original.capacity; // тепер копіюємо і capacity
		this->data = new int[capacity]; 
		for (int i = 0; i < length; i++)
			this->data[i] = original.data[i]; 
	}
};

int main() {

	Array a;

	for (int i = 0; i < 15; i++) {
		a.AddToBack(i);
	}
	a.Print();

	cout << "RemoveFromFront\n";
	a.RemoveFromFront();
	a.Print();

	cout << "Insert 100 at index 5\n";
	a.Insert(100, 5);
	a.Print();

	cout << "RemoveByIndex 3\n";
	a.RemoveByIndex(3);
	a.Print();

	cout << "RemoveByValue 10\n";
	a.RemoveByValue(10);
	a.Print();

	cout << "Sort\n";
	a.Sort();
	a.Print();

	cout << "Reverse\n";
	a.Reverse();
	a.Print();

	cout << "Shuffle\n";
	a.Shuffle();
	a.Print();

	Array b = a; 
	b.Print();
}
