#include <bits/stdc++.h>
using namespace std;

// ITP1_9_A:   Finding a Word
int main(){
  string word;
  cin >> word;
  int wordLen = word.length();

  int num = 0;
  while (true) {
    string s;
    cin >> s;

    if (s == "END_OF_TEXT") {
      break;
    }

    std::transform(s.begin(), s.end(), s.begin(), [](char c) -> char{ if ('A' <= c && c <= 'Z') { return c - 'A' + 'a'; } else { return c; } });

    int len = s.length();
    std::string::size_type pos = s.find(word);
    while (pos != std::string::npos) {
      // 単語が、wordを内包する別の単語の場合がありえるので、前後の1文字がa-zじゃないかを確認する
      if (pos > 0) {
        char check = s[pos - 1];
        if ('a' <= check && check <= 'z') {
          pos = s.find(word, pos + wordLen);
          continue;
        }
      }
      if (pos + wordLen < len) {
        char check = s[pos + wordLen];
        if ('a' <= check && check <= 'z') {
          pos = s.find(word, pos + wordLen);
          continue;
        }
      }
      ++num;
      pos = s.find(word, pos + wordLen);
    }
  }
  cout << num << endl;

  return 0;
}
