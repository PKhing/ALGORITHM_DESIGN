#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int dist[2005], val[2005];
bool visited[2005];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &val[i]);
  priority_queue<ii> q;
  q.emplace(0, 0);
  long long ans = 0;
  while (!q.empty()) {
    int w = q.top().first;
    int u = q.top().second;
    q.pop();
    if (visited[u]) continue;
    visited[u] = 1;
    ans += w;
    for (int i = 0; i < n; i++) {
      if (!visited[i] && (dist[i] < (val[u] ^ val[i]))) {
        dist[i] = val[u] ^ val[i];
        q.emplace(dist[i], i);
      }
    }
  }
  printf("%lld", ans);
}
