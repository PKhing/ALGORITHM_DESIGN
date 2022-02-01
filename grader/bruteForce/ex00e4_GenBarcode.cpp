#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> k >> n;
  vector<int> ans(n);
  for (int i = n - k; i < n; i++) {
    ans[i] = 1;
  }
  do {
    for (auto x : ans) cout << x;
    cout << '\n';
  } while (next_permutation(ans.begin(), ans.end()));
}