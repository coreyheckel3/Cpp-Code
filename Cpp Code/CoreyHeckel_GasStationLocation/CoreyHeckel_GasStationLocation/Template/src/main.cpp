#include "std_lib_facilities.h"
#define sq(x) ((x) * (x))
struct point {
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y)
    {
    }
};


double dist(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}
struct point pGS;
void makePoint(){
    //struct point pGS;
    random_device seed;
    default_random_engine u(seed());
    double upperBound = 1;
    double lowerBound = 0;
    uniform_real_distribution<double> uniform(lowerBound, upperBound);
    pGS.x = uniform(u);
    uniform_real_distribution<double> uniform2(lowerBound, upperBound);
    pGS.y = uniform2(u);
    //cout << pGS.x << endl;
  //  cout << pGS.y << endl;
}


int main()
{
    struct point p1;
    struct point p2;
    struct point p3;
    struct point p4;
    struct point p5;
    struct point p6;
    struct point p7;
    struct point p8;

    array Xs = {0.0, 0.0, 0.0, 0.8, 1.0, 1.0, 1.0, 0.2};
    array Ys = {0.0, 0.8, 1.0, 1.0, 1.0, 0.2, 0.0, 0.0};
   p1.x =0.0;
   p1.y=0.0;
   p2.x =0.0;
   p2.y=0.8;
   p3.x =0.0;
   p3.y=1.0;
    p4.x =0.8;
    p4.y=1.0;
    p5.x =1.0;
    p5.y=1.0;
    p6.x =1.0;
    p6.y=0.2;
    p7.x =1.0;
    p7.y=0.0;
    p8.x =0.2;
    p8.y=0.0;

for (int i = 0; i<1000000; i++){
    makePoint();
    double sum =dist(p1.x, p1.y, pGS) + dist(p2.x, p2.y, pGS) + dist(p3.x, p3.y, pGS) + dist(p4.x, p4.y, pGS) + dist(p5.x, p5.y, pGS) + dist(p6.x, p6.y, pGS) + dist(p7.x, p7.y, pGS) + dist(p8.x, p8.y, pGS);
    cout << sum << endl;
}



    return 0;
}