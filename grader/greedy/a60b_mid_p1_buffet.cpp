#include <bits/stdc++.h>
using namespace std;

int tab[10005];

int main() {
  int f, w, n;
  cin >> f >> w >> n;
  int last = -1, cnt = 0;

  for (int i = 0; i < f; i++) {
    scanf("%d", &tab[i]);
  }
  sort(tab, tab + f);
  for (int i = 0; i < f; i++) {
    if (tab[i] > last) last = tab[i] + 2 * w, cnt++;
  }
  cout << cnt;
}