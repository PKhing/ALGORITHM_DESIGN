#include <bits/stdc++.h>
using namespace std;

int dp[15][10005];
int tab[15];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) scanf("%d", &tab[i]);
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 1e9;
    }
  }
  dp[0][0] = 0;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 1; k <= 100; k++) {
        if (j - k * k < 0) break;
        dp[i][j] =
            min(dp[i][j], dp[i - 1][j - k * k] + (k - tab[i]) * (k - tab[i]));
      }
    }
  }
  printf("%d", dp[m][n] == 1e9 ? -1 : dp[m][n]);
}