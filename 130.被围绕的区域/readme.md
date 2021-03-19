# 130.被围绕的区域

[题目链接](https://leetcode-cn.com/problems/surrounded-regions/)  

考察搜索的题，思路是从边界上的'O'开始，搜索所有与其相邻的'O'，对其进行标记，再遍历整个数组，将所有未被标记的'O'改为'X'即可。
