#include <bits/stdc++.h>
using namespace std;

// ABC088B - Card Game for Two
int main(){
  int n;
  cin >> n;

  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int total = 0;
  std::sort(a.begin(), a.end(), std::greater<int>());
  int alice = 0, bob = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      alice += a[i];
    } else {
      bob += a[i];
    }
  }

  cout << alice - bob << endl;
  return 0;
}
