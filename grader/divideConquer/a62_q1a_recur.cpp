#include <bits/stdc++.h>
using namespace std;
int tab[1 << 9][1 << 9];

void generate(int l, int r, int u, int d, int a, int b) {
  if (a == 0) {
    tab[u][l] = b;
    return;
  }
  int mx = (l + r) >> 1;
  int my = (u + d) >> 1;
  generate(l, mx, u, my, a - 1, b);
  generate(mx + 1, r, u, my, a - 1, b - 1);
  generate(l, mx, my + 1, d, a - 1, b + 1);
  generate(mx + 1, r, my + 1, d, a - 1, b);
}

int main() {
  int a, b;
  cin >> a >> b;
  generate(0, (1 << a) - 1, 0, (1 << a) - 1, a, b);
  for (int i = 0; i < 1 << a; i++) {
    for (int j = 0; j < 1 << a; j++) {
      printf("%d ", tab[i][j]);
    }
    printf("\n");
  }
}