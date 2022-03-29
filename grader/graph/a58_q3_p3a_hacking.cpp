#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int c[50005];
vector<int> edge[50005];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> dist(n, 1e9);
  vector<int> f;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    f.push_back(x);
  }
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  priority_queue<ii, vector<ii>, greater<ii>> q;
  for (auto u : f) {
    dist[u] = c[u];
    q.emplace(c[u], u);
  }
  while (!q.empty()) {
    int u = q.top().second;
    int l = q.top().first;
    q.pop();
    if (dist[u] != l) continue;
    for (auto v : edge[u]) {
      if (dist[v] > dist[u] + c[v]) {
        dist[v] = dist[u] + c[v];
        q.emplace(dist[v], v);
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) mx = max(mx, dist[i]);
  printf("%d", mx);
}