#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<ll> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  };
  while (q--) {
    int st;
    ll cost;
    ll ans = 0;
    scanf("%d %lld", &st, &cost);
    int l = st + 1, r = n;
    while (l <= r) {
      int m = (l + r) >> 1;
      if ((ll)(sum[m] - sum[st]) + (ll)(m - st) * k <= cost) {
        ans = max(ans, sum[m] - sum[st]);
        l = m + 1;
      } else
        r = m - 1;
    }
    printf("%d\n", ans);
  }
}