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

vector<int> enum_divisors(int N) {
    vector<int> res;
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    return res;
}

int main(){
  int n; // 1 <= N <= 2 * 1e5
  cin >> n;
  vector<int> a(n, 0); // 1 <= a_i <= 1e6
  unordered_map<int, int> nums; // 数値 -> 個数
  rep(i, n) {
    cin >> a[i];
    nums[a[i]]++;
  }

  int ans = 0;
  rep(i, n) {
    int ai = a[i];
    // a_iと同じ数が jにもあるなら満たせない
    if (nums[ai] > 1) {
      continue;
    }
    bool found = false;
    const auto& divs = enum_divisors(ai);
    for (const auto& div : divs) {
      if (div != ai && nums[div] > 0) {
        found = true;
        break;
      }
    }
    if (!found) {
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}

