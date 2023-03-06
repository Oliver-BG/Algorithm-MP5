#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    queue<int> points;
    // function to add an edge to graph
    void addEdge(int v, int w);
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    bool exist = false;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (*i == w)
        {
            cout << "Given Vertex already exist" << endl;
            exist = true;
        }
    }
    if (!exist)
        adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    points.push(v);
    list<int>::iterator i;
    cout << "Vertex " << v << " is visited" << endl;
    cout << "Following are points connected to vertex " << v << ":\n[";
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        cout << *i << " ";
    cout << "]" << endl;
    // Recur for all the vertices adjacent
    // to this vertex

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            cout << "We go to: [" << *i << "]" << endl;
            DFS(*i);
        }
    }
}

int dfs_driver()
{
    Graph g;
    int input1, input2;
    cout << "[If you wish to stop, enter a vertex or point that are less than 0]" << endl;
    while (input1 >= 0 || input2 >= 0)
    {
        cout << "Enter A Vertex and point:[eg. 2 4]: ";
        cin >> input1 >> input2;
        if (input1 >= 0 || input2 >= 0)
            g.addEdge(input1, input2);
    }
    cout << "Enter a starting vertex: ";
    cin >> input1;
    // Function call
    cout << endl
         << endl;
    g.DFS(input1);
    cout << "\nFollowing is Depth First Traversal"
            " (starting from vertex "
         << input1 << ")\n";
    while (!g.points.empty())
    {
        cout << g.points.front() << " --> ";
        g.points.pop();
    }
    cout << "end" << endl;
    return 0;
}

void gauss_jordan(vector<vector<double>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < 2; i++) // modified loop
    {
        double pivot = matrix[i][i];

        for (int k = i; k < n; k++)
        {
            matrix[i][k] /= pivot;
        }

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                double factor = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k < n; k++)
                {
                    matrix[j][k] -= factor * matrix[i][k];
                }
                matrix[j][i] = 0;
            }
        }

        cout << "Iteration " << i + 1 << ":\n";
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

int guassian_driver()
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

int main()
{
    int x;
    cout << "Enter an operation " << endl;
    cout << " [1] DFS " << endl;
    cout << " [2] BFS " << endl;
    cout << " [3] Guassian Calculator " << endl;
    cout << "INPUT : " ;
    cin >> x;

    switch (x)
    {
    case 1:
        // DFS();
        dfs_driver();
        break;
    case 2:
        // BFS();
        break;
    case 3:
        guassian_driver();
        break;
    default:
        cout << "invalid input";
    }
}
