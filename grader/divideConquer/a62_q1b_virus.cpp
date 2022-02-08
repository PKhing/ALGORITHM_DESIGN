#include <bits/stdc++.h>
using namespace std;

int tab[(1 << 8) + 5];

bool check(int l, int r, bool rev) {
  if (l + 1 == r) {
    return rev ? (tab[l] && !tab[r]) : (!tab[l] && tab[r]);
  }
  int m = (l + r) >> 1;

  if (rev)
    return (check(m + 1, r, 0) || check(m + 1, r, 1)) && check(l, m, rev);
  return (check(l, m, 0) || check(l, m, 1)) && check(m + 1, r, rev);
}

int main() {
  int n, k;
  cin >> n >> k;
  while (n--) {
    for (int i = 0; i < 1 << k; i++) {
      scanf("%d", &tab[i]);
    }
    printf("%s", check(0, (1 << k) - 1, 0) ? "yes\n" : "no\n");
  }
}