#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}}; // 示例输入
    int res = countSquares(matrix);                                                   // 计算最多可以构成多少个全部由1构成的正方形
    cout << "最多可以构成 " << res << " 个全部由1构成的正方形" << endl;
    return 0;
}
