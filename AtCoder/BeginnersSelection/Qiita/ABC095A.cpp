#include <bits/stdc++.h>
using namespace std;

// ABC095A - Something on It
int main(){
  string s;
  cin >> s;
  int top = 0;
  if (s[0] == 'o') { top++; }
  if (s[1] == 'o') { top++; }
  if (s[2] == 'o') { top++; }

  cout << (700 + top * 100) << endl;
  return 0;
}
