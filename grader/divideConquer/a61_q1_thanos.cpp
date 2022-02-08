#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tab;
int p, k, a, b;

ll solve(int l, int r) {
  ll cnt = upper_bound(tab.begin(), tab.end(), r) -
           lower_bound(tab.begin(), tab.end(), l);

  if (cnt == 0) return a;
  if (l == r) return b * cnt * (r - l + 1);

  int m = (l + r) >> 1;
  return min(b * cnt * (r - l + 1), solve(l, m) + solve(m + 1, r));
}

int main() {
  cin >> p >> k >> a >> b;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    tab.push_back(x);
  }
  sort(tab.begin(), tab.end());
  cout << solve(1, 1 << p);
}