#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
vector<pair<int, int>> edge[25];
bool visited[25];
int query[8];
int found = false;
int n, m;

int summx() {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i] && edge[i].size() > 0) sum += edge[i][0].second;
  }
  return sum;
}

void dfs(int u, int sum, int q) {
  if (found) return;
  if (sum == q) {
    found = true;
    return;
  }
  if (sum > q) return;
  visited[u] = 1;
  if (sum + summx() < q) {
    visited[u] = 0;
    return;
  }

  for (auto v : edge[u]) {
    if (!visited[v.first]) dfs(v.first, sum + v.second, q);
  }
  visited[u] = 0;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < 8; i++) {
    cin >> query[i];
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  for (int i = 0; i < n; i++)
    sort(edge[i].begin(), edge[i].end(),
         [](ii a, ii b) { return a.second > b.second; });

  for (int i = 0; i < 8; i++) {
    found = false;
    for (int j = 0; j < n; j++) {
      dfs(j, 0, query[i]);
    }
    printf("%s\n", found ? "YES" : "NO");
  }
}
