#include "std_lib_facilities.h"

int a[] = {1, 2, 3, 4};
int b[] = {1, 2, 3, 4};
int x, y, z, v;

void elementWiseProduct(int a [], int b []){
    int x = a[0]*b[0];
    int y = a[1]*b[1];
    int z = a[2]*b[2];
    int v = a[3]*b[3];
    int c[] = {x, y, z, v};
}

int main()
{
elementWiseProduct(a, b);
int c[] = {x, y, z, v};
for (int i=0; i < 4; i++)
    std::cout << c[i] << ' ';
    return 1;
}
