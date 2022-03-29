#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1005];
int visited[1005];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[v].push_back(u);
  }
  for (int i = 0; i < 5; i++) {
    int pass = true;
    for (int j = 1; j <= n; j++) visited[j] = 0;
    for (int j = 1; j <= n; j++) {
      int u;
      scanf("%d", &u);
      for (auto v : edge[u]) {
        if (!visited[v]) {
          pass = false;
        }
      }
      visited[u] = 1;
    }
    printf("%s\n", pass ? "SUCCESS" : "FAIL");
  }
}