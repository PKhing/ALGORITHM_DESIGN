#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 2; i <= n + 1; i++) {
    int x;
    scanf("%d", &x);
    dp[i] = max(dp[i - 1], dp[i - 2] + x);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}