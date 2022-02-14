#include <bits/stdc++.h>
using namespace std;
int tmp[1005];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    auto ptr = upper_bound(tmp, tmp + ans, x);
    if (ptr == tmp + ans) {
      tmp[ans++] = x;
    } else {
      *ptr = x;
    }
  }
  cout << ans;
}