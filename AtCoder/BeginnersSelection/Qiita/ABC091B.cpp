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


// ABC091B - Two Colors Card Game
int main(){
  int N, M;
  std::unordered_map<string, int> data;
  cin >> N;
  string si;
  rep(i,N) { // 青
    cin >> si;
    data[si]++;
  }
  cin >> M;
  rep(i,M) { // 赤
    cin >> si;
    data[si]--;
  }

  // 最大のものが0以上であればその数を出力
  int ret = INT_MIN;
  for (const auto& pair : data) {
    if (pair.second > ret) {
      ret = pair.second;
    }
  }

  cout << (ret > 0 ? ret : 0) << endl;


  return 0;
}
