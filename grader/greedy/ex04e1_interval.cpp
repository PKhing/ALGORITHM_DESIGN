#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool cmp(ii a, ii b) { return a.second < b.second; }
int main() {
  int n;
  cin >> n;
  ii t[n];
  for (int i = 0; i < n; i++) scanf("%d", &t[i].first);
  for (int i = 0; i < n; i++) scanf("%d", &t[i].second);
  sort(t, t + n, cmp);
  int last = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (t[i].first >= last) {
      last = t[i].second;
      cnt++;
    }
  }
  cout << cnt;
}