#include <bits/stdc++.h>
using namespace std;

int val[2005];

struct edge {
  int u, v, w;
  edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const edge &ot) const { return w > ot.w; }
};

int par[2005];

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
  for (int i = 0; i < n; i++) scanf("%d", &val[i]);
  for (int i = 0; i < n; i++) {
    par[i] = i;
    for (int j = 1; j < n; j++) {
      e.emplace_back(i, j, val[i] ^ val[j]);
    }
  }
  sort(e.begin(), e.end());
  long long ans = 0;
  for (auto x : e) {
    if (root(x.u) != root(x.v)) {
      par[root(x.u)] = root(x.v);
      ans += x.w;
    }
  }
  printf("%lld", ans);
}