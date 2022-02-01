#include <bits/stdc++.h>
#define ll long long
using namespace std;
int tab[100005];
int t[1000005 << 2];

void update(int p, int v) {
  for (int i = p + 1000005; i < 1000005 << 1; i += i & -i) t[i] += v;
}

int query(int p) {
  int ans = 0;
  for (int i = p + 1000005; i > 0; i -= i & -i) ans += t[i];
  return ans;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
    update(tab[i], 1);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += query(tab[i] - 1);
    update(tab[i], -1);
  }
  cout << ans;
}