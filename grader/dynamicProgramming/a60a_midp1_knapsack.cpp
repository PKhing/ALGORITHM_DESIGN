#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int w[505], v[505];
vector<int> ans;

void solve(int i, int j) {
  if (i == 0 || j == 0) return;
  if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
    ans.push_back(i);
    solve(i - 1, j - w[i]);
  } else {
    solve(i - 1, j);
  }
}

int main() {
  int n, k;
  cin >> k >> n;
  for (int i = 1; i <= k; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= k; i++) scanf("%d", &w[i]);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      scanf("%d", &dp[i][j]);
    }
  }
  solve(k, n);
  printf("%d\n", ans.size());
  for (auto x : ans) {
    printf("%d ", x);
  }
}