#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

int edge[25][25];
int dist[25][1 << 21];

int n;

int dfs(int current, int state) {
  if (dist[current][state] != -1e9) return dist[current][state];
  if (current == 0 && state != 1) return -1e9;

  for (int i = 0; i < n; i++) {
    if ((state & (1 << i)) != 0 && i != current) {
      dist[current][state] =
          max(dist[current][state],
              dfs(i, state ^ (1 << current)) + edge[i][current]);
    }
  }
  return dist[current][state];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &edge[i][j]);
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 1 << n; j++) dist[i][j] = -1e9;
  dist[0][1] = 0;
  printf("%d", dfs(n - 1, (1 << n) - 1));
}