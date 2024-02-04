#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define N 5

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

int minDistance(int dist[], bool sptSet[])
{
    int min = INF, min_index;
    for (int v = 0; v < N; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int parent[], int src, int end)
{
    cout << "Vertex\t Distance\tPath";
    cout << "\n"
         << src << " -> " << end << " \t\t " << dist[end] << "\t\t" << src;
    printPath(parent, end);
}

pair<int *, int *> dijkstra(int graph[N][N], int src)
{
    static int dist[N];
    static int parent[N];
    bool sptSet[N];
    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
        dist[i] = INF;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    return make_pair(dist, parent);
}

int main()
{
    int graph[N][N] = {{0, 4, 0, 2, 0},
                       {4, 0, 1, 7, 3},
                       {0, 1, 0, 0, 5},
                       {2, 7, 0, 0, 6},
                       {0, 3, 5, 6, 0}};

    int start, end;
    cout << "Enter the start vertex: ";
    cin >> start;
    cout << "Enter the end vertex: ";
    cin >> end;
    pair<int *, int *> results = dijkstra(graph, start);
    printSolution(results.first, results.second, start, end);
    return 0;
}
