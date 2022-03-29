#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

struct edge {
  int u, v, w;
  edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator<(const edge &ot) const { return w < ot.w; }
};

vector<edge> e;
priority_queue<ii> query;
int ans[5005];
int par[5005];

int root(int i) {
  while (i != par[par[i]]) {
    par[i] = par[par[i]];
    i = par[par[i]];
  }
  return i;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    e.emplace_back(u, v, w);
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    query.emplace(x, i);
  }
  for (int i = 0; i < n; i++) par[i] = i;
  int component = n;
  while (!query.empty() && query.top().first >= n) {
    ans[query.top().second] = 0;
    query.pop();
  }
  for (auto x : e) {
    if (root(x.u) != root(x.v)) {
      par[root(x.u)] = root(x.v);
      component--;
      while (!query.empty() && query.top().first >= component) {
        ans[query.top().second] = x.w;
        query.pop();
      }
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}