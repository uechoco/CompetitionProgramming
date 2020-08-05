
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

/**
 * @brief 文字列を分割する
 * @param target 分割対象の文字列。 ex: "a, b, c"
 * @param separator 区切り文字列。 ex: ", "
 * @return 分割された文字列の一覧
 */
std::vector<string> strsplit(const std::string& target, const std::string& separator) {
  const auto separator_length = separator.length(); // 区切り文字の長さ
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


int main(){
  string s;
  getline(cin, s);

  vector<ll> stack;
  const vector<string> ss = strsplit(s, " ");
  rep(i, ss.size()) {
    const auto& cur = ss[i];
    if (cur == "+") {
      const ll v1 = stack.back();
      stack.pop_back();
      const ll v2 = stack.back();
      stack.pop_back();
      stack.push_back(v2 + v1);

    } else if (cur == "-") {
      const ll v1 = stack.back();
      stack.pop_back();
      const ll v2 = stack.back();
      stack.pop_back();
      stack.push_back(v2 - v1);
    } else if (cur == "*") {
      const ll v1 = stack.back();
      stack.pop_back();
      const ll v2 = stack.back();
      stack.pop_back();
      stack.push_back(v2 * v1);
    } else {
      ll v = stoll(cur);
      stack.push_back(v);
    }
  }

  cout << stack.back() << endl;

  return 0;
}
