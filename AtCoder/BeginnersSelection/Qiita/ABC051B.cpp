#include <bits/stdc++.h>
using namespace std;

// ABC051B - Sum of Three Integers
int main(){
  int k, s;
  cin >> k >> s;

  int num = 0;

  for (int x = 0; x <= k; ++x) {
    for (int y = 0; y <= k; ++y) {
      int z = s - x - y;
      if (0 <= z && z <= k) {
        ++num;
      }
    }
  }

  cout << num << endl;
  return 0;
}
