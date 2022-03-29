#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;

int tab[1005][1005], dist[1005][1005];
vector<ii> walk = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
priority_queue<iii, vector<iii>, greater<iii>> q;
int mx = 1000;
int mn = 0;

int main() {
  int n, si, sj;
  cin >> n >> si >> sj;
  while (n--) {
    int i, j;
    scanf("%d %d", &i, &j);
    tab[i][j] = 1;
  }

  for (int i = mn; i <= mx; i++) {
    for (int j = mn; j <= mx; j++) {
      dist[i][j] = 1e9;
    }
  }
  dist[si][sj] = 0;

  q.emplace(0, make_pair(si, sj));

  while (!q.empty()) {
    int l = q.top().first;
    int i = q.top().second.first;
    int j = q.top().second.second;
    q.pop();

    if (i < mn || j < mn || i > mx || j > mx) continue;
    if (l != dist[i][j]) continue;

    int newdist = dist[i][j] + tab[i][j];

    for (auto w : walk) {
      if (newdist < dist[i + w.first][j + w.second]) {
        dist[i + w.first][j + w.second] = newdist;
        q.emplace(newdist, make_pair(i + w.first, j + w.second));
      }
    }
  }

  int ans = 1e9;
  for (int i = mn; i <= mx; i++) {
    ans = min({ans, dist[mn][i], dist[mx][i], dist[i][mn], dist[i][mx]});
  }
  printf("%d", ans);
}
