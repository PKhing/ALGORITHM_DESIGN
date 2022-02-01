#include <bits/stdc++.h>
using namespace std;

int n, k;

void generate(int l, int r) {
  int m = (l + r) >> 1;
  if (l == r || k == 1) {
    for (int i = l; i <= r; i++) printf("%d ", i + 1);
    return;
  }
  k -= 2;
  generate(m + 1, r);
  generate(l, m);
}

int main() {
  cin >> n >> k;
  if (!(k & 1) || k > 2 * n - 1) {
    cout << -1;
    exit(0);
  }
  generate(0, n - 1);
}