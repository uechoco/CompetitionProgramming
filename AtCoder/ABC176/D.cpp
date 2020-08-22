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

int h, w; // <= 1000
int ch, cw, dh, dw;

int key = 0;
unordered_map<int, vector<pair<int,int>>> marked_map; // key => marked

struct phash{
    inline size_t operator()(const pair<int,int> & p) const{
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

void marking(vector<vector<int>>& s, vector<pair<int,int>>& marked, int cost, int posh, int posw) {
  if (s[posh][posw] != -1 && s[posh][posw] <= cost) {
    return;
  }
  //cout << ">> marking:" << DUMP(cost) << DUMP(posh) << DUMP(posw) << endl;
  s[posh][posw] = cost;
  marked.emplace_back(posh,posw);
  if (posh-1 >= 0) {
    marking(s, marked, cost, posh-1, posw);
  }
  if (posh+1 <= h-1) {
    marking(s, marked, cost, posh+1, posw);
  }
  if (posw -1 >= 0) {
    marking(s, marked, cost, posh, posw-1);
  }
  if (posw +1 <= w-1) {
    marking(s, marked, cost, posh, posw+1);
  }
}

void dump_map(vector<vector<int>>& s) {
  cout << "dump_map:" << endl;
  rep(i,h) {
    rep(j,w) {
      cout << s[i][j] << ",";
    }
    cout << endl;
  }
}

void walking(vector<vector<int>>& s, vector<vector<int>>& cellKeys, int cost, int posh, int posw) {
  //cout << "> walking:" << DUMP(cost) << DUMP(posh) << DUMP(posw) << endl;
  // 徒歩圏内をマークする
  vector<pair<int,int>> marked;
  if (cellKeys[posh][posw] >= 0) {
    marked = marked_map[cellKeys[posh][posw]];
    if (s[posh][posw] > cost) {
      for(const auto&p : marked) {
        s[p.first][p.second] = cost;
      }
    }
    // cost塗りつぶし
  } else {
    marking(s, marked, cost, posh, posw);
    int curKey = ++key;
    marked_map.emplace(curKey, marked);
    for(const auto&p : marked) {
      cellKeys[p.first][p.second] = curKey;
    }
  }
  //dump_map(s);
  // マークしたマスからワープ可能でコスト更新可能なマスをリストアップ
  unordered_set<pair<int,int>,phash> candidates;
  for(const auto&p : marked) {
    const int ph = p.first;
    const int pw = p.second;
    for(int i = -2; i<=2; ++i) {
      if (ph+i < 0 || ph+i > h-1) continue;
      for(int j = -2; j<=2; ++j) {
        if (pw+j < 0 || pw+j > w-1) continue;
        if (s[ph+i][pw+j] == -1 || s[ph+i][pw+j] > cost+1) {
          candidates.emplace(ph+i,pw+j);
        }
      }
    }
  }
  if (candidates.size() == 0) {
    return;
  }
  for(const auto& p:candidates) {
    //cout << ">> candidate:(" << p.first << "," << p.second << ")" << endl;
    if (s[p.first][p.second] == -1 || s[p.first][p.second] > cost+1) {
      walking(s, cellKeys, cost+1, p.first, p.second);
    }
  }
}

int main(){
  cin >> h >> w;
  cin >> ch >> cw >> dh >> dw;
  ch--;cw--;dh--;dw--;
  VECTOR_DIM2(int, s, h, w, -1); // -2 が壁、-1が未踏破領域
  VECTOR_DIM2(int, cellKeys, h, w, -1);
  {
    char c;
    rep(i,h) {
      rep(j,w) {
        cin >> c;
        if (c == '#') {
          s[i][j] = -2;
        } else {
          s[i][j] = -1;
        }
      }
    }
  }

  int cost = 0;
  walking(s, cellKeys, cost, ch, cw);

  cout << s[dh][dw] << endl;
  return 0;
}
