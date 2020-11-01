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
#define ll long long
#define ld long double
#define DUMP(v) "," #v ":" << v

int main(){
  int h, w;
  cin >> h >> w;

  VECTOR_DIM2(int, M, h, w, 0);
  VECTOR_DIM2(int, T, h, w + 1, 0);
  rep(i,h) {
    rep(j,w) {
      cin >> M[i][j];
    }
  }

  // 連続する列マスの個数をT[i][j]に記録
  // T[i][w] は 0 で初期化されている(最後に行の面積をスタックから取り除いていくための高さ0)
  rep(i,h) {
    rep(j,w) {
      if (M[i][j]) {
        T[i][j] = 0;
      } else {
        T[i][j] = (i > 0) ? (T[i-1][j] + 1) : 1;
      }
    }
  }

  struct Rect {
    int height;
    int leftPos;
  };

  int maxarea = 0;
  rep(i,h) {
    stack<Rect> s;
    rep(j,w+1) {
      Rect r;
      r.height = T[i][j];
      r.leftPos = j;
      //cout << "T[" << i << "][" << j << "]: " << T[i][j] << endl;
      if (s.empty()) {
        s.push(r);
      } else {
        if (s.top().height < r.height) {
          s.push(r);
        } else if (s.top().height > r.height) {
          int lastPopLeftPos = j;
          while (!s.empty() && s.top().height >= r.height) {
            const int area = s.top().height * (j - s.top().leftPos);
            maxarea = max(maxarea, area);
            lastPopLeftPos = s.top().leftPos;
            s.pop();
          }
          r.leftPos = lastPopLeftPos;
          s.push(r);
        }
      }
    }
  }

  cout << maxarea << endl;

  return 0;
}
