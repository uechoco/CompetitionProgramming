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


// ABC081C - Not so Diverse
int main(){
  int N, K; // N個のボール、K種類以下にしたい
  cin >> N >> K;

  std::unordered_map<int, int> data;
  int ai;
  rep(i,N) {
    cin >> ai;
    data[ai]++;
  }
  if (data.size() <= K) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> elems;
  for (const auto& p: data) {
    elems.push_back(p.second);
  }
  int total = 0;
  std::sort(elems.begin(), elems.end());
  for (int i = 0; i < data.size()-K;++i) {
    total+=elems[i];
  }


  cout << total << endl;


  return 0;
}
