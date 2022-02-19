#include <bits/stdc++.h>
using namespace std;

int tab[505][505];
int dp[505][505];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &tab[i][j]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]) + tab[i][j],
                     i > 1 && j > 1 ? dp[i - 1][j - 1] + 2 * tab[i][j] : 0);
    }
  }
  printf("%d", dp[n][m]);
}