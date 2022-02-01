#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t[1005];
int main() {
  int n, a;
  cin >> n >> a;
  for (int i = 0; i < n; i++) scanf("%d", &t[i]);
  for (int i = 0; i < a; i++) {
    ll q = 0;
    scanf("%lld", &q);
    ll ans = -1;
    ll l = 0, r = 1e18;
    while (l <= r) {
      ll m = (l + r) >> 1;
      ll cnt = 0;
      for (int j = 0; j < n; j++) {
        cnt += m / t[j];
      }
      if (cnt < q - n) {
        l = m + 1;
      } else {
        r = m - 1;
        ans = m;
      }
    }
    printf("%lld\n", ans);
  }
}