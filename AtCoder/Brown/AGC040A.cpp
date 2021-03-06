
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

// AGC040 A - ><
int main(){
  string s;
  cin >> s; // length: N-1
  // 2 <= N <= 5e5

  const int n = (int)s.length()+1;
  vector<int> nums(n+1, 0);

  char basech = '\0';
  int basei = 0;
  int renzoku = 0;
  rep(i,n) {
    if (renzoku == 0) {
      basech = s[i];
      basei = i;
      renzoku = 1;
    } else if (basech == s[i]) {
      ++renzoku;
    } else {
      if (basech == '<') {
        // 上昇列
        nums[basei] = max(nums[basei], 0); // 境界
        for(int j=1;j<=renzoku;++j) {
          nums[basei+j] = j;
        }
      } else {
        // 下降列
        nums[basei] = max(nums[basei], renzoku); // 境界
        for(int j=1;j<=renzoku;++j) {
          nums[basei+j] = renzoku-j;
        }
      }
      // 次の列
      basech = s[i];
      renzoku = 1;
      basei = i;
    }
  }
  /*rep(i,nums.size()) {
    cout << nums[i] << ",";
  }
  cout << endl;*/
  ll sum = accumulate(nums.begin(), nums.end(), 0L);
  cout << sum << endl;

  return 0;
}
