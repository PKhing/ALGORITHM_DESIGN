#include <bits/stdc++.h>
#define ii pair<int, int>
#define f first
#define s second

using namespace std;

int dist(ii a, ii b) {
  return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

int closest(vector<ii>& x, vector<ii>& y, int l, int r) {
  if (l == r) return 1e9;
  int m = (l + r) >> 1;

  // divide
  vector<ii> yl, yr;
  for (auto& p : y) {
    if (make_pair(p.s, p.f) <= x[m])
      yl.push_back(p);
    else
      yr.push_back(p);
  }

  int d = min(closest(x, yl, l, m), closest(x, yr, m + 1, r));

  // conquer
  vector<ii> ynear;
  for (auto& p : yr) {
    if (p.s < x[m].f + d) ynear.push_back(p);
  }

  auto ptr =
      lower_bound(x.begin() + l, x.begin() + m + 1, make_pair(x[m].f - d, 0));
  while (ptr != x.begin() + m + 1) {
    auto st = lower_bound(ynear.begin(), ynear.end(), make_pair(ptr->s - d, 0));
    auto ed = upper_bound(ynear.begin(), ynear.end(),
                          make_pair(ptr->s + d, (int)1e9));

    while (st != ed) {
      d = min(d, dist(*ptr, make_pair(st->s, st->f)));
      st++;
    }
    ptr++;
  }

  return d;
}

int main() {
  int n;
  cin >> n;
  vector<ii> x(n), y(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i].first, &x[i].second);
    y[i] = make_pair(x[i].s, x[i].f);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  cout << closest(x, y, 0, n - 1);
}