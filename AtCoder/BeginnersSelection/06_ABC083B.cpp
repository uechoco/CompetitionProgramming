#include <bits/stdc++.h>
using namespace std;

// ABC083B - Some Sums
int main(){
  int n, a, b;
  cin >> n >> a >> b;

  int total = 0;
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    int tmp = i;
    // 桁の和を求める
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (a <= sum && sum <= b) {
      total += i;
    }
  }

  cout << total << endl;
  return 0;
}
