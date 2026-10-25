#include <iostream>
using namespace std;

void obmin(int* px, int* py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main() {
    int x = 10;
    int y = 20;

    obmin(&x, &y); 

    cout << x << " " << y << "\n";

}
