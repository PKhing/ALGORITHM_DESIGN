#include <bits/stdc++.h>
using namespace std;

struct edge {
  int u, v, w;
  edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<edge> e;

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  vector<int> dist(n, 1e9);
  dist[s] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    e.emplace_back(u, v, w);
  }
  bool change = false;
  for (int i = 0; i < n; i++) {
    change = false;
    for (auto x : e) {
      if (dist[x.u] + x.w < dist[x.v]) {
        dist[x.v] = dist[x.u] + x.w;
        change = true;
      }
    }
  }
  if (change)
    printf("-1");
  else {
    for (int i = 0; i < n; i++) printf("%d ", dist[i]);
  }
}