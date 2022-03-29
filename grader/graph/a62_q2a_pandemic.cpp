#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;

int tab[505][505];
vector<ii> walk = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int cnt = 0;

  queue<iii> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &tab[i][j]);
      if (tab[i][j] == 1) {
        tab[i][j] = 0;
        q.emplace(0, make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    int t = q.front().first;
    int i = q.front().second.first;
    int j = q.front().second.second;
    q.pop();

    if (i < 0 || j < 0 || i >= n || j >= m) continue;
    if (tab[i][j] != 0) continue;
    tab[i][j] = 1;
    cnt++;

    if (t == k) continue;
    for (auto w : walk) {
      q.emplace(t + 1, make_pair(i + w.first, j + w.second));
    }
  }
  printf("%d", cnt);
}