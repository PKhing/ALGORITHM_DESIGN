#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int tab[105];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n + 1; i++) {
    scanf("%d", &tab[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = i == j ? 0 : 1e9;
    }
  }

  for (int len = 1; len < n; len++) {
    for (int i = 0; i + len < n; i++) {
      int j = i + len;
      for (int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] +
                                     tab[i] * tab[k + 1] * tab[j + 1]);
      }
    }
  }

  printf("%d", dp[0][n - 1]);
}