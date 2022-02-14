#include <bits/stdc++.h>
using namespace std;
int tab[105][105];
int dp[105][105];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      scanf("%d", &tab[i][j]);
    }
  }
  dp[0][0] = tab[0][0];
  int ans = tab[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = max(j > 0 ? dp[i - 1][j - 1] : 0, dp[i - 1][j]) + tab[i][j];
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}