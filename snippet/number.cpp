#include <bits/stdc++.h>
using namespace std;

// 各桁の和を計算する関数
int sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}


int main(){

  cout << sumOfDigits(57) << endl;
  return 0;
}
