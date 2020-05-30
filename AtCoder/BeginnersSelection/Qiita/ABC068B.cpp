#include <bits/stdc++.h>
using namespace std;

// ABC068B - Break Number
int main(){
  int n;
  cin >> n;

  int r = 1;
  for (int i = 0; i < 7; ++i) {
    if ((1 << i) <= n) {
      r = (1 << i);
    }
  }

  cout << r << endl;
  return 0;
}
