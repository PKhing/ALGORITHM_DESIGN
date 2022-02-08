#include <bits/stdc++.h>
using namespace std;
int solve(int l, int r, int x) {
  if (r < l) return 0;
  if (l == r) return 1;
  if (x & 1 == x) return x;

  int cnt = 0, i = x >> 1;
  while (i > 0) {
    i >>= 1;
    cnt++;
  }

  int m = 1 << cnt;
  if (l == 1 && r == (m << 1) - 1) return x;

  int left = solve(l, min(m - 1, r), x >> 1);
  int middle = l <= m && r >= m && (x & 1);
  int right = solve(max(l - m, 1), r - m, x >> 1);
  return left + middle + right;
}

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  cout << solve(l, r, n);
}