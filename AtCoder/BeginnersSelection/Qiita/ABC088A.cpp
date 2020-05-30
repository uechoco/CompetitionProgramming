#include <bits/stdc++.h>
using namespace std;

// ABC046A - RGB Cards
int main(){
  int n, a;
  cin >> n >> a;

  cout << ((n % 500 <= a) ? "Yes" : "No") << endl;
  return 0;
}
