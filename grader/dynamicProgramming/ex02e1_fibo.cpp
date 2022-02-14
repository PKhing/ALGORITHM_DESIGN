#include <bits/stdc++.h>
using namespace std;

int fibo[100];
int main() {
  int n;
  cin >> n;

  fibo[1] = 1;
  for (int i = 2; i <= n; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
  printf("%d", fibo[n]);
}