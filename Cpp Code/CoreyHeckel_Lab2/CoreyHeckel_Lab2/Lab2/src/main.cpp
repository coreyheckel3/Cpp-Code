#include "std_lib_facilities.h"

// Lab Exercise 2: N take value: 1 <= N <= 20.

// Function used to tell if the input integer num is a prime number.
// Prime number starts with 2 and none prime number starts with 4.
bool isPrime(int n){
    // Corner case
    if (n <= 1)
        return false;
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// this function stores the first N prime number into the array(1 dimension).
void primeNumber(int N, int array[]){
    int n = 2;
    for (int i = 1; i <= N; i++) {
        while (!(isPrime(n))) {
            n++;
        }
        array[i] = n;
        n++;

    }
}

// this function stores the first N none prime number into the array(1 dimension).
void nonePrimeNumber(int N, int array[]) {
    int n = 4;
    for (int i = 1; i <= N; i++) {
        while ((isPrime(n) )) {
            n++;
        }
        array[i] = n;
        n++;
    }
}

// this function calculates the dot product of two arrays.
    int dotProduct(int N, const int ary1[], const int ary2[]) {
        double dotProductValue = 0;
        for (int i = 0; i < N; i++)
            dotProductValue = dotProductValue + ary1[i] * ary2[i];
        return dotProductValue;
    }

// this function prints out the array with length of N.
    void printArray(int N, int array[]) {
        for (int i = 0; i < N; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

// Example test cases by changing the value of N:

/* N = 10
2 3 5 7 11 13 17 19 23 29
4 6 8 9 10 12 14 15 16 18
Dot product of array1 and array2: 1808
*/

/* N = 5
2 3 5 7 11
4 6 8 9 10
Dot product of array1 and array2: 239
*/

    int main() {
        const int N = 10;
        // Define 2 arrays to store integers with specified size
        int array1[N];
        int array2[N];
        // Put the first N prime numbers into the array1 and put the first N none Prime numbers into array2
        primeNumber(N, array1);
        nonePrimeNumber(N, array2);
        // print out the two arrays.
        printArray(N, array1);
        printArray(N, array2);
        // print out the dot product of two array.
        cout << "Dot product of array1 and array2: " << dotProduct(N, array1, array2) << endl;
        return 0;
    }
