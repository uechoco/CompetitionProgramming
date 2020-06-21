
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

const ll NMAX = 1000000000000001;

int main(){
  int64_t n;
  cin >> n;

  vector<ll> dm(14,0);

  int nd = 0;
  ll mul = 26;
  for (int i = 1; i <= 13; ++i){
    if (i == 1) {
      dm[i] = mul;
    } else {
      dm[i] = mul + dm[i-1];
    }
    if (dm[i-1] < n && n <= dm[i]) {
      nd = i;
    }
    mul*=26;
  }
  n -= dm[nd-1] + 1;
  string s;
  rep(i,nd) {
    s += (char)('a');
  }
  int i = 0;
  while(n > 0) {
    int m = n % 26;
    n /= 26;
    s[i] += m;
    i++;
  }
  std::reverse(s.begin(), s.end());
  cout << s << endl;

  return 0;
}
