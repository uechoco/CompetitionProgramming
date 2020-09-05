
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


int main(){
  int H, W, K;
  cin >> H >> W >> K;
  VECTOR_DIM2(bool, data, H, W, false); // 黒がtrue
  int firstblackcount = 0;
  rep(i,H) {
    string s;
    cin >> s;
    rep(j,W) {
      if (s[j] == '#') {
        data[i][j] = true;
        ++firstblackcount;
      }
    }
  }
  unordered_map<ll, int> ans;

  vector<int> chooseHBase, chooseWBase;
  rep(i,H) {
    chooseHBase.push_back(i);
  }
  rep(i,W) {
    chooseWBase.push_back(i);
  }

  // i: 何行選んだか
  // j: 何列選んだか
  for(int i = 0; i <= H; ++i) {
    vector<int> chooseH = chooseHBase;
    do {
      ll mapkey = 0;
      auto tmp = data; // copy
      auto tmpcount = firstblackcount;
      rep(ii,i) {
        auto iii = chooseH[ii];
        mapkey += 1 << (iii + 1);
        rep(jj,W) {
          if (tmp[iii][jj]) {
            tmp[iii][jj] = false;
            --tmpcount;
            if (tmpcount < K) {
              goto BREAKPOINT_I;
            }
          }
        }
      }
BREAKPOINT_I:
      if (tmpcount < K) {
        continue;
      }
      ans[mapkey]++;
      //cout << "i:" << i << ",chooseH[0]=" << chooseH[0] << ",tmpcount:" << tmpcount << endl;
      for(int j = 0; j <= W; ++j) {
        vector<int> chooseW = chooseWBase;
        do {
          ll mapkey2 = 0;
          auto tmp2 = tmp; // copy
          auto tmp2count = tmpcount;
          rep(jj,j) {
            auto jjj = chooseW[jj];
            mapkey2 += 1 << (jjj+10);
            rep(ii,H) {
              if (tmp2[ii][jjj]) {
                tmp2[ii][jjj] = false;
                --tmp2count;
                if (tmp2count < K) {
                  goto BREAKPOINT_J;
                }
              }
            }
          }
BREAKPOINT_J:
          if (tmp2count == K) {
            //cout << "i:" << i << ",j:" << j << ",chooseH[0]=" << chooseH[0] << ",chooseW[0]=" << chooseW[0] << ",tmp2count:" << tmp2count << endl;
            ans[mapkey+mapkey2]++;
          }
        } while (j != 0 && std::next_permutation(chooseW.begin(), chooseW.end()));
      }
    } while (i != 0 && std::next_permutation(chooseH.begin(), chooseH.end()));
  }

  cout << ans.size() << endl;
  return 0;
}
