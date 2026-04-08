#include <iostream>
using namespace std;

int graph[20][20];
bool visited[20];

void DFS(int u, int n) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            DFS(v, n);
        }
    }
}

int main() {
    int n, edges;
    cin >> n;
    cin >> edges;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cin >> start;

    DFS(start, n);

    return 0;
}