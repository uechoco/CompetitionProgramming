#include <bits/stdc++.h>
using namespace std;

bool is_prime(int64_t n) {
    if (n == 1) return false;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
  int64_t N;
  cin >> N;

  // 素因数分解 (24 = (2^3) * (3^1))
  const auto &res = prime_factorize(N);
  if (res.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  // 横にばらす (24 = 2 * 2 * 2 * 3)
  vector<int64_t> primefactors;
  for (auto p : res) {
      for (int i = 0; i < p.second; ++i) {
        primefactors.push_back(p.first);
      }
  }

  // 素因数分解した中から、最大の回数の条件に合う掛け算を求める
  // 未使用の最小約数で割り続ける
  vector<bool> used(N+10, false);
  int usedMin = INT_MAX;
  int count = 0;
  while (primefactors.size() > 0) {
    int len = primefactors.size();
    // LEN個の中から1個以上使った掛け算の、未使用の最小のものを求める
    for (int selectNum = 1; selectNum <= len; ++selectNum) {

    }
  }
  cout << count << endl;
  return 0;
}
