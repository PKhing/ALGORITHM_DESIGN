#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<ii> tab(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &tab[i].first, &tab[i].second);
  }
  sort(tab.begin(), tab.end());
  stack<ii> ans;
  for (int i = 0; i < n; i++) {
    while (!ans.empty() && tab[i].second > ans.top().second) ans.pop();
    ans.push(tab[i]);
  }
  cout << ans.size();
}