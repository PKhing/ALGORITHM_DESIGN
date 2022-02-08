#include <bits/stdc++.h>
using namespace std;

int tab[1005];
int n, m;

bool query(int x, int l) {
  int r = n - 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (tab[m] == x) return true;
    if (tab[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  while (m--) {
    int q;
    scanf("%d", &q);
    bool ans = false;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (q - tab[i] - tab[j] < tab[j]) break;
        if (query(q - tab[i] - tab[j], j + 1)) {
          ans = true;
          break;
        }
      }
      if (ans) break;
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}