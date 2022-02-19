#include <bits/stdc++.h>
using namespace std;

int sum[1005][1005];

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &sum[i][j]);
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  while (q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    c++;
    d++;
    printf("%d\n", sum[c][d] - sum[a][d] - sum[c][b] + sum[a][b]);
  }
}