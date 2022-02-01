#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> tab(n);
  for (int i = 0; i < n; i++) scanf("%d", &tab[i]);
  sort(tab.begin(), tab.end());
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    int ans = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (tab[m] <= x) {
        ans = tab[m];
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    printf("%d\n", ans);
  }
}