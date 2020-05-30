#include <bits/stdc++.h>
using namespace std;

int main(){

  string s;

  // tolower すべて小文字にする
  std::transform(s.begin(), s.end(), s.begin(), [](char c) -> char{ if ('A' <= c && c <= 'Z') { return c - 'A' + 'a'; } else { return c; } });

  // 文字列検索ですべて見つける
  {
    int count = 0;
    string word;
    std::string::size_type pos = s.find(word);
    while (pos != std::string::npos) {
      cout << pos << endl;
      pos = s.find(word, pos + word.length());
    }
  }

  return 0;
}
