#include <bits/stdc++.h>
using namespace std;

// ABC086A - Product
int main(){
  int a, b;
  cin >> a >> b;
  cout << (((a * b) % 2 == 0) ? "Even" : "Odd") << endl;
  return 0;
}
