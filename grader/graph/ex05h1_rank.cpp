#include <bits/stdc++.h>
using namespace std;

vector<int> edge[5005];
vector<int> redge[5005];

bool visited[5005];
bool rvisited[5005];

int component[5005];
int component_cnt = 0;

stack<int> s;
vector<int> component_size;
int n, m;
int sz = 0;

void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto v : edge[u]) {
    dfs(v);
  }
  s.push(u);
}

void rdfs(int u, int component_idx) {
  if (rvisited[u]) return;
  rvisited[u] = 1;
  component[u] = component_idx;
  sz++;
  for (auto v : redge[u]) {
    rdfs(v, component_idx);
  }
}

void find_component() {
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  while (!s.empty()) {
    int i = s.top();
    s.pop();
    if (!rvisited[i]) {
      sz = 0;
      rdfs(i, component_cnt++);
      component_size.push_back(sz);
    }
  }
}

set<int> cedge[5005];
int deg[5005];

int create_new_graph() {
  for (int u = 0; u < n; u++) {
    for (auto v : edge[u]) {
      if (component[u] != component[v])
        cedge[component[u]].insert(component[v]);
    }
  }
}

int rnk[5005];
int ans[5005];

int topo() {
  for (int u = 0; u < component_cnt; u++) {
    for (auto v : cedge[u]) {
      deg[v]++;
    }
  }

  queue<int> q;

  for (int u = 0; u < component_cnt; u++) {
    if (deg[u] == 0) q.push(u);
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : cedge[u]) {
      rnk[v] = max(rnk[v], rnk[u] + 1);
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }

  for (int u = 0; u < component_cnt; u++) {
    ans[rnk[u]] += component_size[u];
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    redge[v].push_back(u);
  }

  find_component();
  create_new_graph();
  topo();

  for (int i = 0; i < component_cnt; i++) {
    if (ans[i] == 0) break;
    printf("%d ", ans[i]);
  }
}