#include <bits/stdc++.h>
using namespace std;
int tab[(1 << 15) + 5];

bool ans = true;
int count(int l, int r) {
  if (l == r) return tab[l];
  int m = (l + r) >> 1;
  int cntl = count(l, m);
  int cntr = count(m + 1, r);
  if (abs(cntl - cntr) > 1) ans = false;
  return cntl + cntr;
}

int main() {
  int n, k;
  cin >> n >> k;
  while (n--) {
    for (int i = 0; i < 1 << k; i++) {
      scanf("%d", &tab[i]);
    }
    ans = true;
    count(0, (1 << k) - 1);
    printf("%s", ans ? "yes\n" : "no\n");
  }
}