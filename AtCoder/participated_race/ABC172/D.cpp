
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

// 約数の列挙
template <typename T>
std::vector<T> enum_divisors(T N) {
    std::vector<T> res;
    for (T i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.emplace_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.emplace_back(N/i);
        }
    }
    return res;
}

// 素因数分解(素因数の数値とその回数のペア)
template <typename T>
std::vector<std::pair<T, T> > prime_factorize_pair(T N) {
    std::vector<std::pair<T, T> > res;
    for (T a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        T ex = 0; // 指数
        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        // その結果を push
        res.emplace_back(a, ex);
    }
    // 最後に残った数について
    if (N != 1) res.emplace_back(N, 1);
    return res;
}
const ll NMAX = 1e7;

int main(){
  ll n;
  cin >> n;

  vector<int> divnum(n+1,0);

  ll total = 1; // n=1のanswer
  for(ll i = 2; i <= n; ++i) {
    if (divnum[i] != 0) {
      total += i * divnum[i];
      //cout << "cachei:" << i << ",num:" <<divnum[i]<< endl;
    } else {
      const auto pairs = prime_factorize_pair(i);
      ll sisu = 1;
      for(const auto& p:pairs) {
        sisu *= (p.second + 1);
      }
      total += i * sisu;
      // cout << "i:" << i << ",sisu=" << sisu << endl;

      // 余分に作る
      for(const auto& p:pairs) {
        ll muler = p.first;
        ll sisu2 = p.second;
        ll sisuother = 1;
        for (const auto& q:pairs) {
          if (q.first != p.first) {
            sisuother *= (q.second + 1);
          }
        }
        ll m = i;
        while (m * muler <= n) {
          m *= muler;
          ++sisu2;
          divnum[m] = (sisu2 + 1) * sisuother;
          //cout << "cache:" << m << "=" << sisu2 << endl;
        }
      }
    }
  }
  cout << total << endl;
  return 0;
}
