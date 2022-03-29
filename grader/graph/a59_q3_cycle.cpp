#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
int depth[100005];
int visited[100005];

void dfs(int u, int par, int d) {
  if (visited[u]) {
    printf("%d", d - depth[u]);
    exit(0);
  }
  visited[u] = 1;
  depth[u] = d;

  for (auto v : edge[u]) {
    if (v != par) dfs(v, u, d + 1);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(0, -1, 0);
}