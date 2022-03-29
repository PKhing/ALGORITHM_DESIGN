#include <bits/stdc++.h>
#define ii pair<int, int>

using namespace std;

vector<int> edge[1005];
int visited[1005];

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  queue<ii> q;
  q.emplace(0, 0);
  int cnt = 0;

  while (!q.empty()) {
    int l = q.front().first;
    int u = q.front().second;
    q.pop();

    if (visited[u]) continue;
    visited[u] = 1;

    if (l == k) {
      cnt++;
      continue;
    }
    for (auto v : edge[u]) {
      q.emplace(l + 1, v);
    }
  }

  printf("%d", cnt);
}