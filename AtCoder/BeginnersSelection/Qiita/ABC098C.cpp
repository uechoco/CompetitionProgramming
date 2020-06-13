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


// ABC098C - Attention
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  unordered_map<int, int> left; // i番目の人がリーダーの時に、東に向いた人数
  unordered_map<int, int> right; // i番目の人がリーダーの時に、西に向いた人数

  rep(i, N) {
    // i がリーダー
    int ln = 0, rn = 0;
    if (i > 0) {
      left[i] = left[i-1] + (S[i-1] == 'E' ? 0 : 1);
    } else {
      left[i] = 0;
    }
    // N-iがリーダー
    if (N-1-i < N-1) {
      right[N-1-i] = right[N-i] + (S[N-i] == 'W' ? 0 : 1);
    } else {
      right[N-1-i] = 0;
    }
    //cout << "i=" << i << ",left[i]=" << left[i] << ",N-i=" << N-i << ",right[N-i-1]=" << right[N-i-1] << endl;
  }
  int minNum = INT_MAX, sum;
  rep(i, N) {
    sum = left[i] + right[i];
    if (minNum > sum) {
      minNum = sum;
    }
  }

  cout << minNum << endl;
  return 0;
}

