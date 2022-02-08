#include <bits/stdc++.h>
using namespace std;
int solve(int x, int n, int cnt) {
  if (x == (x & 1)) return x & 1;
  return min((x / n) * cnt + solve(x % n, n / 10, cnt - 1),
             ((x / n) + 1) * cnt + solve(n - x % n, n / 10, cnt - 1));
}

int main() {
  int x, n = 1, cnt = 1;
  cin >> x;
  while (n <= x) {
    n = n * 10 + 1;
    cnt++;
  }
  cout << solve(x, n, cnt);
}