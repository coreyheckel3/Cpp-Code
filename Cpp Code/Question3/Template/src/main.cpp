#include "std_lib_facilities.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL)); // seed random number generator with current time

    double a = 4.0; // semi-major axis
    double b = 1.0; // semi-minor axis
    double x, y; // coordinates of randomly generated point
    int n = 1000000; // number of points to generate
    int count = 0; // count of points inside ellipse

    for (int i = 0; i < n; i++)
    {
        // generate random point inside rectangle that contains ellipse
        x = (rand() / (double)RAND_MAX) * (2 * a) - a;
        y = (rand() / (double)RAND_MAX) * (2 * b) - b;

        // check if point is inside ellipse
        if ((16 * x * x) + (25 * y * y) <= 49)
            count++;
    }

    // calculate area estimate
    double area_estimate = (count / (double)n) * (4 * a * 2 * b);

    // output result
    cout << "Area enclosed by ellipse: " << area_estimate << endl;

    return 0;
}
