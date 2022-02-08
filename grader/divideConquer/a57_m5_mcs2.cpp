#include <bits/stdc++.h>
using namespace std;
int tab[200005];
int sum[400005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
  }
  for (int i = 1; i <= 2 * n; i++) {
    sum[i] = sum[i - 1] + tab[(i - 1) % n];
  }

  deque<int> q;
  q.push_back(0);
  int ans = -1e9;
  for (int i = 1; i <= 2 * n; i++) {
    while (!q.empty() && q.front() < i - n) q.pop_front();
    ans = max(ans, sum[i] - sum[q.front()]);
    while (!q.empty() && sum[i] < sum[q.back()]) q.pop_back();
    q.push_back(i);
  }

  cout << ans;
}