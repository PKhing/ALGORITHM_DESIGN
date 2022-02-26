#include <bits/stdc++.h>
using namespace std;

double w[100005], v[100005];
priority_queue<pair<double, int>> pq;

int main() {
  int n;
  double sz;
  cin >> sz >> n;
  double ans = 0;
  for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
  for (int i = 0; i < n; i++) scanf("%lf", &w[i]), pq.emplace(v[i] / w[i], i);
  while (!pq.empty() && sz > 0) {
    int i = pq.top().second;
    if (w[i] < sz) {
      sz -= w[i];
      ans += v[i];
    } else {
      ans += v[i] / w[i] * sz;
      sz = 0;
    }
    pq.pop();
  }
  printf("%.04lf", ans);
}