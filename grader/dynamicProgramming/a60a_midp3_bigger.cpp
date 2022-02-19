#include <bits/stdc++.h>
using namespace std;

int dp[10005];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 3; i < n + 3; i++) {
    int x;
    scanf("%d", &x);
    dp[i] = max(dp[i - 3] + x, dp[i - 1]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}