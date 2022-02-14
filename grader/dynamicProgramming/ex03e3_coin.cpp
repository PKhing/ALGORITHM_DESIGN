#include <bits/stdc++.h>
using namespace std;
int dp[25][10005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = 1e9;
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j <= m; j++) {
      dp[i][j] = min(dp[i - 1][j], j - x >= 0 ? dp[i][j - x] + 1 : (int)1e9);
    }
  }
  printf("%d", dp[n][m]);
}