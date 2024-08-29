#include "PocketChange.h"
#include "std_lib_facilities.h"

// Lab Exercise 5: Complete the PocketChange.cpp file with the correct definition of all methods.

// Hints:
// - Read through PocketChange.h declarations and the description of all member function behaviors.
// - Use main() to test your code.

int main()
{
    // Test default constructor:
    cout << "Test constructors:" << endl;
    PocketChange pc1;
    cout << pc1;

    // Test user defined constructor:
    int q = 10;
    int d = 5;
    PocketChange pc2(q, d);
    cout << pc2;

    // Test operator+(const PocketChange& other) overload
    cout << "Test operator+ overload (1):" << endl;
    cout << pc1;
    cout << pc2;
    cout << pc1 + pc2;

    // Test operator+(int d) overload
    cout << "Test operator+ overload (2):" << endl;
    cout << pc1;
    cout << pc1 + 5;

    // Test operator-(const PocketChange& other) overload
    pc1.setQuarters(5);
    pc1.setDimes(4);
    cout << "Test operator- overload (1):" << endl;
    cout << pc1;
    cout << pc2;
    cout << pc2 - pc1;

    // Test operator-(int d) overload
    cout << "Test operator- overload (2): " << endl;
    cout << pc2;
    cout << pc2 - 4;

    // Test operator==(const PocketChange& other) const overload
    pc2.setQuarters(5);
    pc2.setDimes(4);
    cout << "Test operator== overload:" << endl;
    if (pc1 == pc2) {
        cout << "pc1 and pc2 have equal amounts of quarters and dimes" << endl;
    } else {
        cout << "pc1 and pc2 do not have equal amounts of quarters or dimes" << endl;
    }

    cout << endl;

    // Test operator!=(const PocketChange& other) const overload
    pc2.setQuarters(10);
    cout << "Test operator!= overload:" << endl;
    if (pc1 != pc2) {
        cout << "pc1 and pc2 do not have equal amounts of quarters or dimes" << endl;
    } else {
        cout << "pc1 and pc2 have equal amounts of quarters and dimes" << endl;
    }

    return 0;
}
