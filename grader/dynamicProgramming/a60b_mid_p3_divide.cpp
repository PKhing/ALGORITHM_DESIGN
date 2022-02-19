#include <bits/stdc++.h>
using namespace std;

int dp[505][505];
int mod = 1997;

int main() {
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j - 1] + (dp[i - 1][j] * j) % mod;
      dp[i][j] %= mod;
    }
  }
  cout << dp[n][k];
}