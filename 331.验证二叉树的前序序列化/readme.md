# 331. 验证二叉树的前序序列化

[题目链接](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)

本来想用字符串分割构造子树的方法来做，但是没优化导致递归太多超时。  
看了题解之后才发现原来栈还可以这么用。
