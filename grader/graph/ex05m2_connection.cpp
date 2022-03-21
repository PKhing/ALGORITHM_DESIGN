#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

vector<int> edge[1005];
bool visited[1005];

int find(int u, int k) {
  queue<ii> q;
  int ans = 0;
  q.emplace(u, 0);
  while (!q.empty()) {
    int u = q.front().first, l = q.front().second;
    q.pop();
    if (visited[u]) continue;
    visited[u] = 1;

    ans++;
    if (l == k) continue;
    for (auto v : edge[u]) {
      q.emplace(v, l + 1);
    }
  }
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < n; i++) visited[i] = false;
    ans = max(ans, find(i, k));
  }
  printf("%d ", ans);
}