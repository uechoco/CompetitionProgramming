
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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
#define DUMP(v) "," #v ":" << v

// 指定の文字列を繰り返す
std::string strrepeat(const std::string fill, const std::size_t repeat_num) {
  std::string result;
  result.reserve(fill.length() * repeat_num);
  for(int i = 0; i < static_cast<int>(repeat_num); ++i) {
    result += fill;
  }
  return result;
}


// ABC029 C - Brute-force Attack
int main(){
  int n;
  cin >> n;
  const int num = pow(3,n);
  string s = strrepeat("a", n);
  for (int i = 0; i < num; ++i) {
    if (i != 0) {
      for(int j=n-1;j>=0;--j) {
        if (s[j] != 'c') {
          s[j]++;
          for(int k=j+1;k<n;++k) {
            s[k] = 'a';
          }
          break;
        }
      }
    }
    cout << s << endl;
  }

  return 0;
}
