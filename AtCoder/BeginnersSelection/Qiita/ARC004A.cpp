#include <bits/stdc++.h>
using namespace std;

// ARC004A - 2点間距離の最大値 ( The longest distance )
int main(){
  int n;
  cin >> n;
  vector<int> x(n, 0), y(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  int mi=0, mj=0, dsq = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sq = (x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
      if (dsq < sq) {
        mi = i;
        mj = j;
        dsq = sq;
      }
    }
  }

  cout << std::fixed << std::setprecision(6) << sqrt(double(dsq)) << endl;
  return 0;
}
