#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1, 1e9);
  deque<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (!q.empty() && q.front() < i - 2 * k - 1) q.pop_front();
    if (i <= k)
      dp[i] = x;
    else
      dp[i] = x + dp[q.front()];
    while (!q.empty() && dp[q.back()] > dp[i]) q.pop_back();
    q.push_back(i);
  }
  int ans = 1e9;
  for (int i = max(n - k - 1, 0); i < n; i++) ans = min(ans, dp[i]);
  cout << ans;
}