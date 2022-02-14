#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      scanf(" %c", &c);
      if (c == '1')
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
}