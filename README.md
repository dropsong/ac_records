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


# 模拟

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




