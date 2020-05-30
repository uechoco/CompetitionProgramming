#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


unsigned int get_digit(unsigned int num){
    unsigned int digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

//組み合わせの数nCrを計算
int combi(int n, int r){
   int num = 1;
   for(int i = 1; i <= r; i++){
       num = num * (n - i + 1) / i;
   }
   return num;
}

int main()
{
    char s[101];
    unsigned int n, k;
    // N ... 上限整数
    scanf("%d",&n);
    // K ... 0でない数字の個数。1 or 2 or 3
    scanf("%d",&k);
    
    
    snprintf(s, 101, "%d", n);
    unsigned int num = 0;
    unsigned int ketasuu = get_digit(n);
    
    printf("ketasuu %d \n", ketasuu);
    
    if (ketasuu - 1 > 0) {
        num += combi(ketasuu - 1, k) * 9;
    }
    
    
    // 出力
    printf("%d\n", num);
    return 0;
}
