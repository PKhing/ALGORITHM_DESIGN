#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>

using namespace std;
matrix base = {{1, 2}, {1, 1}};
const int mod = 100000007;

matrix mul(matrix &a, matrix &b) {
  matrix c(2, vector<ll>(2, 0));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mod;
      }
  return c;
}

matrix solve(int n) {
  if (n == 1) return base;
  matrix half = solve(n >> 1);
  matrix ans = mul(half, half);
  if (n & 1) return mul(ans, base);
  return ans;
}

int main() {
  int n;
  cin >> n;
  matrix result = solve(n - 1);
  ll ans = (result[0][0] + result[0][1] + 2 * (result[1][0] + result[1][1]));
  printf("%lld", ans % mod);
}