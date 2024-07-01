#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void make_adjList(int n, vector<vector<int>> &v)
{
    map<int, vector<int>> adjList;
    for (vector<int> edge : v)
    {
        adjList[edge[0]].push_back(edge[1]);
        if (edge[0]!= edge[1])
        {
            adjList[edge[1]].push_back(edge[0]);
        }
    }
    for (auto it = adjList.begin(); it!= adjList.end(); it++)
    {
        cout << it->first << ": ";
        for (int x : it->second)
        {
            cout << x << ", ";
        }
        cout << "\n";
    }
}

void make_graph(int n, vvi edges)
{
    vvi adj_matrix(n, vi(n, 0));

    for (vi edge : edges)
    {
        if (edge[0] < n && edge[1] < n)
        {
            adj_matrix[edge[0]][edge[1]] = 1;
            adj_matrix[edge[1]][edge[0]] = 1;
        }
    }

    for (vi r : adj_matrix)
    {
        for (int val : r)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void bfs(int start, map<int, vector<int>> &adjList)
{
    vector<bool> visited(adjList.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int neighbor : adjList[curr])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 5}, {3, 4}, {6, 6}};
    make_adjList(n, edges);
    make_graph(n, edges);

    map<int, vector<int>> adjList;
    for (vector<int> edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        if (edge[0]!= edge[1])
        {
            adjList[edge[1]].push_back(edge[0]);
        }
    }

    cout << "BFS Traversal: ";
    bfs(0, adjList);

    return 0;
}
