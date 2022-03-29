#include <bits/stdc++.h>
#define ll long long
#define matrix vector<vector<ll>>
#define newMatrix(x) x(35, vector<ll>(35, 1e18))
using namespace std;

int edge[35][5];
int k, n, e;
matrix newMatrix(dist);

matrix move(matrix dist1, matrix dist2) {
  matrix newMatrix(newDist);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = -1; l <= 1; l++) {
          int p = (k + l + n) % n;
          newDist[i][j] =
              min(newDist[i][j], dist1[i][k] + dist2[p][j] + edge[k][3 + l]);
        }
      }
    }
  }
  return newDist;
}

matrix solve(int x) {
  if (x == 1) return dist;
  matrix disthalf = solve(x >> 1);
  if (x & 1)
    return move(move(disthalf, disthalf), dist);
  else
    return move(disthalf, disthalf);
}

int main() {
  cin >> k >> n >> e;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &edge[i][j]);
    }
    dist[i][i] = 0;
    dist[i][(i - 1 + n) % n] = edge[i][0];
    dist[i][(i + 1) % n] = edge[i][1];
  }

  // apsp
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }

  matrix ans = solve(k);
  printf("%lld", ans[0][e]);
}