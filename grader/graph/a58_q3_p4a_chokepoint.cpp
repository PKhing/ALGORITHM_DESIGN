#include <bits/stdc++.h>
using namespace std;

int sz[100005];
vector<int> edge[100005];
long long ans[100005];

void calculate_sz(int u, int par) {
  for (auto v : edge[u]) {
    if (v == par) continue;
    calculate_sz(v, u);
    sz[u] += sz[v];
  }
  sz[u]++;
}

void solve(int u, int par) {
  vector<int> tmp;
  if (par != -1) tmp.push_back(sz[0] - sz[u]);
  for (auto v : edge[u]) {
    if (v != par) {
      solve(v, u);
      tmp.push_back(sz[v]);
    }
  }
  for (int i = 0; i < tmp.size(); i++) {
    for (int j = i + 1; j < tmp.size(); j++) {
      ans[u] += tmp[i] * tmp[j];
    }
  }
  ans[u] += sz[0] - 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[v].push_back(u);
    edge[u].push_back(v);
  }
  calculate_sz(0, -1);
  solve(0, -1);
  for (int i = 0; i < n; i++) printf("%lld\n", ans[i]);
}