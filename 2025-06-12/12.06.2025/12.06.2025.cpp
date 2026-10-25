#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

// написати корисний, зрозумілий тип для роботи з динамічним масивом (поки що з елементами типу інт)

class Array {
	int* data; // покажчик на майбутній динамічний масив
	unsigned int length;

public:
	Array() {
		data = nullptr;
		length = 0;
		cout << "Створено пустий масив\n";
	}

	Array(int ar[], unsigned int size) {
		if (size > 1000000) throw "error!\n";

		// якщо в класі є поле-покажчик, то іноді прямо в конструкторі треба буде ВИДІЛЯТИ ПАМ'ЯТЬ динамічно під цей покажчик
		length = size;
		data = new int[length];
		for (int i = 0; i < length; i++) {
			data[i] = ar[i];
		}
		cout << "Створено непустий масив на " << size << " елементів\n";
	}

	// конструктор - метод, в який ми потрапляємо пілся створення об'єкта (записуємо значення в поля, виділяємо пам'ять під поля-покажчики)
	// деструктор - метод, який викликається АВТОМАТИЧНО безпсередньо перед тим, як об'єкт буде знищено.
	// 1) там можна зробити роздруківку і переконатися що об'єкт перестане існувати
	// 2) пам'ять виділена під поля-покажчики може бути вівільнена САМЕ ТАМ

	void Print() const {
		if (length == 0) {
			cout << "Масив пустий, нема чого показувати :(\n";
		}
		else {
			cout << "Елементи масиву: ";
			for (int i = 0; i < length; i++)
			{
				cout << data[i];
				cout << (i == length - 1 ? "." : ", ");
			}
			cout << "\n";
		}
	}

	unsigned int GetLength() const {
		return length;
	}

	void AddToBack(int value) {
		// робимо новий масив, в якому буде на 1 елемент більше
		int* temp = new int[length + 1];
		// переганяємо елементи зі старого масиву в новий
		for (int i = 0; i < length; i++)
		{
			temp[i] = data[i];
		}
		// в кінець нового масиву додаємо передане значення через параметр
		temp[length] = value;
		// старий масив треба почистити, інакше буде виток пам'яті
		delete[] data;
		// переставляємо основний покажчик зі старого масива (якого доречі уже і не існує), на новий масив
		data = temp;
		// так як відбулося додавання 1 елемента в кінець масиву, то його довжина стала +1 
		length++;
	}

	void RemoveFromBack() {
		if (length == 0) {
			cout << "Нема чого видаляти, масив жеж пустий!\n";
			return; // якщо нема чого видаляти, то просто нічого не робимо
			// throw "Помилка! Елементів нема!";
		}
		length--;
		int* temp = new int[length];
		for (int i = 0; i < length; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
	}

	void AddToFront(int value) {
		// робимо новий масив, в якому буде на 1 елемент більше
		int* temp = new int[length + 1];
		// переганяємо елементи зі старого масиву в новий
		for (int i = 0; i < length; i++)
		{
			temp[i + 1] = data[i];
		}
		// на початок нового масиву додаємо передане значення через параметр
		temp[0] = value;
		// старий масив треба почистити, інакше буде виток пам'яті
		delete[] data;
		// переставляємо основний покажчик зі старого масива (якого доречі уже і не існує), на новий масив
		data = temp;
		// так як відбулося додавання 1 елемента в кінець масиву, то його довжина стала +1 
		length++;
	}

	void RemoveFromFront() {
		if (length == 0) {
			cout << "Нема чого видаляти, масив жеж пустий!\n";
			return; // якщо нема чого видаляти, то просто нічого не робимо
			// throw "Помилка! Елементів нема!";
		}
		length--;
		int* temp = new int[length];
		for (int i = 1; i < length + 1; i++)
			temp[i - 1] = data[i];
		delete[] data;
		data = temp;
	}

	void SortAZ() {
		sort(data, data + length);
	}

	void Shuffle() {
		for (int i = 0; i < 10000; i++)
		{
			int ri1 = rand() % length;
			int ri2 = rand() % length;
			swap(data[ri1], data[ri2]);
		}
	}

	void Add10RandomNumbers() {
		for (int i = 0; i < 10; i++)
			AddToBack(rand() % 100);
	}

	// приклад деструктора
	// деструктор не можна перевантажити, він ніколи не приймає параметрів!
	~Array() {
		if (data != nullptr) {
			delete[] data;
		}
		cout << "Об'єкт було знищено, а пам'ять - вивільнено!\n";
	}

	// конструктор копіювання
	// 
	Array(Array& original) {
		this->length = original.length;
		this->data = new int[this->length];
		for (int i = 0; i < this->length; i++)
		{
			this->data[i] = original.data[i];
		}
	}

	// 1) Insert
	void Insert(int index, int value) {
		if (index < 0 || index > length) {
			cout << "Помилка! Індекс за межами масиву\n";
			return;
		}
		int* temp = new int[length + 1];
		for (int i = 0; i < index; i++) temp[i] = data[i];
		temp[index] = value;
		for (int i = index; i < length; i++) temp[i + 1] = data[i];
		delete[] data;
		data = temp;
		length++;
	}

	// 2) RemoveAt
	void RemoveAt(int index) {
		if (index < 0 || index >= length) {
			cout << "Помилка! Індекс за межами масиву\n";
			return;
		}
		length--;
		int* temp = new int[length];
		for (int i = 0, j = 0; i < length + 1; i++) {
			if (i != index) temp[j++] = data[i];
		}
		delete[] data;
		data = temp;
	}

	// 3) RemoveByValue
	void RemoveByValue(int value) {
		int count = 0;
		for (int i = 0; i < length; i++) if (data[i] == value) count++;
		if (count == 0) return;
		int* temp = new int[length - count];
		for (int i = 0, j = 0; i < length; i++) {
			if (data[i] != value) temp[j++] = data[i];
		}
		length -= count;
		delete[] data;
		data = temp;
	}

	// 4) Clear
	void Clear() {
		delete[] data;
		data = nullptr;
		length = 0;
	}

	// 5) IsEmpty
	bool IsEmpty() const {
		return length == 0;
	}

	// 6) IndexOf
	int IndexOf(int value) const {
		for (int i = 0; i < length; i++) if (data[i] == value) return i;
		return -1;
	}

	// 7) LastIndexOf
	int LastIndexOf(int value) const {
		for (int i = length - 1; i >= 0; i--) if (data[i] == value) return i;
		return -1;
	}

	// 8) Reverse
	void Reverse() {
		for (int i = 0; i < length / 2; i++) swap(data[i], data[length - i - 1]);
	}
};

int main() {
	SetConsoleOutputCP(1251);
	srand(time(0));

	Array original;
	original.Add10RandomNumbers();
	original.Print();

	Array copy = original;
	// Array copy(original); // виклик конструктору копіювання! КК
	copy.Print();

	cout << "\nТест Insert на позицію 2 зі значенням 999:\n";
	copy.Insert(2, 999);
	copy.Print();

	cout << "\nТест RemoveAt на позицію 2:\n";
	copy.RemoveAt(2);
	copy.Print();

	cout << "\nТест RemoveByValue (видалити всі 50):\n";
	copy.RemoveByValue(50);
	copy.Print();

	cout << "\nТест Clear:\n";
	copy.Clear();
	copy.Print();
	cout << "IsEmpty? " << (copy.IsEmpty() ? "Так" : "Ні") << "\n";

	copy.Add10RandomNumbers();
	copy.Print();

	cout << "\nТест Reverse:\n";
	copy.Reverse();
	copy.Print();

	cout << "\nТест IndexOf для значення copy[0]: " << copy.IndexOf(copy.GetLength() > 0 ? copy.GetLength() : -1) << "\n";
	cout << "Тест LastIndexOf для значення copy[0]: " << copy.LastIndexOf(copy.GetLength() > 0 ? copy.GetLength() : -1) << "\n";

}
