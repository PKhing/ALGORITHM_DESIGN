#include <bits/stdc++.h>
using namespace std;

int order[1005], sum[1005];
int q, n;

int get(int st, int ed) {
  if (st > ed) swap(st, ed);
  return min(sum[ed] - sum[st], sum[st] + sum[n] - sum[ed]);
}

int main() {
  cin >> q >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &order[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  while (q--) {
    int st, ed;
    cin >> st >> ed;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += min({get(order[i], order[i % n + 1]),
                  get(order[i], st) + get(order[i % n + 1], ed),
                  get(order[i], ed) + get(order[i % n + 1], st)});
    }
    printf("%d\n", ans);
  }
}