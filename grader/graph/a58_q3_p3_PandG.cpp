#include <bits/stdc++.h>
#define ii pair<int, int>
#define state pair<pair<int, char>, ii>
#define f first
#define s second

using namespace std;

char tab[105][105];
vector<ii> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m, g, t, si, sj;
    cin >> n >> m >> g >> t >> si >> sj;

    priority_queue<state, vector<state>, greater<state>> q;

    q.emplace(make_pair(0, 'P'), make_pair(si + 1, sj + 1));

    for (int i = 0; i < g; i++) {
      int t, r, c;
      cin >> t >> r >> c;
      q.emplace(make_pair(t, 'G'), make_pair(r + 1, c + 1));
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf(" %c", &tab[i][j]);
      }
    }

    while (!q.empty()) {
      int time = q.top().f.f;
      int type = q.top().f.s;
      int i = q.top().s.f;
      int j = q.top().s.s;

      q.pop();
      if (i <= 0 || j <= 0 || i > n || j > m) continue;
      if (tab[i][j] == '#' || tab[i][j] == type) continue;
      if (type == 'P' && tab[i][j] == 'G') continue;
      tab[i][j] = type;

      if (time == t) continue;
      for (auto w : walk) {
        q.emplace(make_pair(time + 1, type), make_pair(i + w.f, j + w.s));
      }
    }

    bool found = false;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (tab[i][j] == 'P') found = true;

    printf("%s\n", found ? "YES" : "NO");
  }
}
