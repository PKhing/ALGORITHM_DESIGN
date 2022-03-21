#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1005];
vector<int> redge[1005];
bool visited[1005];
bool rvisited[1005];
stack<int> s;
int cnt = 0;
vector<int> ans;

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto v : edge[u]) {
    dfs(v);
  }
  s.push(u);
}

void rdfs(int u) {
  if (rvisited[u]) return;
  rvisited[u] = 1;
  cnt++;
  for (auto v : redge[u]) {
    rdfs(v);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      edge[i].push_back(x);
      redge[x].push_back(i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) dfs(i);
  }
  while (!s.empty()) {
    if (!rvisited[s.top()]) {
      cnt = 0;
      rdfs(s.top());
      ans.push_back(cnt);
    }
    s.pop();
  }
  sort(ans.begin(), ans.end());
  for (auto i : ans) printf("%d ", i);
}