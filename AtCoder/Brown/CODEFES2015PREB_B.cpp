
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


// CODE FESTIVAL 2015 予選B
// B - 採点
int main(){
  ll n, m;
  cin >> n >> m;
  unordered_map<ll, ll> nums;

  ll a;
  rep(i,n) {
    cin >> a;
    nums[a]++;
  }
  ll border = n / 2 + 1;
  for(const auto& p: nums) {
    if (p.second >= border) {
      cout << p.first << endl;
      return 0;
    }
  }
  cout << "?" << endl;
  return 0;
}
