#include <iostream>
using namespace std;

void BFS(int adj[20][20], int n, int s) {
    int visited[20] = {0};
    int queue[20];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    cout << "BFS Traversal: ";
    while (front < rear) {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e, s;
    
    cout << "Total vertices (n) and edges (e) : ";
    if (!(cin >> n >> e)) return 0;

    int adj[20][20] = {0};

    cout << " Enter no. of Edges  (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    cout << "Enter Starting vertex (s) : ";
    cin >> s;

    BFS(adj, n, s);

    return 0;
}