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

int guassian_driver()
{

}


int main()
{
    int x;
    cout << "Enter an operation: ";
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
        // Guassian():
        break;
    default:
        cout << "invalid input";
    }
}
