#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void gauss_jordan(vector<vector<double>> &matrix)
{
    int n = matrix.size();

    // Forward elimination
    for (int i = 0; i < n; i++)
    {
        double pivot = matrix[i][i];

        // Divide row i by pivot
        for (int k = i; k < n; k++)
        {
            matrix[i][k] /= pivot;
        }

        // Subtract multiple of row i from subsequent rows
        for (int j = i + 1; j < n; j++)
        {
            double factor = matrix[j][i] / pivot;
            for (int k = i + 1; k < n; k++)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
            matrix[j][i] = 0; // Set entry to 0 for numerical stability
        }

        // Print intermediate matrix
        cout << "Intermediate matrix after elimination of variable x" << i + 1 << ":\n";
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

    // Backward substitution
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

    // Print final matrix
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
    // Example usage

    // vector<vector<double>> matrix = {{x, y, z},
    //                                   {xx, yy, zz},
    //                                   {xxx, yyy, zzz}};

    // cout << "Enter a11:";
    // cin >> matrix[0][1];

    // cout << "Enter a12";
    // cin >> y;

    // cout << "Enter a13";
    // cin >> z;

    // cout << "Enter a21";
    // cin >> xx;

    // cout << "Enter 22";
    // cin >> yy;

    // cout << "Enter 23";
    // cin >> zz;

    // cout << "Enter 31";
    // cin >> xxx;

    // cout << "Enter 32";
    // cin >> yyy;

    // cout << "Enter 33";
    // cin >> zzz;

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

    // for (const auto &row : matrix)
    // {
    //     for (const auto &elem : row)
    //     {
    //         cout << elem << ' ';
    //     }
    //     cout << '\n';
    // }
}