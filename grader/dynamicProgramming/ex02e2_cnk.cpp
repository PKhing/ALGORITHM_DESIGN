#include <bits/stdc++.h>
using namespace std;
int tab[100][100];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i == j || j == 0)
        tab[i][j] = 1;
      else
        tab[i][j] = tab[i - 1][j - 1] + tab[i - 1][j];
    }
  }
  cout << tab[n][k];
}