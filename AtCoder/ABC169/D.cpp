#include <bits/stdc++.h>
using namespace std;

bool is_prime(int64_t n) {
    if (n == 1) return false;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
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

// 素因数分解(素因数の数値の一覧)
template <typename T>
std::vector<T> prime_factorize_list(T N) {
  std::vector<T> res;
  const auto factors = prime_factorize_pair<T>(N);
  for (const auto& p: factors){
    for (int i = 0; i < p.second; ++i) {
      res.emplace_back(p.first);
    }
  }
  return res;
}

int main(){
  int64_t N;
  cin >> N;

  // 素因数分解 (24 = (2^3) * (3^1))
  auto factors = prime_factorize_pair(N);
  if (factors.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  // 一番大きな素因数の個数を求めておく
  int maxCoef = 0;
  for (const auto& f: factors) {
    if (maxCoef < f.second) {
      maxCoef = f.second;
    }
  }

  // 素因数分解した中から、最大の回数の条件に合う掛け算を求める
  // 未使用の最小約数で割り続ける
  int count = 0;
  for (int i = 1; i <= maxCoef; ++i) {
    for (auto& f: factors) {
      if (f.second >= i) {
        f.second-=i;
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
