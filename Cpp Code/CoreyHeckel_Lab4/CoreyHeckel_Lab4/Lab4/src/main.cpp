#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std;

// helper function used to generate uniformly distributed random variable with lower bound and upper bound
double uniformRandom(double lower, double upper){
    random_device r;
    default_random_engine engine(r());
    uniform_real_distribution<double> uniform(lower, upper);
    return uniform(engine);
}

// helper function used to calculate the sum distance
double sumDistance(double x, double y, const vector<double>& xx, const vector<double>& yy) {
    double sum = 0;
    for (int i = 0; i < xx.size(); i++) {
        sum += sqrt(pow(xx[i]-x,2) + pow(yy[i]-y,2));
    }
    return sum;
}

pair<double, vector<double>> minimumDistance(const vector<double>& xx, const vector<double>& yy){
    // The vector result
    pair <double, vector<double>> result;
    // The optimal point
    vector<double> optimalPoint = {0,0};
    // the optimal value
    double optimalDistance = 10000;
    // simulation time
    int N = 100000;

    // Monte Carlo simulation
    for (int i = 0; i < N; i++) {
        // generate a random point
        double x = uniformRandom(min(xx[0], min(xx[1], xx[2])), max(xx[0], max(xx[1], xx[2])));
        double y = uniformRandom(min(yy[0], min(yy[1], yy[2])), max(yy[0], max(yy[1], yy[2])));
        // calculate the sum distance
        double distance = sumDistance(x, y, xx, yy);
        // update the optimal value and point
        if (distance < optimalDistance) {
            optimalDistance = distance;
            optimalPoint[0] = x;
            optimalPoint[1] = y;
        }
    }
    // Assign values to result
    result.first = optimalDistance;
    result.second = optimalPoint;
    return result;
}

int main()
{
    // x and y coordinates of triangle vertices
    vector<double> xx = {1,9,5};
    vector<double> yy = {1,1,3};
    pair<double, vector<double>> solution = minimumDistance(xx, yy);
    cout << "The optimal point is: (" << solution.second[0] << ", " << solution.second[1] << ")" << endl;
    cout << "The optimal value is: " << solution.first << endl;
    return 0;
}
