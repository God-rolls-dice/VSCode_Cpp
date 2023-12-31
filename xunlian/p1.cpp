
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    freopen("iostream\\input.text", "r", stdin);   // 输入重定向，输入数据将从D盘根目录下的in.txt文件中读取
    freopen("iostream\\output.text", "w", stdout); // 输出重定向，输出数据将保存在D盘根目录下的out.txt文件中
    while (cin >> a >> b)
        cout << a + b << endl; // 注意使用endl
    fclose(stdin);             // 关闭文件
    fclose(stdout);            // 关闭文件
    return 0;
}