#include <bits/stdc++.h>
using namespace std;
int tab[100005];
int main() {
  int n, d;
  cin >> n >> d;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tab[i]);
    mx = max(mx, tab[i] - tab[i - 1]);
  }

  int l = mx, r = 1e9;
  int ans = -1, cntans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      if (sum < tab[i]) {
        cnt++;
        sum = tab[i - 1] + m;
      }
    }
    if (cnt <= d) {
      ans = m;
      cntans = cnt;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << ' ' << cntans;
}