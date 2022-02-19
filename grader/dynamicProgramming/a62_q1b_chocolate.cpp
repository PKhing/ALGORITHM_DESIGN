#include <bits/stdc++.h>
using namespace std;

int dp[10005];
int tab[25];
int mod = 1000003;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) scanf("%d", &tab[i]);
  dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      if (i - tab[j] >= 0) {
        dp[i] += dp[i - tab[j]];
        dp[i] %= mod;
      }
    }
  }
  printf("%d", dp[n]);
}