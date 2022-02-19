#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    dp[i] =
        max(dp[max(i - 1, 0)], max(dp[max(i - 2, 0)], dp[max(i - 3, 0)])) + x;
  }

  printf("%d", dp[n - 1]);
}