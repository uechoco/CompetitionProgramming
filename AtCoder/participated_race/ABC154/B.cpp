
#include<stdio.h>
#include<string.h>
int main()
{
    char s[101];
    scanf("%s",s);
    size_t num = strlen(s);
    for (int i = 0; i < num; ++i) {
        printf("x");
    }
    return 0;
}
