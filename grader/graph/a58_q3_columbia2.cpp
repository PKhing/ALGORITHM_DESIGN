#include <bits/stdc++.h>
using namespace std;

struct state {
  int i, j, t, l;
  state(int t, int i, int j, int l) : t(t), i(i), j(j), l(l) {}
  bool operator<(const state &ot) const { return l > ot.l; }
};

vector<pair<int, int>> walk = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> walk2;
priority_queue<state> q;

int n, m;
int main() {
  // generate tare walk
  for (auto w1 : walk) {
    for (auto w2 : walk) {
      walk2.emplace_back(w1);
      walk2.emplace_back(w1.first + w2.first, w1.second + w2.second);
    }
  }

  cin >> n >> m;
  vector<vector<int>> val(n, vector<int>(m));
  vector<vector<vector<int>>> dist(3,
                                   vector<vector<int>>(n, vector<int>(m, 1e9)));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &val[i][j]);
    }
  }
  dist[0][0][0] = 0;
  q.emplace(0, 0, 0, 0);

  while (!q.empty()) {
    state s = q.top();
    q.pop();
    if (s.l != dist[s.t][s.i][s.j]) continue;

    // normal walk
    for (auto w : walk) {
      int i = s.i + w.first, j = s.j + w.second;
      if (i < 0 || j < 0 || i >= n || j >= m) continue;
      if (dist[s.t][i][j] > dist[s.t][s.i][s.j] + val[i][j]) {
        dist[s.t][i][j] = dist[s.t][s.i][s.j] + val[i][j];
        q.emplace(s.t, i, j, dist[s.t][i][j]);
      }
    }

    // tare walk
    if (s.t < 2) {
      for (auto w : walk2) {
        int i = s.i + w.first, j = s.j + w.second;
        if (i < 0 || j < 0 || i >= n || j >= m) continue;
        if (dist[s.t + 1][i][j] > dist[s.t][s.i][s.j]) {
          dist[s.t + 1][i][j] = dist[s.t][s.i][s.j];
          q.emplace(s.t + 1, i, j, dist[s.t + 1][i][j]);
        }
      }
    }
  }
  // print answer
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", dist[2][i][j]);
    }
    printf("\n");
  }
}