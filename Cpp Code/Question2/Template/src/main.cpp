#include "std_lib_facilities.h"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return pow(x-1, 3) - 216;
}

double bisection(double a, double b, double eps)
{
    double c;
    while (fabs(b-a) > eps)
    {
        c = (a+b)/2;
        if (f(c) == 0) {
            return c;
        } else if (f(c)*f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

double secant(double x0, double x1, double eps)
{
    double x2;
    do {
        x2 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x2)) > eps);
    return x2;
}

int main()
{
    double a = 0, b = 10, eps = 0.0001;
    double root = bisection(a, b, eps);
    cout << "The root is: " << root << endl;

    double x0 = 1, x1 = 2, eps1 = 0.0001;
    double root1 = secant(x0, x1, eps1);
    cout << "The root is: " << root1 << endl;
    return 0;
}

