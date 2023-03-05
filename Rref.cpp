#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void gauss_jordan(vector<vector<double>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        double pivot = matrix[i][i];

        for (int k = i; k < n; k++)
        {
            matrix[i][k] /= pivot;
        }

        for (int j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i] / pivot;
            for (int k = i + 1; k < n; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
            matrix[j][i] = 0; // Set entry to 0 for numerical stability
        }

        cout << "" << i + 1 << ":\n";
        for (const auto &row : matrix)
        {
            for (const auto &elem : row)
            {
                cout << setprecision(2) << elem << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    for (int i = n - 1; i >= 0; i--)
    {
        double pivot = matrix[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            double factor = matrix[j][i];
            for (int k = i; k >= 0; k--)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    cout << "Final matrix:\n";
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    vector<vector<double>> matrix(3, vector<double>(3));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter a" << i + 1 << j + 1 << ": "
                 << "\n";
            cin >> matrix[i][j];
        }
    }

    gauss_jordan(matrix);
}