#include <bits/stdc++.h>
using namespace std;

int ans = 0;
void solve(int sum, int before) {
  if (sum == 0) {
    ans++;
    return;
  }
  for (int i = before; i <= sum; i++) {
    solve(sum - i, i);
  }
}

int main() {
  int n;
  cin >> n;
  solve(n, 1);
  printf("%d", ans);
}