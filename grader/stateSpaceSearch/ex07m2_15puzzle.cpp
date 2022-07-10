#include <bits/stdc++.h>
#define table vector<vector<int>>
#define state tuple<int, int, table>
#define ii pair<int, int>
using namespace std;

int n = 4;

table result = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
map<int, ii> resultLocation;
vector<ii> walk = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

priority_queue<state, vector<state>, greater<state>> q;
set<table> visited;

void initHeuristic() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      resultLocation[result[i][j]] = {i, j};
    }
  }
}

int heuristic(table tab) {
  int h = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (tab[i][j] == 0) continue;
      ii loc = resultLocation[tab[i][j]];
      h += abs(loc.first - i) + abs(loc.second - j);
    }
  }
  return h;
}

ii getZeroLocation(table &tab) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (tab[i][j] == 0) return {i, j};
    }
  }
}

void move(table tab, int l, int wi, int wj) {
  ii zero = getZeroLocation(tab);
  int i = wi + zero.first;
  int j = wj + zero.second;
  if (i < 0 || j < 0 || i >= n || j >= n) return;
  swap(tab[zero.first][zero.second], tab[i][j]);
  if (visited.find(tab) != visited.end()) return;
  visited.insert(tab);
  int h = heuristic(tab);
  if (h == 0) {
    printf("%d", l + 1);
    exit(0);
  }
  q.emplace(h + l + 1, l + 1, tab);
}

int main() {
  table initial(4, vector<int>(4));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &initial[i][j]);
    }
  }

  initHeuristic();

  q.emplace(0, 0, initial);
  visited.insert(initial);

  while (!q.empty()) {
    int d, l;
    table tab;
    tie(d, l, tab) = q.top();
    q.pop();
    for (auto w : walk) move(tab, l, w.first, w.second);
  }
}