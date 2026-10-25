#include <iostream>
using namespace std;

//Exercise 1
//int main()
//{
//	double uah, usd = 41.59, eur = 45.41, bit = 3384888.68;
//	cout << "Enter the amount of UAH: ";
//	cin >> uah;
//	cout << "Amount in USD: " << uah / usd << "\n";
//	cout << "Amount in EUR: " << uah / eur << "\n";
//	cout << "Amount in Bitcoin: " << uah / bit << "\n";
// 
// return 0;
//}

//Exercise 2
//int main()
//{
//	cout << "Enter the number in kilometers:\n";
//	double km;
//	cin >> km;
//	cout << "The number in nautical mile: " << km * 0.5399568035 << "\n";
//	cout << "The number in miles: " << km * 0.621371192 << "\n";
// 
// return 0;
//}

//Exercise 3 (1)
//int main()
//{
//	int a, b, c;
//	cout << "Enter the first number: ";
//	cin >> a;
//	cout << "Enter the second number: ";
//	cin >> b;
//	c = a;
//	a = b;
//	b = c;
//	cout << "a = " << a << ", b = " << b << ".\n";
// 
// return 0;
//}


//Exercise 3 (2)
//int main()
//{
//	int a, b;
//	cout << "Enter the first number a: ";
//	cin >> a;
//	cout << "Enter the second number b: ";
//	cin >> b;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	cout << "a = " << a << ", b = " << b << ".\n";
// 
// return 0;
//}


//Exercise 4
//int main()
//{
//	int a, b;
//	cout << "Enter a three-digit number a: ";
//	cin >> a;
//	cout << "Enter a three-digit number b: ";
//	cin >> b;
//
//	int newAcenter = (a / 100) * 100 + (b / 10 % 10) * 10 + (a % 10);
//	int newBcenter = (b / 100) * 100 + (a / 10 % 10) * 10 + (b % 10);
//
//	cout << "New number a: " << newAcenter << "\n";
//	cout << "New number b: " << newBcenter << "\n";
//
// return 0;
//}


//Exercise 5
//int main()
//{
//	int n;
//	cout << "Enter a four-digit number: ";
//	cin >> n;
//
//	int a = n / 1000;
//	int b = (n / 100) % 10;
//	int c = (n / 10) % 10;
//	int d = n % 10;
//
//	cout << "Sum a and c: " << a + c << "\n";
//	cout << "Difference b and d: " << b - d << "\n";
// 
// return 0;
//}


//Exercise 6
//int main()
//{
//	int n;
//	cout << "Enter a three-digit number: ";
//	cin >> n;
//	int first = n / 100;
//	int last = n % 10;
//	cout << "Result: " << first << last << "\n";
// 
// return 0;
//}


//Exercise 7
//int main() {
//    double deposit, annualRate, monthlyPayment;
//
//    cout << "Enter the deposit amount (UAH): ";
//    cin >> deposit;
//
//    cout << "Enter the annual percentage (%): ";
//    cin >> annualRate;
//
//    monthlyPayment = (deposit * (annualRate / 100)) / 12;
//
//    cout << "Monthly bank payment: " << monthlyPayment << " UAH" << "\n";
// 
// return 0;
//}


//Exercise 8
//int main()
//{
//	cout << "Enter the number in ib: ";
//	double ib;
//	cin >> ib;
//	cout << "The number in kg: " << ib * 0.45359237 << "\n";
//	cout << "Enter the number in kg: ";
//	double kg;
//	cin >> kg;
//	cout << "The number in ib: " << kg / 0.45359237 << "\n";
//
//	return 0;
//}


//Exercise 9
//int main()
//{
//	int num;
//	cout << "Enter a three-digit number: ";
//	cin >> num;
//
//	cout << "Reverce num: " << num % 10 << (num / 10) % 10 << num / 100;
//
//	return 0;
//}


//Exercise 10
//int main()
//{
//	double m1 = 3.3e23, m2 = 4.87e24, m3 = 5.97e24, m4 = 6.42e23;
//	double m5 = 1.9e27, m6 = 5.68e26, m7 = 8.68e25, m8 = 1.02e26;
//
//	double total = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8;
//	double mean = total / 8;
//
//	cout << "Total mass: " << total << "\n";
//	cout << "Mean mass: " << mean << "\n\n";
//
//	cout << "Percentage of each planet:\n";
//	cout << "Mercury: " << (m1 / total) * 100 << "%\n";
//	cout << "Venus: " << (m2 / total) * 100 << "%\n";
//	cout << "Earth: " << (m3 / total) * 100 << "%\n";
//	cout << "Mars: " << (m4 / total) * 100 << "%\n";
//	cout << "Jupiter: " << (m5 / total) * 100 << "%\n";
//	cout << "Saturn: " << (m6 / total) * 100 << "%\n";
//	cout << "Uranus: " << (m7 / total) * 100 << "%\n";
//	cout << "Neptune: " << (m8 / total) * 100 << "%\n\n";
//
//	cout << "Jupiter is " << m5 / (total - m5) << " times larger than all other planets combined.\n";
//
//	return 0;
//}


//Exercise 11
//int main()
//{
//    double length, width, height, N, M, R;
//
//    cout << "Enter the length of the room (m): ";
//    cin >> length;
//    cout << "Enter the width of the room (m): ";
//    cin >> width;
//    cout << "Enter the height of the room (m): ";
//    cin >> height;
//    cout << "Enter the amount of paint required per 1 m2: ";
//    cin >> N;
//    cout << "Enter the percentage of the surface occupied by windows and doors (m2): ";
//    cin >> M;
//    cout << "Enter the cost of one liter of paint (UAH): ";
//    cin >> R;
//
//    double area = 2 * (length * height + width * height);
//    double windowDoorArea = area * (M / 100);
//    double paintableArea = area - windowDoorArea; 
//
//    double paintNeeded = paintableArea * N;
//
//    double totalCost = paintNeeded * R;
//
//    cout << "Required amount of paint: " << paintNeeded << " liters\n";
//    cout << "Total cost of the paint: " << totalCost << " UAH\n";
//
//    return 0;
//}