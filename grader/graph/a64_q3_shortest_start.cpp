#include <bits/stdc++.h>
using namespace std;

int dist[5005];
vector<tuple<int, int, int>> edge;

int main() {
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  for (int i = 0; i < n; i++) dist[i] = 1e9;
  for (int i = 0; i < s; i++) {
    int x;
    scanf("%d", &x);
    dist[x] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge.emplace_back(u, v, w);
  }
  for (int i = 0; i < n; i++) {
    for (auto e : edge) {
      int u, v, w;
      tie(u, v, w) = e;
      dist[v] = min(dist[v], dist[u] + w);
    }
  }
  printf("%d", dist[e]);
}