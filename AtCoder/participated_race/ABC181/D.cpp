
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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
  string s;
  cin >> s; // 1 <= len <= 200000 , '1'~'9'

  unordered_map<int, int> digits;
  rep(i,s.length()) {
      digits[int(s[i] - '1' + 1)]++;
  }
  bool ans = 0;
  if (s.length() == 1) {
      if (std::stoi(s) % 8 == 0) {
          ans = true;
      }
  } else if (s.length() == 2) {
      const int num = std::stoi(s);
      if (num % 8 == 0) {
          ans = true;
      } else {
          if ((num / 10 + (num % 10) * 10) % 8 == 0) {
              ans = true;
          }
      }
  } else {
    for(int i = 100; i < 1000; ++i) {
        if ((i % 2 != 0) || ((i / 2) % 100) % 4 != 0) continue;
        const int d100 = i / 100;
        const int d10 = (i % 100) / 10;
        const int d1 = i % 10;
        if (d100 == 0 || d10 == 0 || d1 == 0) continue;
        unordered_map<int, int> req;
        req[d100]++;
        req[d10]++;
        req[d1]++;
        int counter = 0;
        for (const auto& p : req) {
            if (digits[p.first] >= p.second) ++counter;
        }
        if (int(req.size()) == counter) {
            //cout << "found i:" << i << endl;
            ans = true;
            break;
        }
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
