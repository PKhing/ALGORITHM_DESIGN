#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[100005];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &sum[i]);
    sum[i] += sum[i - 1];
  }
  ll ans = sum[1];
  ll mn = 0;
  for (int i = 2; i <= n; i++) {
    ans = max(ans, sum[i] - mn);
    mn = min(mn, sum[i]);
  }
  cout << ans;
}