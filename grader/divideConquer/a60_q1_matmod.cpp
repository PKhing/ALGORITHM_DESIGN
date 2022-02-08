#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> x(4);

vector<int> multiply(vector<int> a, vector<int> b) {
  vector<int> ans(4);
  ans[0] = (a[0] * b[0] + a[1] * b[2]) % k;
  ans[1] = (a[0] * b[1] + a[1] * b[3]) % k;
  ans[2] = (a[2] * b[0] + a[3] * b[2]) % k;
  ans[3] = (a[2] * b[1] + a[3] * b[3]) % k;
  return ans;
}

vector<int> solve(int n) {
  if (n == 1) return x;
  vector<int> a = solve(n >> 1);
  if (n & 1) return multiply(x, multiply(a, a));
  return multiply(a, a);
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < 4; i++) cin >> x[i];
  for (auto x : solve(n)) {
    cout << x << ' ';
  }
}
