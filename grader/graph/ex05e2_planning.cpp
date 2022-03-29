#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1005];
int deg[1005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &deg[i]);
    for (int j = 0; j < deg[i]; j++) {
      int x;
      scanf("%d", &x);
      edge[x].push_back(i);
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    printf("%d ", u);

    for (auto v : edge[u]) {
      if (--deg[v] == 0) q.push(v);
    }
  }
}