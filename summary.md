每道题目的分类、摘要、思路。

# 链表

## 环形链表（快慢指针）

https://leetcode.cn/problems/linked-list-cycle-ii/description/
https://github.com/dropsong/ac_records/blob/master/leetcode/142.cc
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null.

最朴素的想法，用一个哈希表判断有没有来过。时间复杂度 $O(N)$, 空间复杂度 $O(N)$.

标准解法是使用快慢指针，快指针每次前进两个节点，慢指针每次前进一个节点。在具体判断哪个节点是入环节点时需要做一些数学推导。当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。时间复杂度 $O(N)$, 空间复杂度 $O(1)$.


# 图论


# 动态规划


# 数学


# 灵机一动
