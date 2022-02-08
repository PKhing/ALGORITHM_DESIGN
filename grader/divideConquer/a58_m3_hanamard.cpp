#include <bits/stdc++.h>
using namespace std;
int tab[(1 << 18) + 5];

vector<int> calculate(int l, int r) {
  vector<int> ans;
  if (l == r) {
    ans.push_back(tab[l]);
    return ans;
  }
  int m = (l + r) >> 1;
  vector<int> a = calculate(l, m);
  vector<int> b = calculate(m + 1, r);
  for (int i = 0; i < a.size(); i++) {
    ans.push_back(a[i] + b[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    ans.push_back(a[i] - b[i]);
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  vector<int> ans = calculate(0, n - 1);
  for (auto x : ans) {
    printf("%d ", x);
  }
}