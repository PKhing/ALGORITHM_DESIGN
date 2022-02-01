#include <bits/stdc++.h>
using namespace std;

void tiling(int lx, int rx, int ly, int ry, int x, int y) {
  if (rx == lx) return;

  int mx = (lx + rx) >> 1;
  int my = (ly + ry) >> 1;

  if (x <= mx && y <= my) {
    tiling(lx, mx, ly, my, x, y);
  } else {
    tiling(lx, mx, ly, my, mx, my);
  }

  if (x > mx && y <= my) {
    tiling(mx + 1, rx, ly, my, x, y);
  } else {
    tiling(mx + 1, rx, ly, my, mx + 1, my);
  }

  if (x <= mx && y > my) {
    tiling(lx, mx, my + 1, ry, x, y);
  } else {
    tiling(lx, mx, my + 1, ry, mx, my + 1);
  }

  if (x > mx && y > my) {
    tiling(mx + 1, rx, my + 1, ry, x, y);
  } else {
    tiling(mx + 1, rx, my + 1, ry, mx + 1, my + 1);
  }

  printf("%d %d %d\n", (x > mx) + (y > my) * 2, mx, my);
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  printf("%d\n", (n * n) / 3);
  tiling(0, n - 1, 0, n - 1, x, y);
}