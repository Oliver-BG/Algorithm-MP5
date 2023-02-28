#include <iostream>
#include <vector>

using namespace std;

vector<double> gauss_elimination(vector<vector<double>> A, vector<double> b) {
    int n = b.size();

    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Find pivot row and swap
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[pivot][i])) {
                pivot = j;
            }
        }
        swap(A[i], A[pivot]);
        swap(b[i], b[pivot]);

        // Eliminate below pivot
        for (int j = i + 1; j < n; j++) {
            double ratio = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= ratio * A[i][k];
            }
            b[j] -= ratio * b[i];
        }
    }

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}

int main() {
    // Example problem
    vector<vector<double>> A = {{2, 1, -1},
                                {-3, -1, 2},
                                {-2, 1, 2}};
    vector<double> b = {8, -11, -3};

    // Solve the problem
    vector<double> x = gauss_elimination(A, b);

    // Print the solution
    cout << "Solution: ";
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}