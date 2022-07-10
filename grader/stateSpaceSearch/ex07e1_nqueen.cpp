#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
bool isValid(vector<int> &tab, int x) {
  for (int i = 0; i < tab.size(); i++) {
    if (x == tab[i] || x == tab[i] + tab.size() - i ||
        x == tab[i] - tab.size() + i)
      return false;
  }
  return true;
}

void solve(int i, vector<int> &tab) {
  if (i == n) {
    ans++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (isValid(tab, j)) {
      tab.push_back(j);
      solve(i + 1, tab);
      tab.pop_back();
    }
  }
}

int main() {
  cin >> n;
  vector<int> tmp;
  solve(0, tmp);
  printf("%d", ans);
}