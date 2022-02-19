#include <bits/stdc++.h>
using namespace std;

int sum[200005];

int main() {
  int n, q, m;
  cin >> n >> q >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1] - m;
  }
  while (q--) {
    int st, w;
    scanf("%d %d", &st, &w);
    int l = st, r = n, ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (sum[m] - sum[st - 1] >= w) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    printf("%d\n", ans);
  }
}