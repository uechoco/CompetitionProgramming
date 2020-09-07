
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
// @brief modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    // コンストラクタ
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
    constexpr int getmod() { return MOD; }
    // 単項演算子マイナス。
    constexpr Fp operator - () const noexcept { return val ? MOD - val : 0;}
    // 足し算 (a + b) mod P を解く。計算途中でもあまりをとって良い。
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    // 引き算 (a - b) mod P を解く。計算途中でもあまりをとって良い。最終結果が負値なら P を足す。
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    // 掛け算 (a * b) mod P を解く。計算途中でもあまりをとって良い。
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    // 割り算 (a / b) mod P を解く。bの逆元をかける。
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept { val += r.val; if (val >= MOD){val -= MOD;} return *this; }
    constexpr Fp& operator -= (const Fp& r) noexcept { val -= r.val; if (val < 0){val += MOD;} return *this; }
    constexpr Fp& operator *= (const Fp& r) noexcept { val = val * r.val % MOD; return *this; }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept { return this->val == r.val; }
    constexpr bool operator != (const Fp& r) const noexcept { return this->val != r.val; }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept { return os << x.val; }
    // 累乗 a^n mod P を二分累乗法で解く O(lon n)
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = 1e9+7; // 1000000007
using mint = Fp<MOD>;

#define ll long long
#define ld long double
#define DUMP(v) "," #v ":" << v

// ABC117 C - Streamline
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> X(m, 0); // 訪れるべき座標一覧(m個)
  rep(i, m) cin >> X[i];
  sort(X.begin(), X.end());

  ll ans = 0;
  if (n >= m) {
    ans = 0; // 最初にコマを置いた時点でクリア
  } else {
    // 数直線上の隣り合う点同士を結ぶ線分を大きい順に並べ、
    // N-1回分断すると、N個の区間ができ、それが答え
    vector<int> diff(m-1,0);
    int base = X[0];
    rep2(i,1,m) {
      diff[i-1] = X[i] - base;
      base = X[i];
    }
    // 大きい順にN-1個の線分をスキップし、残りを合計
    sort(diff.begin(), diff.end(), greater<int>());
    ans = accumulate(diff.begin() + (n-1), diff.end(),0LL);
  }

  cout << ans << endl;
  return 0;
}
