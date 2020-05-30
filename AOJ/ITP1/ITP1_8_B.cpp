
#include <bits/stdc++.h>
using namespace std;

// ITP1_8_B:   Sum of Numbers
int main(){
  char str[1001];
  while (true) {
    cin >> str;
    if (str[0] == '0') {
      break; // 終わり
    }
    const int len = strlen(str);
    int total = 0;
    for (int i = 0; i < len; ++i) {
      total += int(str[i] - '0');
    }
    cout << total << endl;
  }

  return 0;
}
