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


// ABC072C - Together
int main(){
  int n; // 1 <= n <= 1e5
  cin >> n;
  vector<int> a(n, 0);
  vector<int> nums(1e5+10, 0);
  rep(i, n) {
    cin >> a[i];
    nums[a[i]]++;
  }

  int maxNum = 0;
  for (int i = 0; i < 1e5; ++i) {
    int tmp = nums[i];
    if (i >= 1) {
      tmp += nums[i-1];
    }
    tmp += nums[i+1];
    if (maxNum < tmp) {
      maxNum = tmp;
    }
  }

  cout << maxNum << endl;
  return 0;
}

