/* 
Problem 0: (30 points)
*/

#include "std_lib_facilities.h"
#include "std_lib_facilities.h"

vector<vector<int>> outerProduct(vector<int>& A, vector<int>& B)
{
    vector<vector<int>> result(A.size(), vector<int>(B.size()));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            result[i][j] = A[i] * B[j];
        }
    }

    return result;
}

vector<vector<int>> transpose(vector<vector<int>>& A)
{
    vector<vector<int>> result(A[0].size(), vector<int>(A.size()));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            result[j][i] = A[i][j];
        }
    }

    return result;
}

void printMatrix(vector<vector<int>>& A)
{
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    // Define both vector A and vector B
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {1, 2, 3};

    /*Test outerProduct function, the expected output is:
    1 2 3
    2 4 6
    3 6 9
    4 8 12
    5 10 15
    */
    vector<vector<int>> M = outerProduct(A, B);
    printMatrix(M);

    /*Test transpose function, the expected output is:
    1 2 3 4 5
    2 4 6 8 10
    3 6 9 12 15
    */
    vector<vector<int>> tM = transpose(M);
    printMatrix(tM);

    keep_window_open();
    return 0;
}