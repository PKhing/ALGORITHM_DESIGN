#include <bits/stdc++.h>
using namespace std;
vector<int> edge[50005];

int cnt[50005][40];
int ans[40];

void solve(int u) {
  cnt[u][0] = 1;

  if (edge[u].size() == 0) return;

  int l = edge[u][0], r = edge[u].size() > 1 ? edge[u][1] : 0;

  solve(l);
  if (r) solve(r);

  for (int i = 0; i < 20; i++) {
    cnt[u][i + 1] += cnt[l][i] + cnt[r][i];
  }

  // calculate
  if (edge[u].size() > 1) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        ans[i + j + 2] += cnt[l][i] * cnt[r][j];
      }
    }
  }

  for (int i = 0; i < 20; i++) ans[i] += cnt[u][i];
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edge[a].push_back(b);
  }
  solve(1);
  printf("%d", ans[k]);
}