#include <iostream>
#include <vector>
using namespace std;

class MatrixOperations {
public:
    vector<vector<int>> operate(const vector<vector<int>>& A, const vector<vector<int>>& B, int operation) {
        if (operation != 1) {
            cout << "Invalid operation for addition." << endl;
            return {};
        }

        int rows = A.size();
        int cols = A[0].size();

        if (rows != B.size() || cols != B[0].size()) {
            cout << "Invalid dimensions for operation." << endl;
            return {};
        }

        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = A[i][j] + B[i][j];
            }
        }
        return result;
    }

    vector<vector<int>> operate(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int rowsA = A.size();
        int colsA = A[0].size();
        int rowsB = B.size();
        int colsB = B[0].size();

        if (colsA != rowsB) {
            cout << "Invalid dimensions for operation." << endl;
            return {};
        }

        vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                for (int k = 0; k < colsA; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    }

    void printMatrix(const vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        for (const auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MatrixOperations matrixOps;
    int operation;
    cout << "Enter operation type (1 for addition, 2 for multiplication): ";
    cin >> operation;
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter dimensions of Matrix A (rows cols): ";
    cin >> rowsA >> colsA;
    cout << "Enter dimensions of Matrix B (rows cols): ";
    cin >> rowsB >> colsB;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            cin >> B[i][j];
        }
    }

    if (operation == 1) {
        auto result = matrixOps.operate(A, B, 1);
        matrixOps.printMatrix(result);
    } else if (operation == 2) {
        auto result = matrixOps.operate(A, B);
        matrixOps.printMatrix(result);
    } else {
        cout << "Invalid operation type." << endl;
    }
    return 0;
}
