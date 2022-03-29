#include <bits/stdc++.h>
using namespace std;

struct state {
  int i, j, l;
  state(int i, int j, int l) : i(i), j(j), l(l) {}
  bool operator<(const state &ot) const { return l > ot.l; }
};

vector<pair<int, int>> walk = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> tab(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m, 1e9));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &tab[i][j]);
    }
  }

  priority_queue<state> q;
  q.emplace(0, 0, 0);
  dist[0][0] = 0;
  while (!q.empty()) {
    state s = q.top();
    q.pop();
    if (dist[s.i][s.j] != s.l) continue;
    for (auto w : walk) {
      int i = s.i + w.first;
      int j = s.j + w.second;
      if (i < 0 || j < 0 || i >= n || j >= m) continue;
      if (dist[i][j] > s.l + tab[i][j]) {
        dist[i][j] = s.l + tab[i][j];
        q.emplace(i, j, dist[i][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
}