#include <bits/stdc++.h>
using namespace std;

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

// 指定の文字列を繰り返す
std::string strrepeat(const std::string fill, const std::size_t repeat_num) {
  std::string result;
  result.reserve(fill.length() * repeat_num);
  for(int i = 0; i < static_cast<int>(repeat_num); ++i) {
    result += fill;
  }
  return result;
}


int main(){
  {
    // tolower すべて小文字にする
    cout << "===== tolower" << endl;
    string s = "AbcDeFgHIJklmnOpQ";
    std::transform(s.begin(), s.end(), s.begin(), [](char c) -> char{ if ('A' <= c && c <= 'Z') { return c - 'A' + 'a'; } else { return c; } });
    cout << s << endl;
  }

  {
  // 文字列検索ですべて見つける
    cout << "===== find str" << endl;
    string s = "aaa a aaaa aba a aaa";
    int count = 0;
    string word = "aa";
    std::string::size_type pos = s.find(word);
    while (pos != std::string::npos) {
      cout << pos << endl;
      pos = s.find(word, pos + word.length());
    }
  }

  {
    // 文字列の分割
    cout << "===== strsplit" << endl;
    const auto strs = strsplit("aaa bbbb ccc ddd e ffff", " ");
    cout << "strs length:" << strs.size() << endl;
    for (const auto& str : strs) {
      cout << str << endl;
    }
  }

  {
    // 文字列を繰り返す
    cout << "===== strrepeat: " << strrepeat("*.", 5) << endl;
  }
  return 0;
}
