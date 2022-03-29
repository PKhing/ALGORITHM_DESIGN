#include <bits/stdc++.h>
using namespace std;

struct edge {
  int u, v, w;
  edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const edge &ot) const { return w < ot.w; }
};

int par[1005];
int root(int i) {
  while (i != par[par[i]]) {
    par[i] = par[par[i]];
    i = par[par[i]];
  }
  return i;
}

int main() {
  int n;
  cin >> n;
  vector<edge> e;
  for (int i = 0; i < n; i++) {
    par[i] = i;
    for (int j = i + 1; j < n; j++) {
      int w;
      scanf("%d", &w);
      e.emplace_back(i, j, w);
    }
  }
  sort(e.begin(), e.end());
  int ans = 0;
  for (auto x : e) {
    if (root(x.u) != root(x.v)) {
      par[root(x.u)] = root(x.v);
      ans += x.w;
    }
  }
  printf("%d", ans);
}