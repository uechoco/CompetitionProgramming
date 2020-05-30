#include <bits/stdc++.h>
using namespace std;

// ABC081A - Placing Marbles
int main(){
  string s;
  cin >> s;
  int n = s.length();
  int total = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ++total;
    }
  }
  cout << total << endl;
  return 0;
}
