#include <bits/stdc++.h>
using namespace std;

// ITP1_6_A:   Reversing Numbers
int main(){
  int n;
  cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  std::reverse(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i < n - 1) { cout << " "; }
  }
  cout << endl;
  return 0;
}
