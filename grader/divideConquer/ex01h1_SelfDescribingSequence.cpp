#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> length(3);

int get(int x) {
  int l = 1, r = length.size() - 1;
  int ans = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (x <= length[m]) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main() {
  length[1] = 1;
  length[2] = 3;
  int i = 2;
  while (i++) {
    length.push_back(length.back() + get(i));
    if (length.back() >= 2e9) break;
  }

  int q;
  cin >> q;
  while (q--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", get(n));
  }
}