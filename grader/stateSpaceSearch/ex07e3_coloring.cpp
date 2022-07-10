#include <bits/stdc++.h>
using namespace std;
bool pass;
vector<int> edge[55];
int color[50];
int n, m;

void solve(int u, int mxcolor) {
  if (pass) return;
  if (u == n) {
    pass = true;
    return;
  }
  for (int i = 1; i <= mxcolor; i++) {
    bool valid = true;
    for (auto v : edge[u]) {
      if (color[v] == i) {
        valid = false;
        break;
      }
    }
    if (valid) {
      color[u] = i;
      solve(u + 1, mxcolor);
      color[u] = 0;
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int l = 1, r = n;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;

    pass = false;
    solve(0, m);
    if (pass) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  printf("%d", ans);
}