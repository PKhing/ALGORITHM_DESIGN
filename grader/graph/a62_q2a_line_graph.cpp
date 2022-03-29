#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
bool visited[100005];
bool isLine;

void dfs(int u, int par) {
  if (visited[u]) {
    isLine = false;
    return;
  }
  visited[u] = 1;
  if (edge[u].size() > 2) isLine = false;
  for (auto v : edge[u])
    if (v != par) dfs(v, u);
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
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      isLine = 1;
      dfs(i, -1);
      ans += isLine;
    }
  }
  printf("%d", ans);
}