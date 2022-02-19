#include <bits/stdc++.h>
#define matrix vector<vector<int>>
#define ll long long
using namespace std;

matrix base{{1, 0, 1}, {1, 0, 0}, {0, 1, 1}};
int mod = 100000007;

matrix mul(matrix a, matrix b) {
  matrix ans(3, vector<int>(3, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        ans[i][j] += ((ll)a[i][k] * (ll)b[k][j]) % mod;
        ans[i][j] %= mod;
      }
    }
  }
  return ans;
}

matrix solve(ll n) {
  if (n == 1) return base;
  matrix a = solve(n >> 1);
  if (n & 1) {
    return mul(mul(a, a), base);
  }
  return mul(a, a);
}

int main() {
  ll n;
  cin >> n;
  n -= 2;
  matrix x = solve(n);
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ans += x[i][j];
      if (i == 2) ans += x[i][j];
      ans %= mod;
    }
  }
  printf("%d", ans);
}