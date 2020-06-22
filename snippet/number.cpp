#include <bits/stdc++.h>
using namespace std;

// 円周率
const double DOUBLE_PI = acos(-1.0);
const long double LONGDOUBLE_PI = acosl(-1.0);

// 各桁の和を計算する関数
template <typename T>
int sum_of_digits(T n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
// 数値の桁数を求める
template <typename T>
int calc_digit(T n) {
  int res = 0;
  while (n) {
      ++res;
      n /= 10;
  }
  return res;
}

// 素数判定
template <typename T>
bool is_prime(T n) {
    if (n == 1) return false;
    for (T i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// 約数の列挙
template <typename T>
std::vector<T> enum_divisors(T N, bool sorted) {
    std::vector<T> res;
    for (T i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.emplace_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.emplace_back(N/i);
        }
    }
    if (sorted) {// 小さい順に並び替える
      std::sort(res.begin(), res.end());
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
  // 浮動小数点型の桁数を指定出来るマニピュレータ
  cout << std::fixed << std::setprecision(8) << (double)(12.9295871325) << endl;

  {// 素数判定
    int n32 = 6700417;
    int64_t n64 = 67280421310721;
    cout << "素数判定[" << n32 << "] -> " << is_prime(n32) << endl;
    cout << "素数判定[" << n64 << "] -> " << is_prime(n64) << endl;
  }

  { // 約数の列挙

    // 約数の列挙(ソートなし)
    int n32 = 1024;
    // 1,1024,2,512,4,256,8,128,16,64,32
    const auto divisors32 = enum_divisors(n32, false);
    cout << "約数の列挙(ソートなし)[" << n32 << "] -> ";
    for (const auto& d: divisors32){
      cout << d << ",";
    }
    cout << endl;

    // 約数の列挙(ソートあり)
    const auto divisors32sorted = enum_divisors(n32, true);
    // 1,2,4,8,16,32,64,128,256,512,1024
    cout << "約数の列挙(ソートあり)[" << n32 << "] -> ";
    for (const auto& d: divisors32sorted){
      cout << d << ",";
    }
    cout << endl;
  }

  { // 素因数分解
    int64_t n64 = 2020;

    const auto factor_pairs = prime_factorize_pair(n64);
    // (2,2),(5,1),(101,1),
    cout << "素因数分解(ペアと個数)[" << n64 << "] -> ";
    for (const auto& p: factor_pairs){
      cout << "(" << p.first << "," << p.second << "),";
    }
    cout << endl;

    const auto factor_list = prime_factorize_list(n64);
    // 2,2,5,101,
    cout << "素因数分解(一覧))[" << n64 << "] -> ";
    for (const auto& p: factor_list){
      cout << p << ",";
    }
    cout << endl;
  }

  { // 桁数
    cout << "数値の桁数を求める[57234698]:" << calc_digit(57234698) << endl;
    cout << "数値の各桁の和を求める[57]:" << sum_of_digits(57) << endl;
  }
  return 0;
}