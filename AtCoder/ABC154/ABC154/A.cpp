#include<stdio.h>
#include<string.h>
int main()
{
    // 文字列2つの入力
    char s[11], t[11], u[11];
    scanf("%s %s",s, t);
    int a,b;
    // スペース区切りの整数の入力
    scanf("%d %d",&a,&b);
    // 文字列の入力
    scanf("%s",u);
    if (strcmp(s, u) == 0) {
        a--;
    } else {
        b--;
    }
    // 出力
    printf("%d %d\n",a, b);
    return 0;
}
