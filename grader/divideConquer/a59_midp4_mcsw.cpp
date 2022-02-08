#include <bits/stdc++.h>
using namespace std;
int sum[200005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }

  deque<int> q;
  q.push_back(0);
  int ans = -1e9;

  for (int i = 1; i <= n; i++) {
    while (!q.empty() && q.front() < i - k) q.pop_front();
    ans = max(ans, sum[i] - sum[q.front()]);
    while (!q.empty() && sum[i] < sum[q.back()]) q.pop_back();
    q.push_back(i);
  }

  cout << ans;
}