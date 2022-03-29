#include <bits/stdc++.h>
using namespace std;

double tab[505][505];

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lf", &tab[i][j]);
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          tab[i][j] = max(tab[i][j], tab[i][k] * tab[k][j]);
        }
      }
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
      if (tab[i][i] > 1) ans = true;
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
}
