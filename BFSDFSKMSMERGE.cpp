// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <bits/stdc++.h>
using namespace std;
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    queue<int> points;
    // function to add an edge to graph
    void addEdge(int v, int w);
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void BFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    bool exist = false;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if(*i == w){
            cout<<"Given Vertex already exist"<<endl;
            exist = true;
        }
    }
    if(!exist)
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    points.push(v);
    list<int>::iterator i;
    cout << "Vertex " <<v<< " is visited" << endl;
    cout << "Following are points connected to vertex "<<v<<":\n[";
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        cout<<*i<<" ";
    cout<<"]"<<endl;
    // Recur for all the vertices adjacent
    // to this vertex
    
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            cout<<"We go to: ["<<*i<<"]"<<endl;
            DFS(*i);
        }
    }
    
}

void Graph::BFS(int v)
{
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited [" << currVertex << "]"<<endl;
        queue.pop_front();
        points.push(currVertex);
        cout << "Following are points connected to vertex "<<currVertex<<":\n[";
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            cout<<*i<<" ";
        cout<<"]"<<endl;

        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                cout<<"Push "<<*i<<" to Queue and set as VISITED"<<endl;
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}
 
// Driver's code
int main()
{
    // Create a graph given in the above diagram


    //gets mo itong buong line ito before dun sa g.addedge() para dun sa inputs and graph initialization
    //patanggal na lng ung /* & */ starting sa while tsaka ung // ng cout<<[if you wish to stop etc.]
    Graph g;
    int input1, input2;
    //cout<<"[If you wish to stop, enter a vertex or point that are less than 0]"<<endl;
    /*while(input1 >= 0 || input2 >= 0){
        cout<<"Enter A Vertex and point:[eg. 2 4]: ";
        cin >> input1 >> input2;
        if(input1 >= 0 || input2 >= 0)
        g.addEdge(input1, input2);
    }*/



    //sample test, wag mo na ito gets, eto ung parang insta initialized data para di need ng one by one input for testing
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);



    //etong separated na statement para sa starting vertex input, gets mo ito para madetermine starting vertex
    /*cout<<"Enter a starting vertex: ";
    cin >> input1;*/



    //pang dfs
    //replace mo na lang ung 2 sa function DFS() sa baba ng "input1"
    cout<<"DFS:"<<endl<<endl;
    if(!g.visited.empty())
        g.visited.clear();
    if(!g.points.empty())
        while(g.points.empty())
            g.points.pop();
    g.DFS(2);
    cout << "\nFollowing is Depth First Traversal"
            " (starting from vertex "<<input1<<")\n";
    while(!g.points.empty()){
        cout<<g.points.front()<<" --> ";
        g.points.pop();
    }
    cout<<"end"<<endl;


    //pang bfs
    //replace mo na lang ung 2 sa function BFS() sa baba ng "input1"
    cout<<"BFS:"<<endl<<endl;
    if(!g.visited.empty())
        g.visited.clear();
    if(!g.points.empty())
        while(g.points.empty())
            g.points.pop();
    g.BFS(2);
    cout << "\nFollowing is Breadth First Traversa;"
            " (starting from vertex "<<input1<<")\n";
    while(!g.points.empty()){
        cout<<g.points.front()<<" --> ";
        g.points.pop();
    }
    cout<<"end"<<endl;


    return 0;
}
