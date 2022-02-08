#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int dist(ii a, ii b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}

int main() {
  int d = 1e9;
  int n;
  cin >> n;
  vector<ii> tab(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &tab[i].first, &tab[i].second);
  }
  sort(tab.begin(), tab.end());

  set<ii> s;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    auto st = s.lower_bound(make_pair(tab[i].second - d, 0));
    auto ed = s.upper_bound(make_pair(tab[i].second + d, 1e9));

    while (st != ed) {
      d = min(dist(make_pair(st->second, st->first), tab[i]), d);
      st++;
    }

    while (ptr < i && tab[ptr].first < tab[i].first - d) {
      s.erase(make_pair(tab[ptr].second, tab[ptr].first));
      ptr++;
    }

    s.insert(make_pair(tab[i].second, tab[i].first));
  }
  cout << d;
}