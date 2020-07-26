
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

/**
 * @brief 文字列を分割する
 * @param target 分割対象の文字列。 ex: "a, b, c"
 * @param separator 区切り文字列。 ex: ", "
 * @return 分割された文字列の一覧
 */
std::vector<string> strsplit(const std::string& target, const std::string& separator) {
  auto separator_length = separator.length(); // 区切り文字の長さ

  auto list = std::vector<std::string>();

  if (separator_length == 0) {
    list.push_back(target);
  } else {
    auto offset = std::string::size_type(0);
    while (1) {
      auto pos = target.find(separator, offset);
      if (pos == std::string::npos) {
        list.push_back(target.substr(offset));
        break;
      }
      list.push_back(target.substr(offset, pos - offset));
      offset = pos + separator_length;
    }
  }
  return list; // ex: list == {"a", "b", "c"}
}

// 指定の文字列を繰り返す
std::string strrepeat(const std::string fill, const std::size_t repeat_num) {
  std::string result;
  result.reserve(fill.length() * repeat_num);
  for(int i = 0; i < static_cast<int>(repeat_num); ++i) {
    result += fill;
  }
  return result;
}

// DigitalArts プログラミングコンテスト2012
// A - C-Filter
int main(){
  string sfull;
  //cin >> sfull;
  getline(cin, sfull); // スペースを含む、改行まで
  vector<string> ss = strsplit(sfull, " ");
  int n;
  cin >> n;
  vector<string> t(n, "");
  rep(i,n) {
    cin >> t[i];
  }

  for (auto& s : ss) {
    bool bFilterable = false;
    for (const auto& tf : t) {
      if (s.length() != tf.length()) {
        continue; // 単語長の不一致
      }
      if (tf.find("*") == std::string::npos) {
        if (s == tf) {
          bFilterable = true;
          break;
        }
      } else {
        // アスタリスクを持っている
        string tmps = s; // copy
        rep(i,tf.length()) {
          if (tf[i] == '*') {
            tmps[i] = '*';
          }
        }
        //cout << "check tmps:" << tmps << " <=> tf:" << tf << endl;
        if (tmps == tf) {
          bFilterable = true;
          break;
        }
      }
    }
    if (bFilterable) {
      s = strrepeat("*", s.length());
    }
  }

  bool first = true;
  for(const auto& s: ss) {
    if (first) {
      cout << s;
      first = false;
    } else {
      cout << " " << s;
    }
  }
  cout << endl;
  return 0;
}
