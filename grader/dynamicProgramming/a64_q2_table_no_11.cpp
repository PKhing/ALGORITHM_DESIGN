#include <bits/stdc++.h>
using namespace std;
int dp[10000005][2];
const int mod = 100000007;
int main() {
  int n;
  cin >> n;
  dp[1][0] = dp[1][1] = 1;
  for (int i = 1; i < n; i++) {
    dp[i + 1][0] = (dp[i][0] + (2 * dp[i][1]) % mod) % mod;
    dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
  }
  printf("%d", ((dp[n][1] * 2) % mod + dp[n][0]) % mod);
}