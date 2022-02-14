#include <bits/stdc++.h>
using namespace std;

int dp[35][35][35];

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 1; k <= m; k++) {
        dp[i][j][k] += dp[i - 1][j][k - 1];
        if (j > 0) dp[i][j][1] += dp[i - 1][j - 1][k];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans += dp[n][x][i];
  }
  printf("%d", ans);
}