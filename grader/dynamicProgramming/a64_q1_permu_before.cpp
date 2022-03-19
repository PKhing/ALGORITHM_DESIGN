#include <bits/stdc++.h>
using namespace std;

int n, m;
int used[30];
int ans[30];
int before[30];

void solve(int p) {
  if (p == n) {
    for (int i = 0; i < p; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      used[i] = 1;
      ans[p] = i;

      // check
      if (before[i] != -1 && !used[before[i]]) {
        used[i] = 0;
        continue;
      }

      solve(p + 1);
      used[i] = 0;
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) before[i] = -1;

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    before[b] = a;
  }

  solve(0);
}