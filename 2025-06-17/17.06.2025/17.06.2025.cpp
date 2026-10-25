#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void print() const {
        cout << day << "/" << month << "/" << year;
    }
};

class Address {
private:
    string city;
    string street;
    int houseNumber;
public:
    Address() : city(""), street(""), houseNumber(0) {}
    Address(string c, string s, int h) : city(c), street(s), houseNumber(h) {}
    Address(const Address& other) : city(other.city), street(other.street), houseNumber(other.houseNumber) {}

    string getCity() const { return city; }
    string getStreet() const { return street; }
    int getHouseNumber() const { return houseNumber; }

    void setCity(string c) { city = c; }
    void setStreet(string s) { street = s; }
    void setHouseNumber(int h) { houseNumber = h; }

    void print() const {
        cout << street << " St., " << houseNumber << ", " << city;
    }
};

class Student {
private:
    string lastName;
    string firstName;
    string middleName;
    Date birthDate;
    Address homeAddress;
    string phone;

    int* homeworkGrades;
    int homeworkCount;
    int* practiceGrades;
    int practiceCount;
    int* examGrades;
    int examCount;

    static int studentCount;

public:
    Student() : lastName(""), firstName(""), middleName(""), phone(""),
        homeworkGrades(nullptr), homeworkCount(0),
        practiceGrades(nullptr), practiceCount(0),
        examGrades(nullptr), examCount(0) {
        studentCount++;
    }

    Student(string ln, string fn, string mn, Date bd, Address addr, string ph,
        int* hw, int hwCount, int* pr, int prCount, int* ex, int exCount)
        : lastName(ln), firstName(fn), middleName(mn), birthDate(bd), homeAddress(addr), phone(ph),
        homeworkCount(hwCount), practiceCount(prCount), examCount(exCount)
    {
        homeworkGrades = new int[homeworkCount];
        for (int i = 0; i < homeworkCount; i++) homeworkGrades[i] = hw[i];

        practiceGrades = new int[practiceCount];
        for (int i = 0; i < practiceCount; i++) practiceGrades[i] = pr[i];

        examGrades = new int[examCount];
        for (int i = 0; i < examCount; i++) examGrades[i] = ex[i];

        studentCount++;
    }

    Student(const Student& other)
        : lastName(other.lastName), firstName(other.firstName), middleName(other.middleName),
        birthDate(other.birthDate), homeAddress(other.homeAddress), phone(other.phone),
        homeworkCount(other.homeworkCount), practiceCount(other.practiceCount), examCount(other.examCount)
    {
        homeworkGrades = new int[homeworkCount];
        for (int i = 0; i < homeworkCount; i++) homeworkGrades[i] = other.homeworkGrades[i];

        practiceGrades = new int[practiceCount];
        for (int i = 0; i < practiceCount; i++) practiceGrades[i] = other.practiceGrades[i];

        examGrades = new int[examCount];
        for (int i = 0; i < examCount; i++) examGrades[i] = other.examGrades[i];

        studentCount++;
    }

    void setLastName(string ln) { lastName = ln; }
    void setFirstName(string fn) { firstName = fn; }
    void setMiddleName(string mn) { middleName = mn; }
    void setBirthDate(Date bd) { birthDate = bd; }
    void setHomeAddress(Address addr) { homeAddress = addr; }
    void setPhone(string ph) { phone = ph; }

    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getMiddleName() const { return middleName; }
    Date getBirthDate() const { return birthDate; }
    Address getHomeAddress() const { return homeAddress; }
    string getPhone() const { return phone; }

    void print() const {
        cout << "Student: " << lastName << " " << firstName << " " << middleName << "\n";
        cout << "Birth Date: "; birthDate.print(); cout << "\n";
        cout << "Address: "; homeAddress.print(); cout << "\n";
        cout << "Phone: " << phone << "\n";

        cout << "Homework grades: ";
        for (int i = 0; i < homeworkCount; i++) cout << homeworkGrades[i] << " ";
        cout << "\nPractice grades: ";
        for (int i = 0; i < practiceCount; i++) cout << practiceGrades[i] << " ";
        cout << "\nExam grades: ";
        for (int i = 0; i < examCount; i++) cout << examGrades[i] << " ";
        cout << "\n";
    }

    static int getStudentCount() { return studentCount; }
};

// Инициализация статической переменной
int Student::studentCount = 0;

int main() {
    int hw[] = { 9, 8, 10 };
    int pr[] = { 10, 9 };
    int ex[] = { 8, 9 };

    Student s1("Ivanov", "Ivan", "Ivanovich", Date(15, 5, 2000), Address("Kyiv", "Shevchenko", 10), "0991234567", hw, 3, pr, 2, ex, 2);
    s1.print();

    cout << "Total students: " << Student::getStudentCount() << "\n";

}
