#include <bits/stdc++.h>
using namespace std;

struct Item {
  double v, w;
  bool operator<(const Item &ot) const { return v / w > ot.v / ot.w; }
};

int n;
double maxW;
Item item[105];
double maxV = 0;

double heuristic(int i, double wLeft) {
  double v = 0;
  for (i; i < n; i++) {
    if (wLeft <= 0) break;
    v += (item[i].v / item[i].w) * min(item[i].w, wLeft);
    wLeft -= item[i].w;
  }
  return v;
}

void solve(int i, double wLeft, double currentVal) {
  maxV = max(maxV, currentVal);
  if (i == n) return;
  double maxValue = currentVal + heuristic(i, wLeft);
  if (maxValue < maxV) return;
  if (wLeft >= item[i].w)
    solve(i + 1, wLeft - item[i].w, currentVal + item[i].v);
  solve(i + 1, wLeft, currentVal);
}

int main() {
  cin >> maxW >> n;
  for (int i = 0; i < n; i++) {
    scanf("%lf", &item[i].v);
  }
  for (int i = 0; i < n; i++) {
    scanf("%lf", &item[i].w);
  }
  sort(item, item + n);
  solve(0, maxW, 0);
  printf("%lf", maxV);
}