#include <bits/stdc++.h>
using namespace std;
// ITP1_3_D:   How Many Divisors?
int main(){
 int a, b, c, d = 0;
  cin >> a >> b >> c;
  for (int i = a; i <= b; ++i) {
    if ((c / i) * i == c) {
      ++d;
    }
  }
  cout << d << endl;
}
