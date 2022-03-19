#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll tab[500005], ansl[500005], ansr[500005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", &tab[i]);
  ll sum = 0;
  ll mn = 0;
  ll ans = -1e18;
  for (int i = 1; i <= n; i++) {
    sum += tab[i];
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
    ansl[i] = ans;
  }
  sum = 0;
  mn = 0;
  ans = -1e18;
  for (int i = n; i > 0; i--) {
    sum += tab[i];
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
    ansr[i] = ans;
  }

  ans = -1e18;
  for (int i = 1; i <= n; i++) {
    ans = max({ans, ansl[i], ansr[i], ansl[i - 1] + ansr[i]});
  }

  printf("%lld", ans);
}
