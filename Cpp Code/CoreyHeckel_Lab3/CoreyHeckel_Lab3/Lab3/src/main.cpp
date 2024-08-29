#include "std_lib_facilities.h"
#include <cassert>

// Lab Exercise 3: Given two matrices A and B, return C = A x B.
// Hints:
// - To create a vector of two dimensions NxM, do: vector<vector<double>> v(N, vector<double>(M))
// - To get the number of rows in a matrix, do: matrix.size()
// - To get the number of columns in a matrix, do: matrix[0].size()
vector<vector<double>> matrixMultiplication(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    vector<vector<double>> C;

    int row1 = A.size();
    int col1 = A[0].size();
    int row2 = B.size();
    int col2 = B[0].size();
    int rslt[row1][col2];

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < row2; k++) {
                rslt[i][j] += A[i][k] * B[k][j];
            }

            cout << rslt[i][j] << "\t";
        }

        cout << endl;
    }

    return C;
}

// Example use cases:
int main()
{
    vector<vector<double>> M1 = {
        { 2.0, 3.0, -1.0, 0.0 },
        { -7.0, 2.0, 1.0, 10.0 }
    };

    vector<vector<double>> M2 = {
        { 3.0, 4.0 },
        { 2.0, 1.0 },
        { -1.0, 2.0 },
        { 2.0, 7.0 }
    };

    vector<vector<double>> M3 = matrixMultiplication(M1, M2);

    // The following code should print:
    // M3 = {
    //     { 13, 9 },
    //     { 2, 46 }
    // };
    cout << '\n';
    cout << "M3 = {" << '\n';
    for (int i = 0; i < M3.size(); ++i) {
        cout << '\t' << "{ ";
        for (int j = 0; j < M3[0].size(); ++j) {
            cout << M3[i][j];
            if (j < M3[0].size() - 1) {
                cout << ',';
            }
            cout << ' ';
        }
        cout << '}';
        if (i < M3.size() - 1) {
            cout << ',';
        }
        cout << '\n';
    }
    cout << "};";
    cout << '\n';

    return 0;
}
