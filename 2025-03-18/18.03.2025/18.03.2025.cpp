#include <iostream>
using namespace std;

//Exercise 1 (1)
//int main()
//{
//    double x1, y1, x2, y2;
//    cout << "Enter the coordinates of the top-left corner (x1, y1): ";
//    cin >> x1 >> y1;
//    cout << "Enter the coordinates of the bottom-right corner (x2, y2): ";
//    cin >> x2 >> y2;
//
//    double x, y;
//    cout << "Enter the coordinates of the point (X, Y): ";
//    cin >> x >> y;
//
//    if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
//        cout << "The point is inside the rectangle." << "\n";
//    }
//    else {
//        cout << "The point is outside the rectangle." << "\n";
//    }
//
//    return 0;
//}

//Exercise 1 (2)
//int main()
//{
//	int ticket;
//	cout << "Enter the six-digit ticket number: ";
//	cin >> ticket;
//	if (ticket < 100000 || ticket > 999999) {
//		cout << "Invalid ticket number." << "\n";
//	}
//
//	int firstThree = ticket / 1000;
//	int lastThree = ticket % 1000;
//
//	int sumFirst = (firstThree / 100) + (firstThree / 10 % 10) + (firstThree % 10);
//
//	int sumLast = (lastThree / 100) + (lastThree / 10 % 10) + (lastThree % 10);
//
//	if (sumFirst == sumLast) {
//		cout << "This is a lucky ticket!" << "\n";
//	}
//	else {
//		cout << "This is not a lucky ticket." << "\n";
//	}
//  return 0;
//}



//Exercise 3 (1)
//int main() {
//    int num;
//    cout << "Enter a number: ";
//    cin >> num;
//
//    (num >= 0 && num <= 100) ? cout << "A number in the range 0 to 100." : cout << "The number is not in the range 0 to 100.";
//
//    return 0;
//}


//Exercise 3 (2)
//int main() {
//    double num;
//    cout << "Enter a number: ";
//    cin >> num;
//
//    (num - int(num) != 0) ? cout << "The number has a fractional part." : cout << "The number has no fractional part.";
//
//    return 0;
//}

