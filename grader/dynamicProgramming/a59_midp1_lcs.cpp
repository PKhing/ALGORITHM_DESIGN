#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
string a, b, ans;
void solve(int i, int j) {
  if (i == 0 || j == 0) return;

  if (a[i - 1] == b[j - 1]) {
    solve(i - 1, j - 1);
    ans += a[i - 1];
  } else if (dp[i][j] == dp[i - 1][j]) {
    solve(i - 1, j);
  } else {
    solve(i, j - 1);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  cin >> a >> b;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      scanf("%d", &dp[i][j]);
    }
  }
  solve(n, m);
  cout << ans;
}