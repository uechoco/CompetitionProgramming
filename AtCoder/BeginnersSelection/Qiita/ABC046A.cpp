#include <bits/stdc++.h>
using namespace std;

// ABC046A - RGB Cards
int main(){
  int r, g, b;
  cin >> r >> g >> b;

  cout << ((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
