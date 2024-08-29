#include "PocketChange.h"

// Default constructor
PocketChange::PocketChange()
    : quarters { 0 }
    , dimes { 0 }
{
}

// User-defined constructor
PocketChange::PocketChange(int q, int d)
    : quarters { q }
    , dimes { d }
{
}

// Quarters Setter
void PocketChange::setQuarters(int q)
{
    quarters = q;
}

// Dimes Setter
void PocketChange::setDimes(int d)
{
    dimes = d;
}

// Quarters Getter
int PocketChange::getQuarters() const
{
    return quarters;
}

// PocketChange Getter
int PocketChange::getDimes() const
{
    return dimes;
}

// This operator is used to add two PocketChange objects
PocketChange PocketChange::operator+(const PocketChange& other)
{
    PocketChange pocket;
    pocket.setQuarters(quarters + other.quarters);
    pocket.setDimes(dimes + other.dimes);
    return pocket;
}

// This operator is used to add a PocketChange object on the left hand side
// of the operator to an integer value on the right hand side of the operator.
PocketChange PocketChange::operator+(int d)
{
    PocketChange pocket;
    pocket.setQuarters(quarters);
    pocket.setDimes(dimes + d);
    return pocket;
}

// This operator is used to subtract two PocketChange objects
PocketChange PocketChange::operator-(const PocketChange& other)
{
    PocketChange pocket;
    pocket.setQuarters(quarters - other.quarters);
    pocket.setDimes(dimes - other.dimes);
    return pocket;
}

// This operator is used to subtract a PocketChange object on the left hand side
// of the operator from an integer value on the right hand side of the operator.
PocketChange PocketChange::operator-(int d)
{
    PocketChange pocket;
    pocket.setQuarters(quarters);
    pocket.setDimes(dimes - d);
    return pocket;
}

// Implementation of operator==, which is a constant member function.
bool PocketChange::operator==(const PocketChange& other) const
{
    return (quarters == other.quarters && dimes == other.dimes);
}

// Implementation of operator!=, which is a constant member function.
bool PocketChange::operator!=(const PocketChange& other) const
{
    return (quarters != other.quarters || dimes != other.dimes);
}

ostream& operator<<(ostream& os, const PocketChange& pocket)
{
    os << "quarters amount: " << pocket.getQuarters() << endl;
    os << "dimes amount: " << pocket.getDimes() << endl;
    os << endl;
    return os;
}
