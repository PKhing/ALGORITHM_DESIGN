#include <bits/stdc++.h>
using namespace std;

int l[200005], r[200005];
int dp[200005][2][55];

int main() {
  int n, w, k;
  cin >> n >> w >> k;

  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]);

  if (k == n) {
    for (int i = 1; i <= n; i++) {
      dp[i][0][0] = max((i - w - 1 > 0 ? dp[i - w - 1][1][0] : 0) + l[i],
                        dp[i - 1][0][0]);
      dp[i][1][0] = max((i - w - 1 > 0 ? dp[i - w - 1][0][0] : 0) + r[i],
                        dp[i - 1][1][0]);
    }
    printf("%d", max(dp[n][0][0], dp[n][1][0]));
  } else {
    for (int j = 1; j <= k; j++) {
      for (int i = 1; i <= n; i++) {
        dp[i][0][j] = max((i - w - 1 > 0 ? dp[i - w - 1][1][j - 1] : 0) + l[i],
                          dp[i - 1][0][j]);
        dp[i][1][j] = max((i - w - 1 > 0 ? dp[i - w - 1][0][j - 1] : 0) + r[i],
                          dp[i - 1][1][j]);
      }
    }
    printf("%d", max(dp[n][0][k], dp[n][1][k]));
  }
}