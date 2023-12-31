01背包:     每种物品只能拿一次
完全背包：  每种物品能拿多次
状态转移方程：
01背包：
每种商品只有拿还是不拿两种选择，就像01序列一样
``` C++
    public static int bag0_1(int[] w, int[] v, int n) { w[1 ~ n], j[1 ~ n]
        int[][] dp = new int[w.length + 1][n + 1];
        for (int i = 1; i <= w.length; i++) {   //  i表示第几件商品
            for (int j = 1; j <= n; j++) {      //  n表示背包容量   关键的循环保证更新每个空间的状态
                if (j < w[i]) {     //如果背包最大容量小于这个商品的那么就舍去第i件商品
                    dp[i][j] = dp[i - 1][j];
                } else {       
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);  //状态转移方程在前面拿的基础上看是否拿不拿
                }
            }
        }
        return dp[w.length][n];
    }
}
```
优化
``` C++
for (int i = 1; i <= n; i++)    //i为物品的编号
  for (int l = W; l >= w[i]; l--)   // W为背包容量，w[i]为物品的容量，注意循环方向
    f[l] = max(f[l], f[l - w[i]] + v[i]);   //这时f[l]总是先于f[l - w[i]]更新的所以不会相互影响

完全背包:
每种商品可以拿多次,对于某个物品关心的是拿多少次对

``` C++
    public static int bagComplete(int[] w, int[] v, int n) {
        int[][] dp = new int[w.length + 1][n + 1];
        for (int i = 1; i <= w.length; i++) {
            for (int j = 1; j <= n; j++) {      //顺序不能变
                if (j < w[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else { 
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);      //状态转移方程只要管拿得数量得价值能不能超过前面
                }
            }
        }
        return dp[w.length][n];
    }
``` 
优化
``` C++
 for (int i = 1; i <= n; i++)
    for (int l = w[i]; l <= W; l++)     //顺序不能变
        ckmax(f[l], f[l - w[i]] + v[i]);    //f[l - w[i]]先于f[l]更新

```
# a

## a4

`aaa`