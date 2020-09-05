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

struct House {
  map<int, int, std::greater<int>> rateNum; // レートの人数
};

int main(){
  int n, q;
  cin >> n >> q;
  unordered_map<int, int> people; // 幼児番号 -> レート
  unordered_map<int, int> belong; // 幼児番号 -> 所属
  unordered_map<int, House> houses; // 幼稚園 => メタ
  unordered_map<int, int> houseRate; // 幼稚園 => 代表レート
  map<int, int> houseRateNum; // レート => 幼稚園数


  int a, b;
  rep(i,n) {
    cin >> a >> b;
    people[i] = a;
    belong[i] = b;
    auto& h = houses[b];
    h.rateNum[a]++;
  }
  vector<int> ci(q, 0), di(q, 0);
  rep(i,q) {
    cin >> ci[i] >> di[i];
  }

  int rate;
  for(const auto& h : houses) {
    rate = (*h.second.rateNum.cbegin()).first;
    houseRate[h.first] = rate;
    houseRateNum[rate]++;
  }
/*
  for(const auto& h : houses) {
    cout << "hno=" << h.first << "[";
    for (const auto& p : h.second.rateNum) {
      cout << "(rate=" << p.first << ",num=" << p.second << "),";

    }
    cout << "]" << endl;
  }
  cout << "============" << endl;
  */

  int c, cRate, afHouse, bfHouse;
  rep(i,q) {
    c = ci[i]-1; // 幼児番号
    afHouse = di[i]; // 転園先
     // 所属更新
    bfHouse = belong[c];
    belong[c] = afHouse;

    cRate = people[c];
    // 旧所属レート更新
    rate = (*houses[bfHouse].rateNum.cbegin()).first; // 旧代表レート
    houses[bfHouse].rateNum[cRate]--;
    if (houses[bfHouse].rateNum[cRate] == 0) {
      houses[bfHouse].rateNum.erase(cRate);
    }
    houseRateNum[rate]--;
    if (houseRateNum[rate] == 0) {
      houseRateNum.erase(rate);
    }
    rate = (*houses[bfHouse].rateNum.cbegin()).first;
    if (rate > 0) {
      houseRate[bfHouse] = rate;
      houseRateNum[rate]++;
    }
/*
    for(const auto& h : houses) {
      cout << "hno=" << h.first << "[";
      for (const auto& p : h.second.rateNum) {
        cout << "(rate=" << p.first << ",num=" << p.second << "),";

      }
      cout << "]" << endl;
    }*/

    // 新所属レート更新
    rate = (*houses[afHouse].rateNum.cbegin()).first;
    houses[afHouse].rateNum[cRate]++;
    houseRateNum[rate]--;
    if (houseRateNum[rate] == 0) {
      houseRateNum.erase(rate);
    }
    rate = (*houses[afHouse].rateNum.cbegin()).first;
    if (rate > 0) {
      houseRate[afHouse] = rate;
      houseRateNum[rate]++;
    }


/*
    for(const auto& h : houses) {
      cout << "hno=" << h.first << "[";
      for (const auto& p : h.second.rateNum) {
        cout << "(rate=" << p.first << ",num=" << p.second << "),";

      }
      cout << "]" << endl;
    }
    for(const auto& h : houses) {
      houseRate[h.first] = (*h.second.rateNum.cbegin()).first;
      cout << "i=" << i <<  ",houseRate(" << h.first << ")=" << houseRate[h.first] << endl;
    }
    for (const auto& b : belong) {
      cout << "幼児" << b.first + 1 << "は" << b.second << "にいる" << endl;
    }
    for(const auto& h : houseRateNum) {
      cout << "rate=" << h.first <<  ",num=" << h.second << endl;
    }
    cout << "====" << endl;*/

    if (houseRateNum.find(0) != houseRateNum.end()) {
      houseRateNum.erase(0);
    }
    cout << (*houseRateNum.cbegin()).first << endl;
  }

  cout << endl;
  return 0;
}

