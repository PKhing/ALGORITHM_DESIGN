#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < 1 << n; i++) {
    int cnt = 0;
    for (int j = n - 1; j >= 0; j--) {
      if ((i >> j) & 1)
        cnt++;
      else
        cnt = 0;
      if (cnt == k) break;
    }
    if (cnt == k) {
      for (int j = n - 1; j >= 0; j--) cout << ((i >> j) & 1);
      cout << '\n';
    }
  }
}