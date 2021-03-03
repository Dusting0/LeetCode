# 63.不同路径II

[题目链接](https://leetcode-cn.com/problems/unique-paths-ii/)    

DP基础题，构建dp[m][n]，每个元素存储对应位置可达的总路径数，dp[0][0] = 1。  
然后对每个位置判断其上方和左方是否为障碍或边界，如果不是则加上对应位置的总路径数，即  

dp[m][n] += dp[m-1][n] 以及   
dp[m][n] += dp[m][n-1]，  

最后输出dp[m-1][n-1]即可。
