#include <bits/stdc++.h>
using namespace std;

int calculate(int x, int n, int k) {
  if (n == 1) return x % k;
  int result = calculate(x, n >> 1, k) % k;
  return ((result * result) % k * (n & 1 ? x : 1)) % k;
}

int main() {
  int x, n, k;
  cin >> x >> n >> k;
  int ans = 1;
  cout << calculate(x, n, k);
}