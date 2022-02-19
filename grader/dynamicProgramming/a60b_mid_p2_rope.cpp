#include <bits/stdc++.h>
using namespace std;

int dp[4][4005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= 3; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = -1e9;
  for (int i = 1; i <= 3; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= n; j++) {
      dp[i][j] =
          max(dp[i - 1][j], max(j - x >= 0 ? dp[i - 1][j - x] + 1 : (int)-1e9,
                                j - x >= 0 ? dp[i][j - x] + 1 : (int)-1e9));
    }
  }
  cout << dp[3][n];
}