#include <bits/stdc++.h>
using namespace std;

vector<int> edge[5005];
int val[5005];
int query[5005];
int visited[5005];

int sum = 0;

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  sum -= val[u];
  for (auto v : edge[u]) dfs(v);
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    scanf("%d", &val[i]);
    sum += val[i];
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &query[i]);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
  }
  for (int i = 0; i < q; i++) {
    dfs(query[i]);
    printf("%d ", sum);
  }
}