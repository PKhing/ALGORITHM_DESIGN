#include <bits/stdc++.h>
using namespace std;

int tab[50005];

int main() {
  int n, l;
  cin >> n >> l;
  int last = -1, cnt = 0;

  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  sort(tab, tab + n);
  for (int i = 0; i < n; i++) {
    if (tab[i] > last - 1) last = tab[i] + l, cnt++;
  }
  cout << cnt;
}