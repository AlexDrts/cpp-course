#include <iostream>
#include "ElectricKettle.h"
#include "Book.h"
#include "Phone.h"
#include "GelPen.h"
#include "Banknote1000UAH.h"
using namespace std;

int main() {
    ElectricKettle kettle;
    kettle.SetBrand("Tiphal");
    kettle.SetCapacity(1.7);
    kettle.SetHasAutoOff(true);
    kettle.SetColor("White");

    Book book;
    book.SetTitle("Harry Potter and the Philosopher's Stone");
    book.SetAuthor("J.K. Rowling");
    book.SetPages(223);
    book.SetGenre("Fantasy");

    Phone phone;
    phone.SetBrand("Apple");
    phone.SetModel("iPhone 16");
    phone.SetStorage(256);
    phone.SetScreenSize(6.3);

    GelPen pen;
    pen.SetBrand("Pilot");
    pen.SetInkColor("Blue");
    pen.SetTipSize(0.5);
    pen.SetIsRetractable(true);\

    Banknote1000UAH note;
    note.SetYearIssued(2019);

    kettle.Info();
    book.Info();
    phone.Info();
    pen.Info();
    note.Info();

    return 0;
}
