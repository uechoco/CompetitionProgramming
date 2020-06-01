#include <bits/stdc++.h>
using namespace std;

// 円周率
const double DOUBLE_PI = acos(-1.0);
const long double LONGDOUBLE_PI = acosl(-1.0);

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

  // 浮動小数点型の桁数を指定出来るマニピュレータ
  cout << std::fixed << std::setprecision(8) << (double)(12.9295871325) << endl;


  cout << sumOfDigits(57) << endl;
  return 0;
}
