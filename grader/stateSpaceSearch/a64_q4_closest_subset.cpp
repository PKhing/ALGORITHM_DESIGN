#include <bits/stdc++.h>
using namespace std;
int tab[105];
int ans = 1e9;
int n, m, k;

void solve(int i, int sum, int m) {
  if (m == 0) {
    ans = min(ans, abs(sum - k));
    return;
  }
  if (n - i < m) return;
  if (sum >= k + ans) return;
  if (i == n) return;
  solve(i + 1, sum + tab[i], m - 1);
  solve(i + 1, sum, m);
}

int main() {
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  sort(tab, tab + n, [](int a, int b) { return a > b; });
  solve(0, 0, m);
  printf("%d", ans);
}