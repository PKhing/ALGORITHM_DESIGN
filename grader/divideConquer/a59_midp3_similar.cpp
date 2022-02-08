#include <bits/stdc++.h>
using namespace std;
string a, b;

bool solve(int la, int ra, int lb, int rb) {
  if (la == ra) return a[la] == b[lb];
  int ma = (la + ra) >> 1;
  int mb = (lb + rb) >> 1;
  return (solve(la, ma, lb, mb) && solve(ma + 1, ra, mb + 1, rb)) ||
         (solve(la, ma, mb + 1, rb) && solve(ma + 1, ra, lb, mb));
}

int main() {
  cin >> a >> b;
  cout << (solve(0, a.length() - 1, 0, b.length() - 1) ? "YES" : "NO");
}