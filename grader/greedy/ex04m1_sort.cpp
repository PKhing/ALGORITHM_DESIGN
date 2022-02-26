#include <bits/stdc++.h>
using namespace std;

int tab[100005];
int cnt[4];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tab[i]);
    cnt[tab[i]]++;
  }
  int cnt12 = 0, cnt13 = 0, cnt31 = 0, cnt32 = 0;
  for (int i = 0; i < cnt[1]; i++) {
    if (tab[i] == 2) cnt12++;
    if (tab[i] == 3) cnt13++;
  }
  for (int i = n - 1; i >= n - cnt[3]; i--) {
    if (tab[i] == 1) cnt31++;
    if (tab[i] == 2) cnt32++;
  }
  cout << cnt12 + cnt13 + cnt31 + cnt32 - min(cnt13, cnt31);
}