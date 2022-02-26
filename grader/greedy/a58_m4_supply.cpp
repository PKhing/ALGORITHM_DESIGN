#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

ii req[200005];

queue<int> store;
queue<int> wait;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int d, e, l;
    scanf("%d %d %d", &d, &e, &l);
    req[d] = {e, l};
  }
  for (int i = 1; i <= k; i++) {
    if (req[i].first == 0) {
      if (wait.size() > 0) {
        printf("%d\n", wait.front());
        wait.pop();
      } else {
        printf("0\n");
        store.push(req[i].second);
      }
    } else {
      if (store.size() > 0) {
        printf("%d\n", store.front());
        store.pop();
      } else {
        printf("0\n");
        wait.push(req[i].second);
      }
    }
  }
}