#include <bits/stdc++.h>
using namespace std;
int tab[100005];
int main() {
  int n, t;
  cin >> n >> t;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(0);
  }
  for (int i = 0; i < t; i++) {
    scanf("%d", &tab[i]);
  }
  sort(tab, tab + t);
  double ans = 0;
  for (int i = 0; i < t; i++) {
    ans += pq.top() + tab[i];
    pq.push(pq.top() + tab[i]);
    pq.pop();
  }
  printf("%.03f", ans / t);
}