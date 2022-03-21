#include <bits/stdc++.h>
using namespace std;
vector<int> edge[1005];
bool visited[1005];

bool dfs(int u, int par) {
  if (visited[u]) return true;
  visited[u] = 1;
  for (auto v : edge[u]) {
    if (v != par) {
      if (dfs(v, u)) return true;
    }
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) edge[i].clear(), visited[i] = false;
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    bool ans = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i] && dfs(i, -1)) {
        ans = 1;
        break;
      }
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}