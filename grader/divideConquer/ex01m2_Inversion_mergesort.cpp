#include <bits/stdc++.h>
#define ll long long
using namespace std;
int tab[100005];
int tmp[100005];
ll ans = 0;

void mergesort(int l, int r) {
  if (l == r) return;
  int m = (l + r) / 2;
  mergesort(l, m);
  mergesort(m + 1, r);
  int p1 = l, p2 = m + 1, p = 0;
  while (p1 <= m && p2 <= r) {
    if (tab[p1] > tab[p2]) {
      tmp[p++] = tab[p2++];
      ans += m - p1 + 1;
    } else {
      tmp[p++] = tab[p1++];
    }
  }

  while (p1 <= m) {
    tmp[p++] = tab[p1++];
  }

  while (p2 <= r) {
    tmp[p++] = tab[p2++];
  }

  for (int i = 0; i < p; i++) {
    tab[l + i] = tmp[i];
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  mergesort(0, n - 1);
  cout << ans;
}