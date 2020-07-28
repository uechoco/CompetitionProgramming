
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)
// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);
#define ll long long
#define ld long double

// ABC030 B - 時計盤
int main(){
  int n, m;
  cin >> n >> m;

  const int nn = n * 60 + m;
  const int mm = m * 12;
  int can1 = nn - mm;
  int can2 = mm - nn;
  //cout << "can1:" << can1 << ",can2:" << can2 << endl;
  can1 = (can1 + 720 * 3) % 720;
  can2 = (can2 + 720 * 3) % 720;
  //cout << "can1:" << can1 << ",can2:" << can2 << endl;
  const int can3 = min(min(min(can1, can2), 60*12-can1), 60*12-can2);
  //cout << "can3:" << can3 << endl;
  const double ans = can3 / 2.0; // can3 * 360 / (60 * 12);

  cout << std::fixed << std::setprecision(4) << ans << endl;
  return 0;
}
