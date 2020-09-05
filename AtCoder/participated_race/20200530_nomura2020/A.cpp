#include <bits/stdc++.h>
using namespace std;

// A
int main(){
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int range = (h2 * 60 + m2) - (h1 * 60 + m1);

  cout << (range - k > 0 ? (range - k) : 0) << endl;
  return 0;
}
