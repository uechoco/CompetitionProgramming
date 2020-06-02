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


// ABC047B - すぬけ君の塗り絵 2 イージー
int main(){
  int W, H, N;
  cin >> W >> H >> N;

  VECTOR_DIM2(bool, data, H, W, true);
  rep(i, N) {
    int xi, yi, ai;
    cin >> xi >> yi >> ai;
    switch (ai) {
      case 1:
        // black < xi
        rep(y,H){
          rep(x,W){
            if (x < xi) {
              data[y][x]=false;
            }
          }
        }
        break;
      case 2:
        // black > xi
        rep(y,H){
          rep(x,W){
            if (x >= xi) {
              data[y][x]=false;
            }
          }
        }
        break;
      case 3:
        // black < yi
        rep(y,H) {
          if (y < yi) {
            rep(x,W){
              data[y][x]=false;
            }
          }
        }
        break;
      case 4:
        // black > yi
        rep(y,H) {
          if (y >= yi) {
            rep(x,W){
              data[y][x]=false;
            }
          }
        }
        break;
    }
  }
  int count=0;
  rep(i,H){
    rep(j,W){
      if (data[i][j]) {
        ++count;
      }
    }
  }
  cout << count << endl;


  return 0;
}
