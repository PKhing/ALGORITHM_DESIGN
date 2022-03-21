#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

char tab[105][105];
int dist[105][105];
vector<ii> walk = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &tab[i][j]);
      dist[i][j] = -1;
    }
  }
  queue<ii> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    int u = q.front().first, v = q.front().second;
    q.pop();
    dist[0][0] = 0;
    for (auto w : walk) {
      int i = u + w.first, j = v + w.second;
      if (i < 0 || i >= n || j < 0 || j >= m) continue;
      if (dist[i][j] != -1 || tab[i][j] == '#') continue;
      dist[i][j] = dist[u][v] + 1;
      q.emplace(i, j);
    }
  }
  printf("%d", dist[n - 1][m - 1]);
}