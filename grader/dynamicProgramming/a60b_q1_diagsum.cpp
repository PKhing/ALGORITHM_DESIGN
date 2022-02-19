#include <bits/stdc++.h>
using namespace std;
int sum[1005][1005];
int main() {
  int n;
  cin >> n;
  int ans = -1e9;

  for (int i = 1; i <= n; i++)
    for (int j = n; j > 0; j--) {
      scanf("%d", &sum[i][j]);
      sum[i][j] += sum[i - 1][j + 1];
    }

  for (int k = 2; k <= 2 * n; k++) {
    int mn = 0;
    for (int i = 1; i < min(k, n + 1); i++) {
      int j = k - i;
      if (j > n) continue;
      ans = max(ans, sum[i][j] - mn);
      mn = min(mn, sum[i][j]);
    }
  }
  printf("%d", ans);
}