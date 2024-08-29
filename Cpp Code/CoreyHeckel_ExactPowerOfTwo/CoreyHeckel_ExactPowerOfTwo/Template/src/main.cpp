#include "std_lib_facilities.h"

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
    // Function call
    isPowerOfTwo(4) ? cout << "Yes" << endl
                     : cout << "No" << endl;

    return 0;
}

