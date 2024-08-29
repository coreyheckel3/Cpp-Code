#pragma once

#include "std_lib_facilities.h"

// Defining an operator inside a class like in:
// PocketChange PocketChange::operator+(const PocketChange& other);
//
// Is equivalent to defining the same operator outside the class like in:
// PocketChange operator+(const PocketChange& a, const PocketChange& b);
//
// E.g.:
// PocketChange pc1, pc2;
// PocketChange pc3 = pc1 + pc2;
//
// When defining operator+ inside a class,
// pc1 + pc2 == pc1.operator+(pc2);
// but the syntax *does not* need to change.
//
// That is, one can define an operator inside a class and still use it normally:
// PocketChange pc3 = pc1 + pc2;
//
// The advantages of defining operators inside classes are:
// - Code organization
// - One can access private members of "other" with the "." operator,
//   even thought it references a different object
//   (as long as both the caller and the parameter are of the same type)

class PocketChange {
public:
    // two constructors used to construct PocketChange objects.
    PocketChange();
    PocketChange(int q, int d);

    // member functions used to set quarter and dime amounts.
    void setQuarters(int q);
    void setDimes(int d);

    // member functions used to get the value of quarter and dime amounts.
    // "const" is used here to prevent changes of attributes.
    int getQuarters() const;
    int getDimes() const;

    // operator+ overload if the input is a PocketChange object.
    // this operator simply adds two PocketChange objects together member by member.
    PocketChange operator+(const PocketChange& other);

    // operator+ overload if the input is an integer.
    // treat the integer as the number of dimes you want to add to the pocket.
    PocketChange operator+(int d);

    // operator- overload if the input is a PocketChange object.
    // negative amounts of quarters or dimes are not reasonable.
    PocketChange operator-(const PocketChange& other);

    // operator- overload if the input is an integer.
    // treat the integer as the number of dimes you want to subtract from the pocket.
    // negative amounts of quarters or dimes are not reasonable.
    PocketChange operator-(int d);

    // another operator overload - this is a constant member function:
    // the object on the right hand side of this operator will not be
    // changed because of the first "const" and the object on the left hand
    // side will also not be changed because of the second "const". constant
    // member functions cannot make any modifications to the class members.
    bool operator==(const PocketChange& other) const;

    // similarly we have inequality operator.
    bool operator!=(const PocketChange& other) const;

private:
    // attributes cannot be directly accessed - only through getter functions.
    // in this example: getQuarters() and getDimes().
    int quarters;
    int dimes;
};

ostream& operator<<(ostream& os, const PocketChange& pc);
