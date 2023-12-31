https://ac.nowcoder.com/acm/contest/67513/D?&headNav=acm&headNav=acm

思路：
1. 从起点和终点分别遍历到满足条件的点，然后相加步数，选择步数最小的点
2. 分别存储遇到条件点前的步数和遇到条件点后的步数用f[N][N][2]表示，全部初始化为最大值
