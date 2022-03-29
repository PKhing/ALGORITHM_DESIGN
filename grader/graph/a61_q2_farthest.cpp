#include <bits/stdc++.h>
using namespace std;

int edge[1005][1005];
int dist[1005];
int visited[1005];

int main() {
  int n;
  cin >> n;
  vector<int> dist(n, 1e9);
  dist[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &edge[i][j]);
    }
  }

  int u = 0;
  for (int i = 0; i < n; i++) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
      if (edge[u][v] != -1 && dist[v] > dist[u] + edge[u][v])
        dist[v] = dist[u] + edge[u][v];
    }
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      if (!visited[i] && dist[i] < mn) {
        mn = dist[i];
        u = i;
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, dist[i]);
  }
  printf("%d", mx == 1e9 ? -1 : mx);
}