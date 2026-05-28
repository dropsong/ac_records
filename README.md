每道题目的分类、摘要、思路。


# 链表

## 环形链表（快慢指针）

https://leetcode.cn/problems/linked-list-cycle-ii/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/142.cc

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null.

最朴素的想法，用一个哈希表判断有没有来过。时间复杂度 $O(N)$, 空间复杂度 $O(N)$.

标准解法是使用快慢指针，快指针每次前进两个节点，慢指针每次前进一个节点。在具体判断哪个节点是入环节点时需要做一些数学推导。当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。时间复杂度 $O(N)$, 空间复杂度 $O(1)$.


# 图论

## 路径总和 III

https://leetcode.cn/problems/path-sum-iii/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/437.cc

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

朴素思路 O(n²) ：
1. 维护路径：用一个向量 path 记录从根节点到当前节点的完整路径
2. 遍历树：深度优先遍历整棵树，每次访问一个节点时：
    - 将该节点加入 path
    - 从当前节点向上遍历（使用反向迭代器 ``rbegin()``）到根节点
    - 累加路径上各节点的值
    - 如果累加和等于 target，则计数器 ans 加1
3. 回溯：继续遍历左右子树后，将当前节点从路径中移除

优化方案 O(n) ：前缀和 + HashMap 
- 思路类似于 ``leetcode/560.cc``
- 可以先看 560，然后再看下本题的代码实现。

## 从前序与中序遍历序列构造二叉树

https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/105.cc

给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

经典的递归。


# 动态规划

## 打家劫舍

https://leetcode.cn/problems/house-robber/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/198.cc

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

``dp(i) = MAX( dp(i-1), dp(i-2)+nums(i) )``


# 贪心

## 跳跃游戏

https://leetcode.cn/problems/jump-game/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/55.cc

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

暴力：这个方法会 tle, 但是 递归+剪枝 本身写的比较精巧。

贪心：遍历数组中的每一个位置，并实时维护最远可以到达的位置。

## 跳跃游戏 II

https://leetcode.cn/problems/jump-game-ii/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/45.cc

给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
每个元素 ``nums[i]`` 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
``0 <= j <= nums[i]`` 且 ``i + j < n``
返回到达 ``n - 1`` 的最小跳跃次数。测试用例保证可以到达 ``n - 1``。

可以动态规划，可以贪心。思路在代码里面。


# 数学


# 灵机一动

## Boyer-Moore 投票算法

https://leetcode.cn/problems/majority-element/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/169.cc

给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

朴素的想法是，用一个哈希表记录映射 $num \rightarrow cnt$，遍历 nums 维护哈希表，当 ``cnt[num] > nums.size() / 2`` 时，返回 ``num`` 即可。

标准解法是 Boyer-Moore 投票算法，大概的想法是：不同的两个数同归于尽，其他所有数都和众数不一样。因为众数比其他加起来都要多，即使最坏情况，其他所有数都和众数同归于尽，那最后剩下的也一定是众数。（整一个擂台赛，让一堆不同阵营的士兵互殴，不同阵营1换1同归于尽，杀到最后众数必胜）

具体实现上：

```
nums:      [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
candidate:  7  7  7  7  7  7   5  5   5  5  5  5   7  7  7  7
count:      1  2  1  2  1  0   1  0   1  2  1  0   1  2  3  4
```

## 长度最小的子数组

https://leetcode.cn/problems/minimum-size-subarray-sum/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/209.cc

给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 子数组（要求在原数组中连续），并返回其长度。如果不存在符合条件的子数组，返回 0 。

容易想到 $O(n\log n)$ 的解法：前缀和 + 二分答案。这里的边界处理值得注意。

标准解法是双指针。思路类似“模拟”中的《最小覆盖子串》这一题。

## 在排序数组中查找元素的第一个和最后一个位置

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/34.cc

给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 ``[-1, -1]``。你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

这题要求对二分查找的边界问题十分了解，是复习的好材料。

## 缺失的第一个正数

https://leetcode.cn/problems/first-missing-positive/description/

https://github.com/dropsong/ac_records/commit/2c8123269136f4e2d5cfc0c0cf6a9d12b483c944

给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

具体思路很难想到🤔，直接点进链接查看。


# 模拟/杂项

## 二分查找基础题

https://leetcode.cn/problems/search-a-2d-matrix/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/74.cc

一个矩阵里面的数，从左到右、从上到下地递增，查找一个数是否在矩阵中。

思路：相当于二维数组，先二分查找外壳，再二分查找内壳。
一般而论，左闭右开二分查找一个升序序列，若未找到，l 会停在第一个大于 target 的位置上。

## 最小覆盖子串

https://leetcode.cn/problems/minimum-window-substring/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/76.cc

给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。
测试用例保证答案唯一。

思路：双指针移动，每找到一个符合要求的就记录窗口大小，然后 shrink length l++，直到不满足要求为止。每次移动 r++，直到找到一个符合要求的窗口。细节实现起来比较麻烦。

使用如下的数据结构：

```cpp
std::unordered_map<char, int> wmap;  // map inside the sliding window, counting the letters
std::unordered_map<char, int> tmap;  // map counting the t's letters
```

## 函数的开始时间和结束时间

https://github.com/dropsong/ac_records/blob/master/others/func_start_end_time.py

一道常规的 Python 面试题。用装饰器实现。

## 电话号码的字母组合

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/17.cc

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

一个经典的递归入门题。

## 字符串解码

https://leetcode.cn/problems/decode-string/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/394.cc

给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: ``k[encoded_string]``，表示其中方括号内部的 ``encoded_string`` 正好重复 k 次。注意 k 保证为正整数。

可以比较自然地想到递归，但是实现起来有点麻烦。


# 数据结构

## 单调栈

https://leetcode.cn/problems/daily-temperatures/description/

https://github.com/dropsong/ac_records/commit/b4815336f06600d3aa0cf944bb394b1de49fce67

给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

思路可以自己想一下。

## 前 K 个高频元素

https://leetcode.cn/problems/top-k-frequent-elements/description/

https://github.com/dropsong/ac_records/blob/master/leetcode/347.cc

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。可以按任意顺序返回答案。

用堆就行，注意写法不同，访存效率不同。
