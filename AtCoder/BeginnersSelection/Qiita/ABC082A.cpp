#include <bits/stdc++.h>
using namespace std;

// ABC082A - Round Up the Mean
int main(){
  int a, b;
  cin >> a >> b;

  cout << (((a+b)%2==0) ? (a+b)/2 : (a+b+1)/2) << endl;
  return 0;
}
