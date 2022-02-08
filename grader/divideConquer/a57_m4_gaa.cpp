#include <bits/stdc++.h>
using namespace std;

int get(int cnt) { return (1 << (cnt + 3)) - cnt - 5; }

char solve(int n) {
  if (n == 1) return 'g';
  if (n == 2 || n == 3) return 'a';
  int cnt = 0;
  while (get(cnt) < n) {
    cnt++;
  }
  if (n == get(cnt - 1) + 1) return 'g';
  if (n <= get(cnt - 1) + cnt + 3) return 'a';
  return solve(n - (get(cnt - 1) + cnt + 3));
}

int main() {
  int n;
  cin >> n;
  cout << solve(n);
}