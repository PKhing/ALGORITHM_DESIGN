#include <bits/stdc++.h>
using namespace std;

vector<int> edge[10005];
bool visited[10005];

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto v : edge[u]) {
    dfs(v);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      ans++;
    }
  }
  printf("%d", ans);
}