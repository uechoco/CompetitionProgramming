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


// AGC011A - Airport Bus
int main(){
  int N, C, K; // 1 <= N <= 1e5, 1 <= C,K <= 1e9
  // 飛行機でくる乗客数N人
  // バスの定員C人
  // Ti + K = 許容時間
  cin >> N >> C >> K;
  map<int64_t, int> T;// 1 <= Ti <= 1e9
  {
    int64_t ti;
    for (int i = 1; i <= N; ++i) {
      cin >> ti;
      T[ti]++;
    }
  }
  int num = 0;

  int baset = 0; // base time
  int wp = 0; // wait person num
  for (const auto& p: T) {
    if (baset == 0) {
      baset = p.first;
    }
    if (wp > 0 && baset + K < p.first) {
      // 時間切れなので、待機している人を全員バスに乗せたことにする
      num += (wp % C == 0) ? (wp / C) : (wp / C + 1);
      wp = 0;
      baset = p.first;
    }
    wp += p.second;
    if (wp >= C || ((wp > 0) && baset + K == p.first)) {
      num += wp / C;
      wp = wp % C;
      if (wp == 0) {
        baset = 0;
      }
    }
    //cout << "N:" << N << ",C:" << C << ",K:" << K << ",num:" << num << ",wp:" << wp << ",baset:" << baset << endl;
  }
  if (wp > 0) {
    num += (wp % C == 0) ? (wp / C) : (wp / C + 1);
    //cout << "extra N:" << N << ",C:" << C << ",K:" << K << ",num:" << num << ",wp:" << wp << ",baset:" << baset << endl;
  }

  cout << num << endl;
  return 0;
}

