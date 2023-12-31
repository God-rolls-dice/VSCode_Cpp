#include <stdio.h>
int main()
{

    int a[10] = {3, 1, 2};
    int flag = 0;
    int b[a[flag]] = {0};
    for (int i = 0; i < 5; i ++)
    {
        printf("%d\n", b[i]);
    }
}