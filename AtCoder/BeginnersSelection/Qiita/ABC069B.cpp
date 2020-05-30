#include <bits/stdc++.h>
using namespace std;

// ABC069B - i18n
int main(){
  string s;
  cin >> s;
  int len = s.length();

  cout << s[0] << len-2 << s[len-1] << endl;
  return 0;
}
