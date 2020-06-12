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


// AGC013A - Sorted Arrays
int main(){
  int n; // 1 <= N <= 1e5
  cin >> n;
  vector<int64_t> A(n+10, 0); // 1 <= Ai <= 1e9
  rep(i, n) {
    cin >> A[i];
  }

  // 単調非減少または単調非増加な列
  int splitCount = 0;
  int64_t elemFirstA = 0;
  int64_t elemSecondA = 0;
  int64_t elemLatestA = 0;
  bool elemNonDec = true; // 単調非減少:true, 単調非増加:false
  rep(i, n) {
    const int64_t ai = A[i];
    if (elemFirstA == 0) { // 1個目を確定
      elemFirstA = ai;
      elemLatestA = ai;
      //cout << "1個目確定 i:" << i << ",elemFirstA:" << elemFirstA << endl;
    } else if (elemSecondA == 0) { // まだ方向性が決まっていない
      if (elemFirstA != ai) { // 方向性確定
        elemSecondA = ai;
        elemLatestA = ai;
        if (elemFirstA < elemSecondA) {
          elemNonDec = true;
        } else {
          elemNonDec = false;
        }
      //cout << "方向性確定 i:" << i << ",elemSecondA:" << elemSecondA << ",elemNonDec:" << elemNonDec << endl;
      }
    } else { // すでに方向性が決まっている
      //cout << "check i:" << i << ",elemLatestA:" << elemLatestA << ",ai:" << ai << endl;
      if (elemNonDec) {
        // 単調非減少
        if (elemLatestA > ai) {
          // 数列を分ける必要がある
          //cout << "split NonDec i:" << i << ",ai:" << ai << endl;
          ++splitCount;
          elemFirstA = ai;
          elemSecondA = 0;
        }
        elemLatestA = ai;
      } else {
        // 単調非増加
        if (elemLatestA < ai) {
          //cout << "split NonInc i:" << i << ",ai:" << ai << endl;
          // 数列を分ける必要がある
          ++splitCount;
          elemFirstA = ai;
          elemSecondA = 0;
        }
        elemLatestA = ai;
      }
    }
  }

  cout << splitCount + 1 << endl;
  return 0;
}

