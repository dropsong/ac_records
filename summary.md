Prompt for my dear AI agents:
这个仓库里积累了我刷过的题，请将每道题目分类总结至本文件内。要求如下：
- 你可以参照已有内容。
- 每一道题目要有标题（可以用题号替代）、题目描述、解法的摘要。
- 分类可能不全面，你可以自己增加，包括一级标题和二级标题。
- 一道题目或许可以属于多个分类，在其每个分类下都要体现，思路可以只在一处写，其他处做 html 跳转。
- 每个代码文件的首行可能有题目的来源链接，若如此，需要附上链接。
- 部分文件名中包含了简要解法，部分 git commit 信息中有简要解法，部分代码文件中的注释写了解法，你可以参考。
- 除了本 markdown 文件，不要修改其他文件。

-----

# 题目分类总结

说明：本总结按代码文件和文件名标签整理；同一题的 AC/TLE/wrong 或不同复杂度版本合并为一个条目。若题目出现在多个分类，主分类保留完整描述，其他分类使用 HTML 锚点跳转。

# 图论

## <a id="bzoj-1016"></a>BZOJ 1016

- 代码文件：`BZOJ/1016(MST).cc`
- 分类标签：MST
- 题目描述：BZOJ 1016，题面以原题为准；代码主要围绕「MST」实现。
- 解法摘要：使用最小生成树相关算法，按边权组织边并维护连通性。

## <a id="bzoj-1051"></a>BZOJ 1051

- 代码文件：`BZOJ/1051(tarjan).cc`
- 分类标签：tarjan
- 题目描述：BZOJ 1051，题面以原题为准；代码主要围绕「tarjan」实现。
- 解法摘要：Tarjan 求强连通分量/割点等结构，再在缩点图或结果上处理。

## <a id="uva-437"></a>UVA 437

- 来源链接：[https://onlinejudge.org/external/4/437.pdf](https://onlinejudge.org/external/4/437.pdf)
- 代码文件：`UVA/437(dagdp).cc`
- 分类标签：dagdp
- 题目描述：UVA 437，题面以原题为准；代码主要围绕「dagdp」实现。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。
- 交叉分类：动态规划

## <a id="uva-10048"></a>UVA 10048

- 来源链接：[https://onlinejudge.org/external/100/10048.pdf](https://onlinejudge.org/external/100/10048.pdf)
- 代码文件：`UVA/10048(图论).cc`
- 分类标签：图论
- 题目描述：UVA 10048，题面以原题为准；代码主要围绕「图论」实现。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="uva-11624"></a>UVA 11624

- 来源链接：[https://onlinejudge.org/external/116/11624.pdf](https://onlinejudge.org/external/116/11624.pdf)
- 代码文件：`UVA/11624(bfs).cc`
- 分类标签：bfs
- 题目描述：UVA 11624，题面以原题为准；代码主要围绕「bfs」实现。
- 解法摘要：广度优先分层扩展，适合最短步数或连通块。
- 交叉分类：搜索与回溯

## <a id="codeforces-173b"></a>Codeforces 173B

- 代码文件：`codeforces/173B(01bfs).cc`
- 分类标签：01bfs
- 题目描述：Codeforces 173B，题面以原题为准；代码主要围绕「01bfs」实现。
- 解法摘要：广度优先分层扩展，适合最短步数或连通块。
- 交叉分类：搜索与回溯

- <a href="#codeforces-519e">Codeforces 519E</a>：亦可归入「图论」，完整思路见主条目。
- <a href="#leetcode-199">LeetCode 199. 二叉树的右视图</a>：亦可归入「图论」，完整思路见主条目。

## <a id="leetcode-407"></a>LeetCode 407. 接雨水 II

- 代码文件：`leetcode/407.cc`、`leetcode/407_tle.cc`、`leetcode/407_wrong.cc`
- 题目描述：二维高度图中计算可接雨水。
- 解法摘要：从边界入小根堆做 BFS，按最低外墙向内扩展并累加水量。

## <a id="luogu-1037"></a>洛谷 P1037

- 来源链接：[https://www.luogu.com.cn/problem/P1037](https://www.luogu.com.cn/problem/P1037)
- 代码文件：`luogu/1037(图论建模).cc`
- 分类标签：图论建模
- 题目描述：洛谷 P1037，题面以原题链接为准；代码标签显示主要考点为「图论建模」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-1061"></a>洛谷 P1061

- 来源链接：[https://www.luogu.com.cn/problem/P1061](https://www.luogu.com.cn/problem/P1061)
- 代码文件：`luogu/1061(dfs).cc`
- 分类标签：dfs
- 题目描述：洛谷 P1061，题面以原题链接为准；代码标签显示主要考点为「dfs」。
- 解法摘要：深度优先遍历状态空间，递归回溯恢复现场。
- 交叉分类：搜索与回溯

## <a id="luogu-1111"></a>洛谷 P1111

- 来源链接：[https://www.luogu.com.cn/problem/P1111](https://www.luogu.com.cn/problem/P1111)
- 代码文件：`luogu/1111(kruscal).cc`
- 分类标签：kruscal
- 题目描述：洛谷 P1111，题面以原题链接为准；代码标签显示主要考点为「kruscal」。
- 解法摘要：Kruskal 按边权排序，用并查集维护连通块。

## <a id="luogu-1119"></a>洛谷 P1119

- 来源链接：[https://www.luogu.com.cn/problem/P1119](https://www.luogu.com.cn/problem/P1119)
- 代码文件：`luogu/1119(floyd).cc`
- 分类标签：floyd
- 题目描述：洛谷 P1119，题面以原题链接为准；代码标签显示主要考点为「floyd」。
- 解法摘要：Floyd 多源最短路/传递闭包，枚举中转点更新状态。

## <a id="luogu-1144"></a>洛谷 P1144

- 来源链接：[https://www.luogu.com.cn/problem/P1144](https://www.luogu.com.cn/problem/P1144)
- 代码文件：`luogu/1144(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P1144，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-1330"></a>洛谷 P1330

- 来源链接：[https://www.luogu.com.cn/problem/P1330](https://www.luogu.com.cn/problem/P1330)
- 代码文件：`luogu/1330(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P1330，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-1339"></a>洛谷 P1339

- 来源链接：[https://www.luogu.com.cn/problem/P1339](https://www.luogu.com.cn/problem/P1339)
- 代码文件：`luogu/1339(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P1339，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-1341"></a>洛谷 P1341

- 来源链接：[https://www.luogu.com.cn/problem/P1341](https://www.luogu.com.cn/problem/P1341)
- 代码文件：`luogu/1341(欧拉回路).cc`
- 分类标签：欧拉回路
- 题目描述：洛谷 P1341，题面以原题链接为准；代码标签显示主要考点为「欧拉回路」。
- 解法摘要：依据题意建模，核心实现标签为「欧拉回路」，重点处理输入规模和边界。

## <a id="luogu-1346"></a>洛谷 P1346

- 来源链接：[https://www.luogu.com.cn/problem/P1346](https://www.luogu.com.cn/problem/P1346)
- 代码文件：`luogu/1346(图论floyd).cc`
- 分类标签：图论floyd
- 题目描述：洛谷 P1346，题面以原题链接为准；代码标签显示主要考点为「图论floyd」。
- 解法摘要：Floyd 多源最短路/传递闭包，枚举中转点更新状态。

## <a id="luogu-1378"></a>洛谷 P1378

- 来源链接：[https://www.luogu.com.cn/problem/P1378](https://www.luogu.com.cn/problem/P1378)
- 代码文件：`luogu/1378(dfs).cc`
- 分类标签：dfs
- 题目描述：洛谷 P1378，题面以原题链接为准；代码标签显示主要考点为「dfs」。
- 解法摘要：深度优先遍历状态空间，递归回溯恢复现场。
- 交叉分类：搜索与回溯

## <a id="luogu-1546"></a>洛谷 P1546

- 来源链接：[https://www.luogu.com.cn/problem/P1546](https://www.luogu.com.cn/problem/P1546)
- 代码文件：`luogu/1546(kruscal).cc`
- 分类标签：kruscal
- 题目描述：洛谷 P1546，题面以原题链接为准；代码标签显示主要考点为「kruscal」。
- 解法摘要：Kruskal 按边权排序，用并查集维护连通块。

## <a id="luogu-1550"></a>洛谷 P1550

- 来源链接：[https://www.luogu.com.cn/problem/P1550](https://www.luogu.com.cn/problem/P1550)
- 代码文件：`luogu/1550(kruscal).cc`
- 分类标签：kruscal
- 题目描述：洛谷 P1550，题面以原题链接为准；代码标签显示主要考点为「kruscal」。
- 解法摘要：Kruskal 按边权排序，用并查集维护连通块。

## <a id="luogu-1551"></a>洛谷 P1551

- 来源链接：[https://www.luogu.com.cn/problem/P1551](https://www.luogu.com.cn/problem/P1551)
- 代码文件：`luogu/1551(并查集).cc`
- 分类标签：并查集
- 题目描述：洛谷 P1551，题面以原题链接为准；代码标签显示主要考点为「并查集」。
- 解法摘要：并查集合并和查询集合关系，路径压缩优化。

## <a id="luogu-1692"></a>洛谷 P1692

- 来源链接：[https://www.luogu.com.cn/problem/P1692](https://www.luogu.com.cn/problem/P1692)
- 代码文件：`luogu/1692(dfs).cc`
- 分类标签：dfs
- 题目描述：洛谷 P1692，题面以原题链接为准；代码标签显示主要考点为「dfs」。
- 解法摘要：深度优先遍历状态空间，递归回溯恢复现场。
- 交叉分类：搜索与回溯

## <a id="luogu-1807"></a>洛谷 P1807

- 来源链接：[https://www.luogu.com.cn/problem/P1807](https://www.luogu.com.cn/problem/P1807)
- 代码文件：`luogu/1807(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P1807，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-1991"></a>洛谷 P1991

- 来源链接：[https://www.luogu.com.cn/problem/P1991](https://www.luogu.com.cn/problem/P1991)
- 代码文件：`luogu/1991(MST).cc`
- 分类标签：MST
- 题目描述：洛谷 P1991，题面以原题链接为准；代码标签显示主要考点为「MST」。
- 解法摘要：使用最小生成树相关算法，按边权组织边并维护连通性。

## <a id="luogu-2078"></a>洛谷 P2078

- 来源链接：[https://www.luogu.com.cn/problem/P2078](https://www.luogu.com.cn/problem/P2078)
- 代码文件：`luogu/2078(并查集).cc`
- 分类标签：并查集
- 题目描述：洛谷 P2078，题面以原题链接为准；代码标签显示主要考点为「并查集」。
- 解法摘要：并查集合并和查询集合关系，路径压缩优化。

## <a id="luogu-2176"></a>洛谷 P2176

- 来源链接：[https://www.luogu.com.cn/problem/P2176](https://www.luogu.com.cn/problem/P2176)
- 代码文件：`luogu/2176(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P2176，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-2196"></a>洛谷 P2196

- 来源链接：[https://www.luogu.com.cn/problem/P2196](https://www.luogu.com.cn/problem/P2196)
- 代码文件：`luogu/2196(图+dp).cc`
- 分类标签：图+dp
- 题目描述：洛谷 P2196，题面以原题链接为准；代码标签显示主要考点为「图+dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。
- 交叉分类：动态规划

## <a id="luogu-2296"></a>洛谷 P2296

- 来源链接：[https://www.luogu.com.cn/problem/P2296](https://www.luogu.com.cn/problem/P2296)
- 代码文件：`luogu/2296(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P2296，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-2330"></a>洛谷 P2330

- 来源链接：[https://www.luogu.com.cn/problem/P2330](https://www.luogu.com.cn/problem/P2330)
- 代码文件：`luogu/2330(kruscal).cc`
- 分类标签：kruscal
- 题目描述：洛谷 P2330，题面以原题链接为准；代码标签显示主要考点为「kruscal」。
- 解法摘要：Kruskal 按边权排序，用并查集维护连通块。

## <a id="luogu-2419"></a>洛谷 P2419

- 来源链接：[https://www.luogu.com.cn/problem/P2419](https://www.luogu.com.cn/problem/P2419)
- 代码文件：`luogu/2419(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P2419，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-2661"></a>洛谷 P2661

- 来源链接：[https://www.luogu.com.cn/problem/P2661](https://www.luogu.com.cn/problem/P2661)
- 代码文件：`luogu/2661(图论tarjan).cc`
- 分类标签：图论tarjan
- 题目描述：洛谷 P2661，题面以原题链接为准；代码标签显示主要考点为「图论tarjan」。
- 解法摘要：Tarjan 求强连通分量/割点等结构，再在缩点图或结果上处理。

- <a href="#luogu-2680">洛谷 P2680</a>：亦可归入「图论」，完整思路见主条目。
- <a href="#luogu-2783">洛谷 P2783</a>：亦可归入「图论」，完整思路见主条目。

## <a id="luogu-2921"></a>洛谷 P2921

- 来源链接：[https://www.luogu.com.cn/problem/P2921](https://www.luogu.com.cn/problem/P2921)
- 代码文件：`luogu/2921(tarjan&DAGdp).cc`
- 分类标签：tarjan&DAGdp
- 题目描述：洛谷 P2921，题面以原题链接为准；代码标签显示主要考点为「tarjan&DAGdp」。
- 解法摘要：Tarjan 求强连通分量/割点等结构，再在缩点图或结果上处理。
- 交叉分类：动态规划

## <a id="luogu-3003"></a>洛谷 P3003

- 来源链接：[https://www.luogu.com.cn/problem/P3003](https://www.luogu.com.cn/problem/P3003)
- 代码文件：`luogu/3003(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P3003，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-3366"></a>洛谷 P3366

- 来源链接：[https://www.luogu.com.cn/problem/P3366](https://www.luogu.com.cn/problem/P3366)
- 代码文件：`luogu/3366(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P3366，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-3367"></a>洛谷 P3367

- 来源链接：[https://www.luogu.com.cn/problem/P3367](https://www.luogu.com.cn/problem/P3367)
- 代码文件：`luogu/3367(并查集).cc`
- 分类标签：并查集
- 题目描述：洛谷 P3367，题面以原题链接为准；代码标签显示主要考点为「并查集」。
- 解法摘要：并查集合并和查询集合关系，路径压缩优化。

## <a id="luogu-3371"></a>洛谷 P3371

- 来源链接：[https://www.luogu.com.cn/problem/P3371](https://www.luogu.com.cn/problem/P3371)
- 代码文件：`luogu/3371(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P3371，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

- <a href="#luogu-3379">洛谷 P3379</a>：亦可归入「图论」，完整思路见主条目。

## <a id="luogu-3388"></a>洛谷 P3388

- 来源链接：[https://www.luogu.com.cn/problem/P3388](https://www.luogu.com.cn/problem/P3388)
- 代码文件：`luogu/3388(割点).cpp`
- 分类标签：割点
- 题目描述：洛谷 P3388，题面以原题链接为准；代码标签显示主要考点为「割点」。
- 解法摘要：依据题意建模，核心实现标签为「割点」，重点处理输入规模和边界。

## <a id="luogu-3958"></a>洛谷 P3958

- 来源链接：[https://www.luogu.com.cn/problem/P3958](https://www.luogu.com.cn/problem/P3958)
- 代码文件：`luogu/3958(bfs).cc`
- 分类标签：bfs
- 题目描述：洛谷 P3958，题面以原题链接为准；代码标签显示主要考点为「bfs」。
- 解法摘要：广度优先分层扩展，适合最短步数或连通块。
- 交叉分类：搜索与回溯

## <a id="luogu-4017"></a>洛谷 P4017

- 来源链接：[https://www.luogu.com.cn/problem/P4017](https://www.luogu.com.cn/problem/P4017)
- 代码文件：`luogu/4017(图论+dp).cc`
- 分类标签：图论+dp
- 题目描述：洛谷 P4017，题面以原题链接为准；代码标签显示主要考点为「图论+dp」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。
- 交叉分类：动态规划

## <a id="luogu-4779"></a>洛谷 P4779

- 来源链接：[https://www.luogu.com.cn/problem/P4779](https://www.luogu.com.cn/problem/P4779)
- 代码文件：`luogu/4779(图论).cc`
- 分类标签：图论
- 题目描述：洛谷 P4779，题面以原题链接为准；代码标签显示主要考点为「图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。

## <a id="luogu-4995"></a>洛谷 P4995

- 来源链接：[https://www.luogu.com.cn/problem/P4995](https://www.luogu.com.cn/problem/P4995)
- 代码文件：`luogu/4995(贪心或图论).cc`
- 分类标签：贪心或图论
- 题目描述：洛谷 P4995，题面以原题链接为准；代码标签显示主要考点为「贪心或图论」。
- 解法摘要：建图后按题意选择 BFS、最短路、拓扑或连通性算法。
- 交叉分类：数组、双指针与贪心

## <a id="luogu-5908"></a>洛谷 P5908

- 来源链接：[https://www.luogu.com.cn/problem/P5908](https://www.luogu.com.cn/problem/P5908)
- 代码文件：`luogu/5908(dfs).cpp`
- 分类标签：dfs
- 题目描述：洛谷 P5908，题面以原题链接为准；代码标签显示主要考点为「dfs」。
- 解法摘要：深度优先遍历状态空间，递归回溯恢复现场。
- 交叉分类：搜索与回溯

# 动态规划

## <a id="uva-116"></a>UVA 116

- 来源链接：[https://onlinejudge.org/external/1/116.pdf](https://onlinejudge.org/external/1/116.pdf)
- 代码文件：`UVA/116(dp).cc`
- 分类标签：dp
- 题目描述：UVA 116，题面以原题为准；代码主要围绕「dp」实现。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

- <a href="#uva-437">UVA 437</a>：亦可归入「动态规划」，完整思路见主条目。

## <a id="uva-1025"></a>UVA 1025

- 来源链接：[https://www.luogu.org/problemnew/show/UVA1025](https://www.luogu.org/problemnew/show/UVA1025)；[https://onlinejudge.org/external/10/1025.pdf](https://onlinejudge.org/external/10/1025.pdf)
- 代码文件：`UVA/1025(dp).cc`
- 分类标签：dp
- 题目描述：UVA 1025，题面以原题为准；代码主要围绕「dp」实现。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="leetcode-5"></a>LeetCode 5. 最长回文子串

- 来源链接：[https://leetcode.cn/problems/longest-palindromic-substring/description/](https://leetcode.cn/problems/longest-palindromic-substring/description/)
- 代码文件：`leetcode/5(dp).cc`
- 分类标签：dp
- 题目描述：求字符串中的最长回文连续子串。
- 解法摘要：动态规划判断区间是否回文，或按中心扩展更新答案。
- 交叉分类：字符串

## <a id="luogu-1018"></a>洛谷 P1018

- 来源链接：[https://www.luogu.com.cn/problem/P1018](https://www.luogu.com.cn/problem/P1018)
- 代码文件：`luogu/1018(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P1018，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1020"></a>洛谷 P1020

- 来源链接：[https://www.luogu.com.cn/problem/P1020](https://www.luogu.com.cn/problem/P1020)
- 代码文件：`luogu/1020(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P1020，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1040"></a>洛谷 P1040

- 来源链接：[https://www.luogu.com.cn/problem/P1040](https://www.luogu.com.cn/problem/P1040)
- 代码文件：`luogu/1040(区间dp).cc`
- 分类标签：区间dp
- 题目描述：洛谷 P1040，题面以原题链接为准；代码标签显示主要考点为「区间dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1048"></a>洛谷 P1048

- 来源链接：[https://www.luogu.com.cn/problem/P1048](https://www.luogu.com.cn/problem/P1048)
- 代码文件：`luogu/1048(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1048，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1049"></a>洛谷 P1049

- 来源链接：[https://www.luogu.com.cn/problem/P1049](https://www.luogu.com.cn/problem/P1049)
- 代码文件：`luogu/1049(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1049，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1060"></a>洛谷 P1060

- 来源链接：[https://www.luogu.com.cn/problem/P1060](https://www.luogu.com.cn/problem/P1060)
- 代码文件：`luogu/1060(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1060，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1063"></a>洛谷 P1063

- 来源链接：[https://www.luogu.com.cn/problem/P1063](https://www.luogu.com.cn/problem/P1063)
- 代码文件：`luogu/1063(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P1063，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1091"></a>洛谷 P1091

- 来源链接：[https://www.luogu.com.cn/problem/P1091](https://www.luogu.com.cn/problem/P1091)
- 代码文件：`luogu/1091(线性dp).cc`
- 分类标签：线性dp
- 题目描述：洛谷 P1091，题面以原题链接为准；代码标签显示主要考点为「线性dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1140"></a>洛谷 P1140

- 来源链接：[https://www.luogu.com.cn/problem/P1140](https://www.luogu.com.cn/problem/P1140)
- 代码文件：`luogu/1140(区间dp).cc`
- 分类标签：区间dp
- 题目描述：洛谷 P1140，题面以原题链接为准；代码标签显示主要考点为「区间dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1164"></a>洛谷 P1164

- 来源链接：[https://www.luogu.com.cn/problem/P1164](https://www.luogu.com.cn/problem/P1164)
- 代码文件：`luogu/1164(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1164，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1192"></a>洛谷 P1192

- 来源链接：[https://www.luogu.com.cn/problem/P1192](https://www.luogu.com.cn/problem/P1192)
- 代码文件：`luogu/1192(递推).cc`
- 分类标签：递推
- 题目描述：洛谷 P1192，题面以原题链接为准；代码标签显示主要考点为「递推」。
- 解法摘要：依据题意建模，核心实现标签为「递推」，重点处理输入规模和边界。

## <a id="luogu-1216"></a>洛谷 P1216

- 来源链接：[https://www.luogu.com.cn/problem/P1216](https://www.luogu.com.cn/problem/P1216)
- 代码文件：`luogu/1216(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P1216，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1439"></a>洛谷 P1439

- 来源链接：[https://www.luogu.com.cn/problem/P1439](https://www.luogu.com.cn/problem/P1439)
- 代码文件：`luogu/1439(线性dp).cc`
- 分类标签：线性dp
- 题目描述：洛谷 P1439，题面以原题链接为准；代码标签显示主要考点为「线性dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1441"></a>洛谷 P1441

- 来源链接：[https://www.luogu.com.cn/problem/P1441](https://www.luogu.com.cn/problem/P1441)
- 代码文件：`luogu/1441(搜索+dp).cc`
- 分类标签：搜索+dp
- 题目描述：洛谷 P1441，题面以原题链接为准；代码标签显示主要考点为「搜索+dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。
- 交叉分类：搜索与回溯

## <a id="luogu-1508"></a>洛谷 P1508

- 来源链接：[https://www.luogu.com.cn/problem/P1508](https://www.luogu.com.cn/problem/P1508)
- 代码文件：`luogu/1508(多维dp).cc`
- 分类标签：多维dp
- 题目描述：洛谷 P1508，题面以原题链接为准；代码标签显示主要考点为「多维dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1616"></a>洛谷 P1616

- 来源链接：[https://www.luogu.com.cn/problem/P1616](https://www.luogu.com.cn/problem/P1616)
- 代码文件：`luogu/1616(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1616，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1833"></a>洛谷 P1833

- 来源链接：[https://www.luogu.com.cn/problem/P1833](https://www.luogu.com.cn/problem/P1833)
- 代码文件：`luogu/1833(背包).cc`
- 分类标签：背包
- 题目描述：洛谷 P1833，题面以原题链接为准；代码标签显示主要考点为「背包」。
- 解法摘要：按容量维度做 0/1、完全或多维背包转移。

## <a id="luogu-1855"></a>洛谷 P1855

- 来源链接：[https://www.luogu.com.cn/problem/P1855](https://www.luogu.com.cn/problem/P1855)
- 代码文件：`luogu/1855(多维dp).cc`
- 分类标签：多维dp
- 题目描述：洛谷 P1855，题面以原题链接为准；代码标签显示主要考点为「多维dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1879"></a>洛谷 P1879

- 来源链接：[https://www.luogu.com.cn/problem/P1879](https://www.luogu.com.cn/problem/P1879)
- 代码文件：`luogu/1879(状压dp).cc`
- 分类标签：状压dp
- 题目描述：洛谷 P1879，题面以原题链接为准；代码标签显示主要考点为「状压dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-1880"></a>洛谷 P1880

- 来源链接：[https://www.luogu.com.cn/problem/P1880](https://www.luogu.com.cn/problem/P1880)
- 代码文件：`luogu/1880(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P1880，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

- <a href="#luogu-2196">洛谷 P2196</a>：亦可归入「动态规划」，完整思路见主条目。

## <a id="luogu-2386"></a>洛谷 P2386

- 来源链接：[https://www.luogu.com.cn/problem/P2386](https://www.luogu.com.cn/problem/P2386)
- 代码文件：`luogu/2386(dp).cc`
- 分类标签：dp
- 题目描述：洛谷 P2386，题面以原题链接为准；代码标签显示主要考点为「dp」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

- <a href="#luogu-2921">洛谷 P2921</a>：亦可归入「动态规划」，完整思路见主条目。
- <a href="#luogu-4017">洛谷 P4017</a>：亦可归入「动态规划」，完整思路见主条目。

## <a id="luogu-4310"></a>洛谷 P4310

- 来源链接：[https://www.luogu.com.cn/problem/P4310](https://www.luogu.com.cn/problem/P4310)
- 代码文件：`luogu/4310(dp-TLE).cc`、`luogu/4310.cc`
- 分类标签：dp-TLE
- 题目描述：洛谷 P4310，题面以原题链接为准；代码标签显示主要考点为「dp-TLE」。
- 解法摘要：定义状态表示前缀/区间/集合最优值，再按转移递推。

## <a id="luogu-5507"></a>洛谷 P5507

- 来源链接：[https://www.luogu.com.cn/problem/P5507](https://www.luogu.com.cn/problem/P5507)
- 代码文件：`luogu/5507(状压Astar).cc`
- 分类标签：状压Astar
- 题目描述：洛谷 P5507，题面以原题链接为准；代码标签显示主要考点为「状压Astar」。
- 解法摘要：用二进制集合表示状态，在状态之间转移或搜索。
- 交叉分类：搜索与回溯

# 搜索与回溯

## <a id="uva-307"></a>UVA 307

- 来源链接：[https://onlinejudge.org/external/3/307.pdf](https://onlinejudge.org/external/3/307.pdf)
- 代码文件：`UVA/307(搜索&剪枝).cc`
- 分类标签：搜索&剪枝
- 题目描述：UVA 307，题面以原题为准；代码主要围绕「搜索&剪枝」实现。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="uva-524"></a>UVA 524

- 来源链接：[https://onlinejudge.org/external/5/524.pdf](https://onlinejudge.org/external/5/524.pdf)
- 代码文件：`UVA/524(搜索).cc`
- 分类标签：搜索
- 题目描述：UVA 524，题面以原题为准；代码主要围绕「搜索」实现。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#uva-11624">UVA 11624</a>：亦可归入「搜索与回溯」，完整思路见主条目。
- <a href="#codeforces-173b">Codeforces 173B</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="leetcode-35"></a>LeetCode 35. 搜索插入位置

- 来源链接：[https://leetcode.cn/problems/search-insert-position/description/](https://leetcode.cn/problems/search-insert-position/description/)
- 代码文件：`leetcode/35.cc`
- 题目描述：在有序数组中找目标值或插入位置。
- 解法摘要：标准二分找第一个不小于 target 的位置。
- 交叉分类：数组、双指针与贪心

## <a id="leetcode-74"></a>LeetCode 74. 搜索二维矩阵

- 来源链接：[https://leetcode.cn/problems/search-a-2d-matrix/description/](https://leetcode.cn/problems/search-a-2d-matrix/description/)
- 代码文件：`leetcode/74.cc`
- 题目描述：在行列有序且行首行尾衔接的矩阵中查找目标。
- 解法摘要：把矩阵视作一维有序数组做二分。

- <a href="#leetcode-98">LeetCode 98. 验证二叉搜索树</a>：亦可归入「搜索与回溯」，完整思路见主条目。
- <a href="#leetcode-108">LeetCode 108. 将有序数组转换为二叉搜索树</a>：亦可归入「搜索与回溯」，完整思路见主条目。
- <a href="#leetcode-230">LeetCode 230. 二叉搜索树中第 K 小的元素</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="luogu-1019"></a>洛谷 P1019

- 来源链接：[https://www.luogu.com.cn/problem/P1019](https://www.luogu.com.cn/problem/P1019)
- 代码文件：`luogu/1019(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1019，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1025"></a>洛谷 P1025

- 来源链接：[https://www.luogu.com.cn/problem/P1025](https://www.luogu.com.cn/problem/P1025)
- 代码文件：`luogu/1025(搜索剪枝).cc`
- 分类标签：搜索剪枝
- 题目描述：洛谷 P1025，题面以原题链接为准；代码标签显示主要考点为「搜索剪枝」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1032"></a>洛谷 P1032

- 来源链接：[https://www.luogu.com.cn/problem/P1032](https://www.luogu.com.cn/problem/P1032)
- 代码文件：`luogu/1032(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1032，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1036"></a>洛谷 P1036

- 来源链接：[https://www.luogu.com.cn/problem/P1036](https://www.luogu.com.cn/problem/P1036)
- 代码文件：`luogu/1036(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1036，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#luogu-1061">洛谷 P1061</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="luogu-1101"></a>洛谷 P1101

- 来源链接：[https://www.luogu.com.cn/problem/P1101](https://www.luogu.com.cn/problem/P1101)
- 代码文件：`luogu/1101(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1101，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1118"></a>洛谷 P1118

- 来源链接：[https://www.luogu.com.cn/problem/P1118](https://www.luogu.com.cn/problem/P1118)
- 代码文件：`luogu/1118(数学优化搜索).cc`
- 分类标签：数学优化搜索
- 题目描述：洛谷 P1118，题面以原题链接为准；代码标签显示主要考点为「数学优化搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。
- 交叉分类：数学与数论

## <a id="luogu-1120"></a>洛谷 P1120

- 来源链接：[https://www.luogu.com.cn/problem/P1120](https://www.luogu.com.cn/problem/P1120)
- 代码文件：`luogu/1120(剪枝).cc`
- 分类标签：剪枝
- 题目描述：洛谷 P1120，题面以原题链接为准；代码标签显示主要考点为「剪枝」。
- 解法摘要：依据题意建模，核心实现标签为「剪枝」，重点处理输入规模和边界。

## <a id="luogu-1126"></a>洛谷 P1126

- 来源链接：[https://www.luogu.com.cn/problem/P1126](https://www.luogu.com.cn/problem/P1126)
- 代码文件：`luogu/1126(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1126，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1135"></a>洛谷 P1135

- 来源链接：[https://www.luogu.com.cn/problem/P1135](https://www.luogu.com.cn/problem/P1135)
- 代码文件：`luogu/1135(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1135，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1141"></a>洛谷 P1141

- 来源链接：[https://www.luogu.com.cn/problem/P1141](https://www.luogu.com.cn/problem/P1141)
- 代码文件：`luogu/1141(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1141，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1242"></a>洛谷 P1242

- 来源链接：[https://www.luogu.com.cn/problem/P1242](https://www.luogu.com.cn/problem/P1242)
- 代码文件：`luogu/1242(搜索&玄学).cc`
- 分类标签：搜索&玄学
- 题目描述：洛谷 P1242，题面以原题链接为准；代码标签显示主要考点为「搜索&玄学」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1363"></a>洛谷 P1363

- 来源链接：[https://www.luogu.com.cn/problem/P1363](https://www.luogu.com.cn/problem/P1363)
- 代码文件：`luogu/1363(搜索_观察).cc`
- 分类标签：搜索_观察
- 题目描述：洛谷 P1363，题面以原题链接为准；代码标签显示主要考点为「搜索_观察」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#luogu-1378">洛谷 P1378</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="luogu-1379"></a>洛谷 P1379

- 来源链接：[https://www.luogu.com.cn/problem/P1379](https://www.luogu.com.cn/problem/P1379)
- 代码文件：`luogu/1379(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1379，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1433"></a>洛谷 P1433

- 来源链接：[https://www.luogu.com.cn/problem/P1433](https://www.luogu.com.cn/problem/P1433)
- 代码文件：`luogu/1433(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1433，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#luogu-1441">洛谷 P1441</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="luogu-1443"></a>洛谷 P1443

- 来源链接：[https://www.luogu.com.cn/problem/P1443](https://www.luogu.com.cn/problem/P1443)
- 代码文件：`luogu/1443(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1443，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1464"></a>洛谷 P1464

- 来源链接：[https://www.luogu.com.cn/problem/P1464](https://www.luogu.com.cn/problem/P1464)
- 代码文件：`luogu/1464(搜索·大整数).cc`
- 分类标签：搜索·大整数
- 题目描述：洛谷 P1464，题面以原题链接为准；代码标签显示主要考点为「搜索·大整数」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。
- 交叉分类：数学与数论

## <a id="luogu-1588"></a>洛谷 P1588

- 来源链接：[https://www.luogu.com.cn/problem/P1588](https://www.luogu.com.cn/problem/P1588)
- 代码文件：`luogu/1588(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1588，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-1605"></a>洛谷 P1605

- 来源链接：[https://www.luogu.com.cn/problem/P1605](https://www.luogu.com.cn/problem/P1605)
- 代码文件：`luogu/1605(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1605，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#luogu-1692">洛谷 P1692</a>：亦可归入「搜索与回溯」，完整思路见主条目。

## <a id="luogu-1767"></a>洛谷 P1767

- 来源链接：[https://www.luogu.com.cn/problem/P1767](https://www.luogu.com.cn/problem/P1767)
- 代码文件：`luogu/1767(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P1767，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-2089"></a>洛谷 P2089

- 来源链接：[https://www.luogu.com.cn/problem/P2089](https://www.luogu.com.cn/problem/P2089)
- 代码文件：`luogu/2089(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P2089，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-2324"></a>洛谷 P2324

- 来源链接：[https://www.luogu.com.cn/problem/P2324](https://www.luogu.com.cn/problem/P2324)
- 代码文件：`luogu/2324(IDAstar).cc`
- 分类标签：IDAstar
- 题目描述：洛谷 P2324，题面以原题链接为准；代码标签显示主要考点为「IDAstar」。
- 解法摘要：依据题意建模，核心实现标签为「IDAstar」，重点处理输入规模和边界。

## <a id="luogu-2404"></a>洛谷 P2404

- 来源链接：[https://www.luogu.com.cn/problem/P2404](https://www.luogu.com.cn/problem/P2404)
- 代码文件：`luogu/2404(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P2404，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

## <a id="luogu-3956"></a>洛谷 P3956

- 来源链接：[https://www.luogu.com.cn/problem/P3956](https://www.luogu.com.cn/problem/P3956)
- 代码文件：`luogu/3956(搜索).cc`
- 分类标签：搜索
- 题目描述：洛谷 P3956，题面以原题链接为准；代码标签显示主要考点为「搜索」。
- 解法摘要：DFS/BFS 枚举状态，结合 visited、剪枝或启发式控制复杂度。

- <a href="#luogu-3958">洛谷 P3958</a>：亦可归入「搜索与回溯」，完整思路见主条目。
- <a href="#luogu-5507">洛谷 P5507</a>：亦可归入「搜索与回溯」，完整思路见主条目。
- <a href="#luogu-5908">洛谷 P5908</a>：亦可归入「搜索与回溯」，完整思路见主条目。
# 数据结构

## <a id="uva-136"></a>UVA 136

- 来源链接：[https://onlinejudge.org/external/1/136.pdf](https://onlinejudge.org/external/1/136.pdf)
- 代码文件：`UVA/136(堆).cc`
- 分类标签：堆
- 题目描述：UVA 136，题面以原题为准；代码主要围绕「堆」实现。
- 解法摘要：优先队列维护当前最小/最大候选。

## <a id="uva-540"></a>UVA 540

- 来源链接：[https://onlinejudge.org/external/5/540.pdf](https://onlinejudge.org/external/5/540.pdf)
- 代码文件：`UVA/540(队列).cc`
- 分类标签：队列
- 题目描述：UVA 540，题面以原题为准；代码主要围绕「队列」实现。
- 解法摘要：依据题意建模，核心实现标签为「队列」，重点处理输入规模和边界。

## <a id="uva-10474"></a>UVA 10474

- 来源链接：[https://onlinejudge.org/external/104/10474.pdf](https://onlinejudge.org/external/104/10474.pdf)
- 代码文件：`UVA/10474(STL).cc`
- 分类标签：STL
- 题目描述：UVA 10474，题面以原题为准；代码主要围绕「STL」实现。
- 解法摘要：依据题意建模，核心实现标签为「STL」，重点处理输入规模和边界。

## <a id="uva-10603"></a>UVA 10603

- 来源链接：[https://onlinejudge.org/external/106/10603.pdf](https://onlinejudge.org/external/106/10603.pdf)
- 代码文件：`UVA/10603(优先队列广搜).cc`
- 分类标签：优先队列广搜
- 题目描述：UVA 10603，题面以原题为准；代码主要围绕「优先队列广搜」实现。
- 解法摘要：依据题意建模，核心实现标签为「优先队列广搜」，重点处理输入规模和边界。

## <a id="uva-10815"></a>UVA 10815

- 来源链接：[https://onlinejudge.org/external/108/10815.pdf](https://onlinejudge.org/external/108/10815.pdf)
- 代码文件：`UVA/10815(STL).cc`
- 分类标签：STL
- 题目描述：UVA 10815，题面以原题为准；代码主要围绕「STL」实现。
- 解法摘要：依据题意建模，核心实现标签为「STL」，重点处理输入规模和边界。

## <a id="uva-11572"></a>UVA 11572

- 来源链接：[https://onlinejudge.org/external/115/11572.pdf](https://onlinejudge.org/external/115/11572.pdf)
- 代码文件：`UVA/11572(STL).cc`
- 分类标签：STL
- 题目描述：UVA 11572，题面以原题为准；代码主要围绕「STL」实现。
- 解法摘要：依据题意建模，核心实现标签为「STL」，重点处理输入规模和边界。

## <a id="leetcode-1"></a>LeetCode 1. 两数之和

- 代码文件：`leetcode/1(map).cc`
- 分类标签：map
- 题目描述：给定数组和目标值，找出和为目标值的两个数下标。
- 解法摘要：哈希表记录已见数值与下标，遍历时查找 target-x。
- 交叉分类：数组、双指针与贪心

## <a id="leetcode-155"></a>LeetCode 155. 最小栈

- 来源链接：[https://leetcode.cn/problems/min-stack/description](https://leetcode.cn/problems/min-stack/description)
- 代码文件：`leetcode/155.cc`
- 题目描述：设计支持常数时间取最小值的栈。
- 解法摘要：辅助栈同步记录当前最小值。

## <a id="luogu-1044"></a>洛谷 P1044

- 来源链接：[https://www.luogu.com.cn/problem/P1044](https://www.luogu.com.cn/problem/P1044)
- 代码文件：`luogu/1044(栈).cc`
- 分类标签：栈
- 题目描述：洛谷 P1044，题面以原题链接为准；代码标签显示主要考点为「栈」。
- 解法摘要：使用栈维护最近未匹配元素或单调结构。

## <a id="luogu-1165"></a>洛谷 P1165

- 来源链接：[https://www.luogu.com.cn/problem/P1165](https://www.luogu.com.cn/problem/P1165)
- 代码文件：`luogu/1165(数据结构).cc`
- 分类标签：数据结构
- 题目描述：洛谷 P1165，题面以原题链接为准；代码标签显示主要考点为「数据结构」。
- 解法摘要：依据题意建模，核心实现标签为「数据结构」，重点处理输入规模和边界。

## <a id="luogu-1449"></a>洛谷 P1449

- 来源链接：[https://www.luogu.com.cn/problem/P1449](https://www.luogu.com.cn/problem/P1449)
- 代码文件：`luogu/1449(栈).cc`
- 分类标签：栈
- 题目描述：洛谷 P1449，题面以原题链接为准；代码标签显示主要考点为「栈」。
- 解法摘要：使用栈维护最近未匹配元素或单调结构。

## <a id="luogu-1739"></a>洛谷 P1739

- 来源链接：[https://www.luogu.com.cn/problem/P1739](https://www.luogu.com.cn/problem/P1739)
- 代码文件：`luogu/1739(栈).cc`
- 分类标签：栈
- 题目描述：洛谷 P1739，题面以原题链接为准；代码标签显示主要考点为「栈」。
- 解法摘要：使用栈维护最近未匹配元素或单调结构。

- <a href="#luogu-1972">洛谷 P1972</a>：亦可归入「数据结构」，完整思路见主条目。
- <a href="#luogu-2023">洛谷 P2023</a>：亦可归入「数据结构」，完整思路见主条目。

## <a id="luogu-3353"></a>洛谷 P3353

- 来源链接：[https://www.luogu.com.cn/problem/P3353](https://www.luogu.com.cn/problem/P3353)
- 代码文件：`luogu/3353(数据结构).cc`
- 分类标签：数据结构
- 题目描述：洛谷 P3353，题面以原题链接为准；代码标签显示主要考点为「数据结构」。
- 解法摘要：依据题意建模，核心实现标签为「数据结构」，重点处理输入规模和边界。

- <a href="#luogu-3372">洛谷 P3372</a>：亦可归入「数据结构」，完整思路见主条目。
- <a href="#luogu-3373">洛谷 P3373</a>：亦可归入「数据结构」，完整思路见主条目。
- <a href="#luogu-3374">洛谷 P3374</a>：亦可归入「数据结构」，完整思路见主条目。

## <a id="luogu-3378"></a>洛谷 P3378

- 来源链接：[https://www.luogu.com.cn/problem/P3378](https://www.luogu.com.cn/problem/P3378)
- 代码文件：`luogu/3378(堆).cc`
- 分类标签：堆
- 题目描述：洛谷 P3378，题面以原题链接为准；代码标签显示主要考点为「堆」。
- 解法摘要：优先队列维护当前最小/最大候选。

# 数学与数论

## <a id="bzoj-3293"></a>BZOJ 3293

- 代码文件：`BZOJ/3293(math).cc`
- 分类标签：math
- 题目描述：BZOJ 3293，题面以原题为准；代码主要围绕「math」实现。
- 解法摘要：依据题意建模，核心实现标签为「math」，重点处理输入规模和边界。

## <a id="zoj-1037"></a>ZOJ 1037

- 代码文件：`ZOJ/1037(找规律).cc`
- 分类标签：找规律
- 题目描述：ZOJ 1037，题面以原题为准；代码主要围绕「找规律」实现。
- 解法摘要：依据题意建模，核心实现标签为「找规律」，重点处理输入规模和边界。

## <a id="acwing-4699"></a>acwing 4699

- 来源链接：[https://www.acwing.com/problem/content/description/4702/](https://www.acwing.com/problem/content/description/4702/)
- 代码文件：`acwing/4699(进制).cc`
- 分类标签：进制
- 题目描述：AcWing 4699，题面以原题链接为准；代码主要围绕「进制」实现。
- 解法摘要：依据题意建模，核心实现标签为「进制」，重点处理输入规模和边界。

## <a id="luogu-1029"></a>洛谷 P1029

- 来源链接：[https://www.luogu.com.cn/problem/P1029](https://www.luogu.com.cn/problem/P1029)
- 代码文件：`luogu/1029(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1029，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-1072"></a>洛谷 P1072

- 来源链接：[https://www.luogu.com.cn/problem/P1072](https://www.luogu.com.cn/problem/P1072)
- 代码文件：`luogu/1072(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1072，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-1088"></a>洛谷 P1088

- 来源链接：[https://www.luogu.com.cn/problem/P1088](https://www.luogu.com.cn/problem/P1088)
- 代码文件：`luogu/1088(数学).cc`
- 分类标签：数学
- 题目描述：洛谷 P1088，题面以原题链接为准；代码标签显示主要考点为「数学」。
- 解法摘要：推导公式或性质后直接计算。

- <a href="#luogu-1118">洛谷 P1118</a>：亦可归入「数学与数论」，完整思路见主条目。

## <a id="luogu-1147"></a>洛谷 P1147

- 来源链接：[https://www.luogu.com.cn/problem/P1147](https://www.luogu.com.cn/problem/P1147)
- 代码文件：`luogu/1147(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1147，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-1226"></a>洛谷 P1226

- 来源链接：[https://www.luogu.com.cn/problem/P1226](https://www.luogu.com.cn/problem/P1226)
- 代码文件：`luogu/1226(快速幂).cc`
- 分类标签：快速幂
- 题目描述：洛谷 P1226，题面以原题链接为准；代码标签显示主要考点为「快速幂」。
- 解法摘要：二进制快速幂降低幂运算复杂度。

## <a id="luogu-1338"></a>洛谷 P1338

- 来源链接：[https://www.luogu.com.cn/problem/P1338](https://www.luogu.com.cn/problem/P1338)
- 代码文件：`luogu/1338(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1338，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-1372"></a>洛谷 P1372

- 来源链接：[https://www.luogu.com.cn/problem/P1372](https://www.luogu.com.cn/problem/P1372)
- 代码文件：`luogu/1372(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1372，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

- <a href="#luogu-1464">洛谷 P1464</a>：亦可归入「数学与数论」，完整思路见主条目。

## <a id="luogu-1498"></a>洛谷 P1498

- 来源链接：[https://www.luogu.com.cn/problem/P1498](https://www.luogu.com.cn/problem/P1498)
- 代码文件：`luogu/1498(数学).cc`
- 分类标签：数学
- 题目描述：洛谷 P1498，题面以原题链接为准；代码标签显示主要考点为「数学」。
- 解法摘要：推导公式或性质后直接计算。

## <a id="luogu-1516"></a>洛谷 P1516

- 来源链接：[https://www.luogu.com.cn/problem/P1516](https://www.luogu.com.cn/problem/P1516)
- 代码文件：`luogu/1516(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1516，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-1601"></a>洛谷 P1601

- 来源链接：[https://www.luogu.com.cn/problem/P1601](https://www.luogu.com.cn/problem/P1601)
- 代码文件：`luogu/1601(高精).cc`
- 分类标签：高精
- 题目描述：洛谷 P1601，题面以原题链接为准；代码标签显示主要考点为「高精」。
- 解法摘要：用数组/字符串模拟大整数运算。

## <a id="luogu-1720"></a>洛谷 P1720

- 来源链接：[https://www.luogu.com.cn/problem/P1720](https://www.luogu.com.cn/problem/P1720)
- 代码文件：`luogu/1720(数学).cc`
- 分类标签：数学
- 题目描述：洛谷 P1720，题面以原题链接为准；代码标签显示主要考点为「数学」。
- 解法摘要：推导公式或性质后直接计算。

## <a id="luogu-1865"></a>洛谷 P1865

- 来源链接：[https://www.luogu.com.cn/problem/P1865](https://www.luogu.com.cn/problem/P1865)
- 代码文件：`luogu/1865(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P1865，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-2142"></a>洛谷 P2142

- 来源链接：[https://www.luogu.com.cn/problem/P2142](https://www.luogu.com.cn/problem/P2142)
- 代码文件：`luogu/2142(高精).cc`
- 分类标签：高精
- 题目描述：洛谷 P2142，题面以原题链接为准；代码标签显示主要考点为「高精」。
- 解法摘要：用数组/字符串模拟大整数运算。

## <a id="luogu-2158"></a>洛谷 P2158

- 来源链接：[https://www.luogu.com.cn/problem/P2158](https://www.luogu.com.cn/problem/P2158)
- 代码文件：`luogu/2158(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P2158，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-2197"></a>洛谷 P2197

- 来源链接：[https://www.luogu.com.cn/problem/P2197](https://www.luogu.com.cn/problem/P2197)
- 代码文件：`luogu/2197(NIM博弈).cc`
- 分类标签：NIM博弈
- 题目描述：洛谷 P2197，题面以原题链接为准；代码标签显示主要考点为「NIM博弈」。
- 解法摘要：分析必胜/必败态或套用 Nim 异或结论。
- 交叉分类：博弈论

## <a id="luogu-3131"></a>洛谷 P3131

- 来源链接：[https://www.luogu.com.cn/problem/P3131](https://www.luogu.com.cn/problem/P3131)
- 代码文件：`luogu/3131(同余系划分).cc`
- 分类标签：同余系划分
- 题目描述：洛谷 P3131，题面以原题链接为准；代码标签显示主要考点为「同余系划分」。
- 解法摘要：依据题意建模，核心实现标签为「同余系划分」，重点处理输入规模和边界。

## <a id="luogu-3383"></a>洛谷 P3383

- 来源链接：[https://www.luogu.com.cn/problem/P3383](https://www.luogu.com.cn/problem/P3383)
- 代码文件：`luogu/3383(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P3383，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-3951"></a>洛谷 P3951

- 来源链接：[https://www.luogu.com.cn/problem/P3951](https://www.luogu.com.cn/problem/P3951)
- 代码文件：`luogu/3951(数论).cc`
- 分类标签：数论
- 题目描述：洛谷 P3951，题面以原题链接为准；代码标签显示主要考点为「数论」。
- 解法摘要：利用整除、同余、gcd 或筛法等数论性质化简。

## <a id="luogu-4525"></a>洛谷 P4525

- 来源链接：[https://www.luogu.com.cn/problem/P4525](https://www.luogu.com.cn/problem/P4525)
- 代码文件：`luogu/4525(辛普森).cpp`
- 分类标签：辛普森
- 题目描述：洛谷 P4525，题面以原题链接为准；代码标签显示主要考点为「辛普森」。
- 解法摘要：依据题意建模，核心实现标签为「辛普森」，重点处理输入规模和边界。

## <a id="luogu-4702"></a>洛谷 P4702

- 来源链接：[https://www.luogu.com.cn/problem/P4702](https://www.luogu.com.cn/problem/P4702)
- 代码文件：`luogu/4702(博弈).cc`
- 分类标签：博弈
- 题目描述：洛谷 P4702，题面以原题链接为准；代码标签显示主要考点为「博弈」。
- 解法摘要：分析必胜/必败态或套用 Nim 异或结论。
- 交叉分类：博弈论

## <a id="luogu-5020"></a>洛谷 P5020

- 来源链接：[https://www.luogu.com.cn/problem/P5020](https://www.luogu.com.cn/problem/P5020)
- 代码文件：`luogu/5020(数学).cc`
- 分类标签：数学
- 题目描述：洛谷 P5020，题面以原题链接为准；代码标签显示主要考点为「数学」。
- 解法摘要：推导公式或性质后直接计算。

# 字符串

## <a id="leetcode-3"></a>LeetCode 3. 无重复字符的最长子串

- 代码文件：`leetcode/3(滑动窗口).cc`
- 分类标签：滑动窗口
- 题目描述：求字符串中不含重复字符的最长子串长度。
- 解法摘要：滑动窗口配合哈希集合/位置表，右端扩张、左端排除重复。
- 交叉分类：数组、双指针与贪心

- <a href="#leetcode-5">LeetCode 5. 最长回文子串</a>：亦可归入「字符串」，完整思路见主条目。

## <a id="leetcode-6"></a>LeetCode 6. Z 字形变换

- 来源链接：[https://leetcode.cn/problems/zigzag-conversion/](https://leetcode.cn/problems/zigzag-conversion/)
- 代码文件：`leetcode/6(瞪眼观察).cc`
- 分类标签：瞪眼观察
- 题目描述：按 Z 字形行序重排字符串并输出。
- 解法摘要：观察行号往返变化，将字符追加到对应行后拼接。

## <a id="leetcode-14"></a>LeetCode 14. 最长公共前缀

- 来源链接：[https://leetcode.cn/problems/longest-common-prefix/](https://leetcode.cn/problems/longest-common-prefix/)
- 代码文件：`leetcode/14.cc`
- 题目描述：求字符串数组的最长公共前缀。
- 解法摘要：以首串为基准逐位比较或不断缩短候选前缀。
- 交叉分类：数组、双指针与贪心

## <a id="leetcode-17"></a>LeetCode 17. 电话号码的字母组合

- 来源链接：[https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)
- 代码文件：`leetcode/17.cc`
- 题目描述：给定数字串，返回电话键盘可能的字母组合。
- 解法摘要：回溯逐位枚举映射字符，走到末尾收集组合。

## <a id="leetcode-20"></a>LeetCode 20. 有效的括号

- 来源链接：[https://leetcode.cn/problems/valid-parentheses/description/](https://leetcode.cn/problems/valid-parentheses/description/)
- 代码文件：`leetcode/20.cc`
- 题目描述：判断括号串是否按类型正确闭合。
- 解法摘要：栈保存待匹配左括号，遇到右括号检查栈顶。

## <a id="leetcode-49"></a>LeetCode 49. 字母异位词分组

- 来源链接：[https://leetcode.cn/problems/group-anagrams/description/](https://leetcode.cn/problems/group-anagrams/description/)
- 代码文件：`leetcode/49.cc`
- 题目描述：把互为异位词的字符串分到同组。
- 解法摘要：排序后的字符串或字符计数作为哈希键。

## <a id="leetcode-72"></a>LeetCode 72. 编辑距离

- 代码文件：`leetcode/72.cc`
- 题目描述：求两个字符串互相转换的最少插入、删除、替换次数。
- 解法摘要：二维 DP，dp[i][j] 表示前缀转换代价。

## <a id="leetcode-394"></a>LeetCode 394. 字符串解码

- 来源链接：[https://leetcode.cn/problems/decode-string/description/](https://leetcode.cn/problems/decode-string/description/)
- 代码文件：`leetcode/394.cc`
- 题目描述：解码形如 k[encoded] 的嵌套字符串。
- 解法摘要：栈保存重复次数和外层字符串，遇右括号展开。

## <a id="leetcode-438"></a>LeetCode 438. 找到字符串中所有字母异位词

- 来源链接：[https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/](https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/)
- 代码文件：`leetcode/438.cc`
- 题目描述：找 s 中所有 p 的异位词起点。
- 解法摘要：固定长度滑动窗口维护字符计数差。

## <a id="luogu-1071"></a>洛谷 P1071

- 来源链接：[https://www.luogu.com.cn/problem/P1071](https://www.luogu.com.cn/problem/P1071)
- 代码文件：`luogu/1071(字符串).cc`
- 分类标签：字符串
- 题目描述：洛谷 P1071，题面以原题链接为准；代码标签显示主要考点为「字符串」。
- 解法摘要：按字符扫描、映射或模式规则处理字符串。

## <a id="luogu-1603"></a>洛谷 P1603

- 来源链接：[https://www.luogu.com.cn/problem/P1603](https://www.luogu.com.cn/problem/P1603)
- 代码文件：`luogu/1603(字符串).cc`
- 分类标签：字符串
- 题目描述：洛谷 P1603，题面以原题链接为准；代码标签显示主要考点为「字符串」。
- 解法摘要：按字符扫描、映射或模式规则处理字符串。

## <a id="luogu-1914"></a>洛谷 P1914

- 来源链接：[https://www.luogu.com.cn/problem/P1914](https://www.luogu.com.cn/problem/P1914)
- 代码文件：`luogu/1914(字符串).cc`
- 分类标签：字符串
- 题目描述：洛谷 P1914，题面以原题链接为准；代码标签显示主要考点为「字符串」。
- 解法摘要：按字符扫描、映射或模式规则处理字符串。

# 数组、双指针与贪心

## <a id="uva-272"></a>UVA 272

- 来源链接：[https://onlinejudge.org/external/2/272.pdf](https://onlinejudge.org/external/2/272.pdf)
- 代码文件：`UVA/272(水题).cc`
- 分类标签：水题
- 题目描述：UVA 272，题面以原题为准；代码主要围绕「水题」实现。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="uva-489"></a>UVA 489

- 来源链接：[https://onlinejudge.org/external/4/489.pdf](https://onlinejudge.org/external/4/489.pdf)
- 代码文件：`UVA/489(乱搞).cc`
- 分类标签：乱搞
- 题目描述：UVA 489，题面以原题为准；代码主要围绕「乱搞」实现。
- 解法摘要：依据题意建模，核心实现标签为「乱搞」，重点处理输入规模和边界。

## <a id="codeforces-484a"></a>Codeforces 484A

- 代码文件：`codeforces/484A(greedy).cc`
- 分类标签：greedy
- 题目描述：Codeforces 484A，题面以原题为准；代码主要围绕「greedy」实现。
- 解法摘要：依据题意建模，核心实现标签为「greedy」，重点处理输入规模和边界。

- <a href="#leetcode-1">LeetCode 1. 两数之和</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。
- <a href="#leetcode-2">LeetCode 2. 两数相加</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。
- <a href="#leetcode-3">LeetCode 3. 无重复字符的最长子串</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="leetcode-7"></a>LeetCode 7. 整数反转

- 来源链接：[https://leetcode.cn/problems/reverse-integer/description/](https://leetcode.cn/problems/reverse-integer/description/)
- 代码文件：`leetcode/7(模拟).cc`
- 分类标签：模拟
- 题目描述：反转 32 位有符号整数，溢出返回 0。
- 解法摘要：逐位取模构造答案，每次更新前检查边界。

- <a href="#leetcode-14">LeetCode 14. 最长公共前缀</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="leetcode-15"></a>LeetCode 15. 三数之和

- 来源链接：[https://leetcode.cn/problems/3sum/description/](https://leetcode.cn/problems/3sum/description/)
- 代码文件：`leetcode/15(double_pointer).cc`、`leetcode/15_tle.cc`
- 分类标签：double_pointer
- 题目描述：找出数组中所有和为 0 的不重复三元组。
- 解法摘要：排序后枚举第一个数，内层双指针并跳过重复值。

## <a id="leetcode-34"></a>LeetCode 34. 在排序数组中查找元素的第一个和最后一个位置

- 来源链接：[https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/)
- 代码文件：`leetcode/34.cc`
- 题目描述：在有序数组中找目标值区间。
- 解法摘要：两次二分分别找 lower_bound 和 upper_bound-1。

- <a href="#leetcode-35">LeetCode 35. 搜索插入位置</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="leetcode-41"></a>LeetCode 41. 缺失的第一个正数

- 来源链接：[https://leetcode.cn/problems/first-missing-positive/description/](https://leetcode.cn/problems/first-missing-positive/description/)
- 代码文件：`leetcode/41.cc`
- 题目描述：求未排序数组中缺失的最小正整数。
- 解法摘要：把值 x 原地交换到下标 x-1，最后扫描第一个不匹配位置。

## <a id="leetcode-46"></a>LeetCode 46. 全排列

- 来源链接：[https://leetcode.cn/problems/permutations/description/](https://leetcode.cn/problems/permutations/description/)
- 代码文件：`leetcode/46.cc`
- 题目描述：返回数组的所有排列。
- 解法摘要：回溯使用 visited 或原地交换生成排列。

## <a id="leetcode-48"></a>LeetCode 48. 旋转图像

- 来源链接：[https://leetcode.cn/problems/rotate-image/description/](https://leetcode.cn/problems/rotate-image/description/)
- 代码文件：`leetcode/48.cc`
- 题目描述：将 n*n 矩阵顺时针旋转 90 度。
- 解法摘要：先转置再按行翻转，或按层四向交换。

## <a id="leetcode-53"></a>LeetCode 53. 最大子数组和

- 来源链接：[https://leetcode.cn/problems/maximum-subarray/description/](https://leetcode.cn/problems/maximum-subarray/description/)
- 代码文件：`leetcode/53.cc`
- 题目描述：求连续子数组的最大和。
- 解法摘要：Kadane 动态规划，当前和为负则从当前位置重启。

## <a id="leetcode-78"></a>LeetCode 78. 子集

- 来源链接：[https://leetcode.cn/problems/subsets/description/](https://leetcode.cn/problems/subsets/description/)
- 代码文件：`leetcode/78.cc`
- 题目描述：返回数组所有子集。
- 解法摘要：回溯选择/不选择，或位掩码枚举。

- <a href="#leetcode-108">LeetCode 108. 将有序数组转换为二叉搜索树</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="leetcode-128"></a>LeetCode 128. 最长连续序列

- 来源链接：[https://leetcode.cn/problems/longest-consecutive-sequence/description/](https://leetcode.cn/problems/longest-consecutive-sequence/description/)
- 代码文件：`leetcode/128.cc`
- 题目描述：求数组中最长连续整数序列长度。
- 解法摘要：哈希集合只从序列起点向后扩展，整体线性。

## <a id="leetcode-136"></a>LeetCode 136. 只出现一次的数字

- 来源链接：[https://leetcode.cn/problems/single-number/description/](https://leetcode.cn/problems/single-number/description/)
- 代码文件：`leetcode/136.cc`
- 题目描述：数组中除一个数外都出现两次，找单独的数。
- 解法摘要：利用异或抵消成对数字。

## <a id="leetcode-189"></a>LeetCode 189. 轮转数组

- 来源链接：[https://leetcode.cn/problems/rotate-array/description/](https://leetcode.cn/problems/rotate-array/description/)
- 代码文件：`leetcode/189.cc`
- 题目描述：将数组向右轮转 k 位。
- 解法摘要：三次翻转：全体、前 k、后 n-k。

## <a id="leetcode-209"></a>LeetCode 209. 长度最小的子数组

- 来源链接：[https://leetcode.cn/problems/minimum-size-subarray-sum/description/](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)
- 代码文件：`leetcode/209.cc`
- 题目描述：求和至少为 target 的最短连续子数组长度。
- 解法摘要：正数数组滑动窗口，和达标后收缩左端。

## <a id="leetcode-215"></a>LeetCode 215. 数组中的第 K 个最大元素

- 来源链接：[https://leetcode.cn/problems/kth-largest-element-in-an-array/description/](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/)
- 代码文件：`leetcode/215.cc`
- 题目描述：找数组第 k 大元素。
- 解法摘要：维护大小为 k 的小根堆，或快速选择。

## <a id="leetcode-238"></a>LeetCode 238. 除自身以外数组的乘积

- 来源链接：[https://leetcode.cn/problems/product-of-array-except-self/description/](https://leetcode.cn/problems/product-of-array-except-self/description/)
- 代码文件：`leetcode/238.cc`
- 题目描述：返回除自身外所有元素乘积，不能用除法。
- 解法摘要：前缀积乘后缀积，两趟扫描。

## <a id="leetcode-239"></a>LeetCode 239. 滑动窗口最大值

- 来源链接：[https://leetcode.cn/problems/sliding-window-maximum/description/](https://leetcode.cn/problems/sliding-window-maximum/description/)
- 代码文件：`leetcode/239-n.cc`、`leetcode/239-nlogk.cc`
- 题目描述：求每个长度为 k 的窗口最大值。
- 解法摘要：单调队列维护下标，队首始终是窗口最大值；另有堆版本。

## <a id="leetcode-283"></a>LeetCode 283. 移动零

- 来源链接：[https://leetcode.cn/problems/move-zeroes/description/](https://leetcode.cn/problems/move-zeroes/description/)
- 代码文件：`leetcode/283.cc`
- 题目描述：把所有 0 移到数组末尾并保持非零相对顺序。
- 解法摘要：双指针压缩非零元素，再补零。

## <a id="leetcode-560"></a>LeetCode 560. 和为 K 的子数组

- 来源链接：[https://leetcode.cn/problems/subarray-sum-equals-k/description/](https://leetcode.cn/problems/subarray-sum-equals-k/description/)
- 代码文件：`leetcode/560.cc`
- 题目描述：统计连续子数组和等于 k 的数量。
- 解法摘要：前缀和 + 哈希计数，累加 prefix-k 出现次数。

## <a id="luogu-1007"></a>洛谷 P1007

- 来源链接：[https://www.luogu.com.cn/problem/P1007](https://www.luogu.com.cn/problem/P1007)
- 代码文件：`luogu/1007(脑洞).cc`
- 分类标签：脑洞
- 题目描述：洛谷 P1007，题面以原题链接为准；代码标签显示主要考点为「脑洞」。
- 解法摘要：依据题意建模，核心实现标签为「脑洞」，重点处理输入规模和边界。

## <a id="luogu-1031"></a>洛谷 P1031

- 来源链接：[https://www.luogu.com.cn/problem/P1031](https://www.luogu.com.cn/problem/P1031)
- 代码文件：`luogu/1031(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P1031，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-1051"></a>洛谷 P1051

- 来源链接：[https://www.luogu.com.cn/problem/P1051](https://www.luogu.com.cn/problem/P1051)
- 代码文件：`luogu/1051(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1051，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1056"></a>洛谷 P1056

- 来源链接：[https://www.luogu.com.cn/problem/P1056](https://www.luogu.com.cn/problem/P1056)
- 代码文件：`luogu/1056(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P1056，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-1067"></a>洛谷 P1067

- 来源链接：[https://www.luogu.com.cn/problem/P1067](https://www.luogu.com.cn/problem/P1067)
- 代码文件：`luogu/1067(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P1067，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-1086"></a>洛谷 P1086

- 来源链接：[https://www.luogu.com.cn/problem/P1086](https://www.luogu.com.cn/problem/P1086)
- 代码文件：`luogu/1086(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P1086，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-1090"></a>洛谷 P1090

- 来源链接：[https://www.luogu.com.cn/problem/P1090](https://www.luogu.com.cn/problem/P1090)
- 代码文件：`luogu/1090(乱搞).cc`
- 分类标签：乱搞
- 题目描述：洛谷 P1090，题面以原题链接为准；代码标签显示主要考点为「乱搞」。
- 解法摘要：依据题意建模，核心实现标签为「乱搞」，重点处理输入规模和边界。

## <a id="luogu-1093"></a>洛谷 P1093

- 来源链接：[https://www.luogu.com.cn/problem/P1093](https://www.luogu.com.cn/problem/P1093)
- 代码文件：`luogu/1093(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1093，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1106"></a>洛谷 P1106

- 来源链接：[https://www.luogu.com.cn/problem/P1106](https://www.luogu.com.cn/problem/P1106)
- 代码文件：`luogu/1106(乱搞).cc`
- 分类标签：乱搞
- 题目描述：洛谷 P1106，题面以原题链接为准；代码标签显示主要考点为「乱搞」。
- 解法摘要：依据题意建模，核心实现标签为「乱搞」，重点处理输入规模和边界。

## <a id="luogu-1115"></a>洛谷 P1115

- 来源链接：[https://www.luogu.com.cn/problem/P1115](https://www.luogu.com.cn/problem/P1115)
- 代码文件：`luogu/1115(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P1115，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-1150"></a>洛谷 P1150

- 来源链接：[https://www.luogu.com.cn/problem/P1150](https://www.luogu.com.cn/problem/P1150)
- 代码文件：`luogu/1150(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P1150，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-1187"></a>洛谷 P1187

- 来源链接：[https://www.luogu.com.cn/problem/P1187](https://www.luogu.com.cn/problem/P1187)
- 代码文件：`luogu/1187(乱搞).cc`
- 分类标签：乱搞
- 题目描述：洛谷 P1187，题面以原题链接为准；代码标签显示主要考点为「乱搞」。
- 解法摘要：依据题意建模，核心实现标签为「乱搞」，重点处理输入规模和边界。

## <a id="luogu-1223"></a>洛谷 P1223

- 来源链接：[https://www.luogu.com.cn/problem/P1223](https://www.luogu.com.cn/problem/P1223)
- 代码文件：`luogu/1223(排序不等式).cc`
- 分类标签：排序不等式
- 题目描述：洛谷 P1223，题面以原题链接为准；代码标签显示主要考点为「排序不等式」。
- 解法摘要：排序后利用顺序性质扫描或贪心。

## <a id="luogu-1387"></a>洛谷 P1387

- 来源链接：[https://www.luogu.com.cn/problem/P1387](https://www.luogu.com.cn/problem/P1387)
- 代码文件：`luogu/1387(二维前缀和).cc`
- 分类标签：二维前缀和
- 题目描述：洛谷 P1387，题面以原题链接为准；代码标签显示主要考点为「二维前缀和」。
- 解法摘要：依据题意建模，核心实现标签为「二维前缀和」，重点处理输入规模和边界。

## <a id="luogu-1420"></a>洛谷 P1420

- 来源链接：[https://www.luogu.com.cn/problem/P1420](https://www.luogu.com.cn/problem/P1420)
- 代码文件：`luogu/1420(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1420，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1426"></a>洛谷 P1426

- 来源链接：[https://www.luogu.com.cn/problem/P1426](https://www.luogu.com.cn/problem/P1426)
- 代码文件：`luogu/1426(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1426，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1434"></a>洛谷 P1434

- 来源链接：[https://www.luogu.com.cn/problem/P1434](https://www.luogu.com.cn/problem/P1434)
- 代码文件：`luogu/1434(排序乱搞).cc`
- 分类标签：排序乱搞
- 题目描述：洛谷 P1434，题面以原题链接为准；代码标签显示主要考点为「排序乱搞」。
- 解法摘要：排序后利用顺序性质扫描或贪心。

## <a id="luogu-1462"></a>洛谷 P1462

- 来源链接：[https://www.luogu.com.cn/problem/P1462](https://www.luogu.com.cn/problem/P1462)
- 代码文件：`luogu/1462(二分).cc`
- 分类标签：二分
- 题目描述：洛谷 P1462，题面以原题链接为准；代码标签显示主要考点为「二分」。
- 解法摘要：二分答案或位置，用判定函数缩小范围。

## <a id="luogu-1478"></a>洛谷 P1478

- 来源链接：[https://www.luogu.com.cn/problem/P1478](https://www.luogu.com.cn/problem/P1478)
- 代码文件：`luogu/1478(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1478，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1525"></a>洛谷 P1525

- 来源链接：[https://www.luogu.com.cn/problem/P1525](https://www.luogu.com.cn/problem/P1525)
- 代码文件：`luogu/1525(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P1525，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-1532"></a>洛谷 P1532

- 来源链接：[https://www.luogu.com.cn/problem/P1532](https://www.luogu.com.cn/problem/P1532)
- 代码文件：`luogu/1532(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P1532，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-1553"></a>洛谷 P1553

- 来源链接：[https://www.luogu.com.cn/problem/P1553](https://www.luogu.com.cn/problem/P1553)
- 代码文件：`luogu/1553(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P1553，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-1577"></a>洛谷 P1577

- 来源链接：[https://www.luogu.com.cn/problem/P1577](https://www.luogu.com.cn/problem/P1577)
- 代码文件：`luogu/1577(二分).cc`
- 分类标签：二分
- 题目描述：洛谷 P1577，题面以原题链接为准；代码标签显示主要考点为「二分」。
- 解法摘要：二分答案或位置，用判定函数缩小范围。

## <a id="luogu-1583"></a>洛谷 P1583

- 来源链接：[https://www.luogu.com.cn/problem/P1583](https://www.luogu.com.cn/problem/P1583)
- 代码文件：`luogu/1583(水题).cc`
- 分类标签：水题
- 题目描述：洛谷 P1583，题面以原题链接为准；代码标签显示主要考点为「水题」。
- 解法摘要：依据题意建模，核心实现标签为「水题」，重点处理输入规模和边界。

## <a id="luogu-1781"></a>洛谷 P1781

- 来源链接：[https://www.luogu.com.cn/problem/P1781](https://www.luogu.com.cn/problem/P1781)
- 代码文件：`luogu/1781(排序).cc`
- 分类标签：排序
- 题目描述：洛谷 P1781，题面以原题链接为准；代码标签显示主要考点为「排序」。
- 解法摘要：排序后利用顺序性质扫描或贪心。

## <a id="luogu-1803"></a>洛谷 P1803

- 来源链接：[https://www.luogu.com.cn/problem/P1803](https://www.luogu.com.cn/problem/P1803)
- 代码文件：`luogu/1803(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P1803，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-1908"></a>洛谷 P1908

- 来源链接：[https://www.luogu.com.cn/problem/P1908](https://www.luogu.com.cn/problem/P1908)
- 代码文件：`luogu/1908(归并排序).cc`
- 分类标签：归并排序
- 题目描述：洛谷 P1908，题面以原题链接为准；代码标签显示主要考点为「归并排序」。
- 解法摘要：排序后利用顺序性质扫描或贪心。

- <a href="#luogu-1972">洛谷 P1972</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="luogu-2678"></a>洛谷 P2678

- 来源链接：[https://www.luogu.com.cn/problem/P2678](https://www.luogu.com.cn/problem/P2678)
- 代码文件：`luogu/2678(二分).cc`
- 分类标签：二分
- 题目描述：洛谷 P2678，题面以原题链接为准；代码标签显示主要考点为「二分」。
- 解法摘要：二分答案或位置，用判定函数缩小范围。

- <a href="#luogu-2680">洛谷 P2680</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。

## <a id="luogu-3918"></a>洛谷 P3918

- 来源链接：[https://www.luogu.com.cn/problem/P3918](https://www.luogu.com.cn/problem/P3918)
- 代码文件：`luogu/3918(贪心).cc`
- 分类标签：贪心
- 题目描述：洛谷 P3918，题面以原题链接为准；代码标签显示主要考点为「贪心」。
- 解法摘要：抓住局部最优策略，排序或扫描维护当前最优。

## <a id="luogu-3926"></a>洛谷 P3926

- 来源链接：[https://www.luogu.com.cn/problem/P3926](https://www.luogu.com.cn/problem/P3926)
- 代码文件：`luogu/3926(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P3926，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

## <a id="luogu-3952"></a>洛谷 P3952

- 来源链接：[https://www.luogu.com.cn/problem/P3952](https://www.luogu.com.cn/problem/P3952)
- 代码文件：`luogu/3952(模拟).cc`
- 分类标签：模拟
- 题目描述：洛谷 P3952，题面以原题链接为准；代码标签显示主要考点为「模拟」。
- 解法摘要：按题意维护变量和流程，注意边界条件。

- <a href="#luogu-4995">洛谷 P4995</a>：亦可归入「数组、双指针与贪心」，完整思路见主条目。
# 树与链表

## <a id="poj-1985"></a>POJ 1985

- 代码文件：`POJ/1985(tree).cc`
- 分类标签：tree
- 题目描述：POJ 1985，题面以原题为准；代码主要围绕「tree」实现。
- 解法摘要：依据题意建模，核心实现标签为「tree」，重点处理输入规模和边界。

## <a id="uva-679"></a>UVA 679

- 来源链接：[https://onlinejudge.org/external/6/679.pdf](https://onlinejudge.org/external/6/679.pdf)
- 代码文件：`UVA/679(树).cc`
- 分类标签：树
- 题目描述：UVA 679，题面以原题为准；代码主要围绕「树」实现。
- 解法摘要：依据题意建模，核心实现标签为「树」，重点处理输入规模和边界。

## <a id="codeforces-519e"></a>Codeforces 519E

- 代码文件：`codeforces/519E(LCA).cc`
- 分类标签：LCA
- 题目描述：Codeforces 519E，题面以原题为准；代码主要围绕「LCA」实现。
- 解法摘要：预处理倍增祖先与深度，用 LCA 回答树上距离或路径问题。
- 交叉分类：图论

## <a id="leetcode-2"></a>LeetCode 2. 两数相加

- 代码文件：`leetcode/2(模拟).cc`
- 分类标签：模拟
- 题目描述：用两个逆序链表表示非负整数，返回相加后的链表。
- 解法摘要：同步遍历两条链表并维护进位，按位创建结果节点。
- 交叉分类：数组、双指针与贪心

## <a id="leetcode-21"></a>LeetCode 21. 合并两个有序链表

- 来源链接：[https://leetcode.cn/problems/merge-two-sorted-lists/description/](https://leetcode.cn/problems/merge-two-sorted-lists/description/)
- 代码文件：`leetcode/21.cc`
- 题目描述：合并两条升序链表。
- 解法摘要：哑节点串接较小节点，最后接上剩余链表。

## <a id="leetcode-25"></a>LeetCode 25. K 个一组翻转链表

- 来源链接：[https://leetcode.cn/problems/reverse-nodes-in-k-group/description/](https://leetcode.cn/problems/reverse-nodes-in-k-group/description/)
- 代码文件：`leetcode/25.cc`
- 题目描述：每 k 个节点一组翻转链表，不足 k 个保持原样。
- 解法摘要：先探测一组长度，再局部反转并接回前后链。

## <a id="leetcode-92"></a>LeetCode 92. 反转链表 II

- 来源链接：[https://leetcode.cn/problems/reverse-linked-list-ii/description/](https://leetcode.cn/problems/reverse-linked-list-ii/description/)
- 代码文件：`leetcode/92(反转链表).cc`
- 分类标签：反转链表
- 题目描述：反转链表中指定区间。
- 解法摘要：用哑节点定位区间前驱，头插法或局部反转区间节点。

## <a id="leetcode-94"></a>LeetCode 94. 二叉树中序遍历

- 来源链接：[https://leetcode.cn/problems/binary-tree-inorder-traversal/description/](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)
- 代码文件：`leetcode/94.cc`
- 题目描述：返回二叉树的中序遍历序列。
- 解法摘要：递归左根右，或显式栈模拟。

## <a id="leetcode-98"></a>LeetCode 98. 验证二叉搜索树

- 来源链接：[https://leetcode.cn/problems/validate-binary-search-tree/description/](https://leetcode.cn/problems/validate-binary-search-tree/description/)
- 代码文件：`leetcode/98.cc`
- 题目描述：判断二叉树是否满足 BST 性质。
- 解法摘要：递归传上下界，或中序遍历检查严格递增。
- 交叉分类：搜索与回溯

## <a id="leetcode-101"></a>LeetCode 101. 对称二叉树

- 来源链接：[https://leetcode.cn/problems/symmetric-tree/description/](https://leetcode.cn/problems/symmetric-tree/description/)
- 代码文件：`leetcode/101.cc`
- 题目描述：判断二叉树是否镜像对称。
- 解法摘要：递归比较左右子树外侧与内侧节点。

## <a id="leetcode-102"></a>LeetCode 102. 二叉树的层序遍历

- 来源链接：[https://leetcode.cn/problems/binary-tree-level-order-traversal/description/](https://leetcode.cn/problems/binary-tree-level-order-traversal/description/)
- 代码文件：`leetcode/102.cc`
- 题目描述：按层返回二叉树节点值。
- 解法摘要：队列 BFS，每轮处理当前层大小。

## <a id="leetcode-104"></a>LeetCode 104. 二叉树的最大深度

- 来源链接：[https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)
- 代码文件：`leetcode/104.cc`
- 题目描述：求二叉树最大深度。
- 解法摘要：递归返回左右子树深度最大值加一。

## <a id="leetcode-105"></a>LeetCode 105. 从前序与中序遍历序列构造二叉树

- 来源链接：[https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
- 代码文件：`leetcode/105.cc`
- 题目描述：根据 preorder 和 inorder 重建二叉树。
- 解法摘要：前序首元素为根，哈希定位中序位置后递归划分左右子树。

## <a id="leetcode-108"></a>LeetCode 108. 将有序数组转换为二叉搜索树

- 来源链接：[https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/)
- 代码文件：`leetcode/108.cc`
- 题目描述：把升序数组转换为高度平衡 BST。
- 解法摘要：递归选择中点为根，左右区间分别建树。
- 交叉分类：搜索与回溯、数组、双指针与贪心

## <a id="leetcode-141"></a>LeetCode 141. 环形链表

- 来源链接：[https://leetcode.cn/problems/linked-list-cycle/description/](https://leetcode.cn/problems/linked-list-cycle/description/)
- 代码文件：`leetcode/141.cc`
- 题目描述：判断链表是否有环。
- 解法摘要：快慢指针，相遇则存在环。

## <a id="leetcode-142"></a>LeetCode 142. 环形链表 II

- 来源链接：[https://leetcode.cn/problems/linked-list-cycle-ii/description/](https://leetcode.cn/problems/linked-list-cycle-ii/description/)
- 代码文件：`leetcode/142.cc`
- 题目描述：返回链表入环节点。
- 解法摘要：快慢指针相遇后，一个指针回头同步走到入口。

## <a id="leetcode-160"></a>LeetCode 160. 相交链表

- 来源链接：[https://leetcode.cn/problems/intersection-of-two-linked-lists/description/](https://leetcode.cn/problems/intersection-of-two-linked-lists/description/)
- 代码文件：`leetcode/160.cc`
- 题目描述：找两条单链表的相交起点。
- 解法摘要：双指针分别走完后切换到另一链表，路程对齐后相遇。

## <a id="leetcode-199"></a>LeetCode 199. 二叉树的右视图

- 来源链接：[https://leetcode.cn/problems/binary-tree-right-side-view/description/](https://leetcode.cn/problems/binary-tree-right-side-view/description/)
- 代码文件：`leetcode/199.cc`
- 题目描述：返回每层最右侧节点。
- 解法摘要：BFS 取每层最后一个，或 DFS 先右后左记录首访深度。
- 交叉分类：图论

## <a id="leetcode-206"></a>LeetCode 206. 反转链表

- 来源链接：[https://leetcode.cn/problems/reverse-linked-list/](https://leetcode.cn/problems/reverse-linked-list/)
- 代码文件：`leetcode/206(反转链表).cc`
- 分类标签：反转链表
- 题目描述：反转单链表。
- 解法摘要：迭代维护 prev/cur，不断改 next 指针。

## <a id="leetcode-226"></a>LeetCode 226. 翻转二叉树

- 来源链接：[https://leetcode.cn/problems/invert-binary-tree/description/](https://leetcode.cn/problems/invert-binary-tree/description/)
- 代码文件：`leetcode/226.cc`
- 题目描述：交换二叉树每个节点的左右子树。
- 解法摘要：递归或 BFS 对每个节点交换左右孩子。

## <a id="leetcode-230"></a>LeetCode 230. 二叉搜索树中第 K 小的元素

- 来源链接：[https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/)
- 代码文件：`leetcode/230.cc`
- 题目描述：在 BST 中找第 k 小。
- 解法摘要：中序遍历得到升序，第 k 次访问即答案。
- 交叉分类：搜索与回溯

## <a id="leetcode-234"></a>LeetCode 234. 回文链表

- 来源链接：[https://leetcode.cn/problems/palindrome-linked-list/description/](https://leetcode.cn/problems/palindrome-linked-list/description/)
- 代码文件：`leetcode/234.cc`
- 题目描述：判断链表节点值是否回文。
- 解法摘要：快慢指针找中点，反转后半段后逐项比较。

## <a id="leetcode-437"></a>LeetCode 437. 路径总和 III

- 来源链接：[https://leetcode.cn/problems/path-sum-iii/description/](https://leetcode.cn/problems/path-sum-iii/description/)
- 代码文件：`leetcode/437.cc`
- 题目描述：统计二叉树中路径和等于目标值的向下路径数。
- 解法摘要：DFS 维护根到当前前缀和，用哈希计数 target 差值。

## <a id="leetcode-543"></a>LeetCode 543. 二叉树的直径

- 来源链接：[https://leetcode.cn/problems/diameter-of-binary-tree/description/](https://leetcode.cn/problems/diameter-of-binary-tree/description/)
- 代码文件：`leetcode/543.cc`
- 题目描述：求二叉树任意两点最长路径边数。
- 解法摘要：DFS 返回深度，同时用左右深度和更新直径。

## <a id="luogu-1030"></a>洛谷 P1030

- 来源链接：[https://www.luogu.com.cn/problem/P1030](https://www.luogu.com.cn/problem/P1030)
- 代码文件：`luogu/1030(树).cc`
- 分类标签：树
- 题目描述：洛谷 P1030，题面以原题链接为准；代码标签显示主要考点为「树」。
- 解法摘要：依据题意建模，核心实现标签为「树」，重点处理输入规模和边界。

## <a id="luogu-1087"></a>洛谷 P1087

- 来源链接：[https://www.luogu.com.cn/problem/P1087](https://www.luogu.com.cn/problem/P1087)
- 代码文件：`luogu/1087(树).cc`
- 分类标签：树
- 题目描述：洛谷 P1087，题面以原题链接为准；代码标签显示主要考点为「树」。
- 解法摘要：依据题意建模，核心实现标签为「树」，重点处理输入规模和边界。

## <a id="luogu-1305"></a>洛谷 P1305

- 来源链接：[https://www.luogu.com.cn/problem/P1305](https://www.luogu.com.cn/problem/P1305)
- 代码文件：`luogu/1305(树).cc`
- 分类标签：树
- 题目描述：洛谷 P1305，题面以原题链接为准；代码标签显示主要考点为「树」。
- 解法摘要：依据题意建模，核心实现标签为「树」，重点处理输入规模和边界。

## <a id="luogu-1972"></a>洛谷 P1972

- 来源链接：[https://www.luogu.com.cn/problem/P1972](https://www.luogu.com.cn/problem/P1972)
- 代码文件：`luogu/1972(树状数组&离散化).cc`
- 分类标签：树状数组&离散化
- 题目描述：洛谷 P1972，题面以原题链接为准；代码标签显示主要考点为「树状数组&离散化」。
- 解法摘要：树状数组维护前缀信息，支持单点修改与前缀查询。
- 交叉分类：数据结构、数组、双指针与贪心

## <a id="luogu-2023"></a>洛谷 P2023

- 来源链接：[https://www.luogu.com.cn/problem/P2023](https://www.luogu.com.cn/problem/P2023)
- 代码文件：`luogu/2023(segmenttree).cc`
- 分类标签：segmenttree
- 题目描述：洛谷 P2023，题面以原题链接为准；代码标签显示主要考点为「segmenttree」。
- 解法摘要：依据题意建模，核心实现标签为「segmenttree」，重点处理输入规模和边界。
- 交叉分类：数据结构

## <a id="luogu-2420"></a>洛谷 P2420

- 来源链接：[https://www.luogu.com.cn/problem/P2420](https://www.luogu.com.cn/problem/P2420)
- 代码文件：`luogu/2420(树型结构).cc`
- 分类标签：树型结构
- 题目描述：洛谷 P2420，题面以原题链接为准；代码标签显示主要考点为「树型结构」。
- 解法摘要：依据题意建模，核心实现标签为「树型结构」，重点处理输入规模和边界。

## <a id="luogu-2680"></a>洛谷 P2680

- 来源链接：[https://www.luogu.com.cn/problem/P2680](https://www.luogu.com.cn/problem/P2680)
- 代码文件：`luogu/2680(二分&lca).cc`
- 分类标签：二分&lca
- 题目描述：洛谷 P2680，题面以原题链接为准；代码标签显示主要考点为「二分&lca」。
- 解法摘要：预处理倍增祖先与深度，用 LCA 回答树上距离或路径问题。
- 交叉分类：图论、数组、双指针与贪心

## <a id="luogu-2783"></a>洛谷 P2783

- 来源链接：[https://www.luogu.com.cn/problem/P2783](https://www.luogu.com.cn/problem/P2783)
- 代码文件：`luogu/2783(lca).cpp`
- 分类标签：lca
- 题目描述：洛谷 P2783，题面以原题链接为准；代码标签显示主要考点为「lca」。
- 解法摘要：预处理倍增祖先与深度，用 LCA 回答树上距离或路径问题。
- 交叉分类：图论

## <a id="luogu-3372"></a>洛谷 P3372

- 来源链接：[https://www.luogu.com.cn/problem/P3372](https://www.luogu.com.cn/problem/P3372)
- 代码文件：`luogu/3372(线段树).cc`
- 分类标签：线段树
- 题目描述：洛谷 P3372，题面以原题链接为准；代码标签显示主要考点为「线段树」。
- 解法摘要：线段树维护区间信息，支持区间查询/修改。
- 交叉分类：数据结构

## <a id="luogu-3373"></a>洛谷 P3373

- 来源链接：[https://www.luogu.com.cn/problem/P3373](https://www.luogu.com.cn/problem/P3373)
- 代码文件：`luogu/3373(线段树).cc`
- 分类标签：线段树
- 题目描述：洛谷 P3373，题面以原题链接为准；代码标签显示主要考点为「线段树」。
- 解法摘要：线段树维护区间信息，支持区间查询/修改。
- 交叉分类：数据结构

## <a id="luogu-3374"></a>洛谷 P3374

- 来源链接：[https://www.luogu.com.cn/problem/P3374](https://www.luogu.com.cn/problem/P3374)
- 代码文件：`luogu/3374(线段树).cc`
- 分类标签：线段树
- 题目描述：洛谷 P3374，题面以原题链接为准；代码标签显示主要考点为「线段树」。
- 解法摘要：线段树维护区间信息，支持区间查询/修改。
- 交叉分类：数据结构

## <a id="luogu-3379"></a>洛谷 P3379

- 来源链接：[https://www.luogu.com.cn/problem/P3379](https://www.luogu.com.cn/problem/P3379)
- 代码文件：`luogu/3379(LCA).cc`
- 分类标签：LCA
- 题目描述：洛谷 P3379，题面以原题链接为准；代码标签显示主要考点为「LCA」。
- 解法摘要：预处理倍增祖先与深度，用 LCA 回答树上距离或路径问题。
- 交叉分类：图论

# 计算几何与随机化

## <a id="bzoj-3680"></a>BZOJ 3680

- 代码文件：`BZOJ/3680(SA).cc`
- 分类标签：SA
- 题目描述：BZOJ 3680，题面以原题为准；代码主要围绕「SA」实现。
- 解法摘要：模拟退火在连续空间中随机扰动逼近最优解。

## <a id="poj-2454"></a>POJ 2454

- 代码文件：`POJ/2454(随机化).cc`
- 分类标签：随机化
- 题目描述：POJ 2454，题面以原题为准；代码主要围绕「随机化」实现。
- 解法摘要：随机打乱或随机选择以规避构造性坏例。

## <a id="luogu-1665"></a>洛谷 P1665

- 来源链接：[https://www.luogu.com.cn/problem/P1665](https://www.luogu.com.cn/problem/P1665)
- 代码文件：`luogu/1665(计算几何).cc`
- 分类标签：计算几何
- 题目描述：洛谷 P1665，题面以原题链接为准；代码标签显示主要考点为「计算几何」。
- 解法摘要：按几何公式计算距离、面积或相交关系。

# 博弈论

- <a href="#luogu-2197">洛谷 P2197</a>：亦可归入「博弈论」，完整思路见主条目。
- <a href="#luogu-4702">洛谷 P4702</a>：亦可归入「博弈论」，完整思路见主条目。
# 模拟与杂项

## <a id="uva-156"></a>UVA 156

- 来源链接：[https://onlinejudge.org/external/1/156.pdf](https://onlinejudge.org/external/1/156.pdf)
- 代码文件：`UVA/156.cc`
- 题目描述：UVA 156，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-514"></a>UVA 514

- 来源链接：[https://onlinejudge.org/external/5/514.pdf](https://onlinejudge.org/external/5/514.pdf)
- 代码文件：`UVA/514.cc`
- 题目描述：UVA 514，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-572"></a>UVA 572

- 来源链接：[https://onlinejudge.org/external/5/572.pdf](https://onlinejudge.org/external/5/572.pdf)
- 代码文件：`UVA/572.cc`
- 题目描述：UVA 572，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-673"></a>UVA 673

- 来源链接：[https://onlinejudge.org/external/6/673.pdf](https://onlinejudge.org/external/6/673.pdf)
- 代码文件：`UVA/673.cc`
- 题目描述：UVA 673，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-699"></a>UVA 699

- 来源链接：[https://onlinejudge.org/external/6/699.pdf](https://onlinejudge.org/external/6/699.pdf)
- 代码文件：`UVA/699.cc`
- 题目描述：UVA 699，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-10111"></a>UVA 10111

- 来源链接：[https://www.luogu.com.cn/problem/UVA10111](https://www.luogu.com.cn/problem/UVA10111)；[https://onlinejudge.org/external/101/10111.pdf](https://onlinejudge.org/external/101/10111.pdf)
- 代码文件：`UVA/10111.md`、`UVA/10111_alphabeta.cc`
- 题目描述：UVA 10111，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="uva-10954"></a>UVA 10954

- 来源链接：[https://onlinejudge.org/external/109/10954.pdf](https://onlinejudge.org/external/109/10954.pdf)
- 代码文件：`UVA/10954.cc`
- 题目描述：UVA 10954，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="zoj-2417"></a>ZOJ 2417

- 代码文件：`ZOJ/2417.cc`
- 题目描述：ZOJ 2417，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="acwing-5018"></a>acwing 5018

- 来源链接：[https://www.acwing.com/problem/content/description/5021/](https://www.acwing.com/problem/content/description/5021/)
- 代码文件：`acwing/5018(ac).cc`、`acwing/5018(tle).cc`
- 分类标签：ac、tle
- 题目描述：AcWing 5018，题面以原题链接为准；代码主要围绕「ac、tle」实现。
- 解法摘要：依据题意建模，核心实现标签为「ac、tle」，重点处理输入规模和边界。

## <a id="codeforces-32"></a>codeforces 32

- 代码文件：`codeforces/32B.cc`
- 题目描述：Codeforces 32，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="codeforces-664a"></a>Codeforces 664A

- 代码文件：`codeforces/664A.cc`
- 题目描述：Codeforces 664A，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="codeforces-762a"></a>Codeforces 762A

- 代码文件：`codeforces/762A.cc`
- 题目描述：Codeforces 762A，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="codeforces-784e"></a>Codeforces 784E

- 代码文件：`codeforces/784E.cc`
- 题目描述：Codeforces 784E，题面以原题为准；代码主要围绕「综合实现」实现。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="leetcode-9"></a>LeetCode 9. 回文数

- 来源链接：[https://leetcode.cn/problems/palindrome-number/](https://leetcode.cn/problems/palindrome-number/)
- 代码文件：`leetcode/9(入门).cc`
- 分类标签：入门
- 题目描述：判断整数正向和反向读是否一致。
- 解法摘要：负数直接排除，反转后一半或转字符串比较。

## <a id="leetcode-11"></a>LeetCode 11. 盛最多水的容器

- 来源链接：[https://leetcode.cn/problems/container-with-most-water/](https://leetcode.cn/problems/container-with-most-water/)
- 代码文件：`leetcode/11.cc`
- 题目描述：选择两条竖线使容器面积最大。
- 解法摘要：双指针从两端向内，每次移动较短的一侧。

## <a id="leetcode-12"></a>LeetCode 12. 整数转罗马数字

- 来源链接：[https://leetcode.cn/problems/integer-to-roman/description/](https://leetcode.cn/problems/integer-to-roman/description/)
- 代码文件：`leetcode/12(入门).cc`
- 分类标签：入门
- 题目描述：把整数转换成罗马数字表示。
- 解法摘要：按数值从大到小贪心扣减并追加符号。

## <a id="leetcode-16"></a>LeetCode 16. 最接近的三数之和

- 来源链接：[https://leetcode.cn/problems/3sum-closest/description/](https://leetcode.cn/problems/3sum-closest/description/)
- 代码文件：`leetcode/16.cc`
- 题目描述：找出三数之和最接近目标值的组合。
- 解法摘要：排序后枚举第一个数，双指针根据当前和调整并维护最优差值。

## <a id="leetcode-42"></a>LeetCode 42. 接雨水

- 来源链接：[https://leetcode.cn/problems/trapping-rain-water/](https://leetcode.cn/problems/trapping-rain-water/)
- 代码文件：`leetcode/42.cc`
- 题目描述：给定柱高，计算可接雨水总量。
- 解法摘要：维护左右最高值，双指针从低的一侧结算贡献。

## <a id="leetcode-45"></a>LeetCode 45. 跳跃游戏 II

- 来源链接：[https://leetcode.cn/problems/jump-game-ii/description/](https://leetcode.cn/problems/jump-game-ii/description/)
- 代码文件：`leetcode/45.cc`
- 题目描述：求从起点跳到终点的最少跳跃次数。
- 解法摘要：贪心按层维护当前步可达边界和下一步最远边界。

## <a id="leetcode-51"></a>LeetCode 51. N 皇后

- 来源链接：[https://leetcode.cn/problems/n-queens/description/](https://leetcode.cn/problems/n-queens/description/)
- 代码文件：`leetcode/51.cc`
- 题目描述：在 n*n 棋盘放置 n 个互不攻击的皇后。
- 解法摘要：回溯按行放置，记录列、主对角线、副对角线占用。

## <a id="leetcode-54"></a>LeetCode 54. 螺旋矩阵

- 来源链接：[https://leetcode.cn/problems/spiral-matrix/](https://leetcode.cn/problems/spiral-matrix/)
- 代码文件：`leetcode/54.cc`
- 题目描述：按螺旋顺序输出矩阵元素。
- 解法摘要：维护上下左右边界，逐圈收缩遍历。

## <a id="leetcode-55"></a>LeetCode 55. 跳跃游戏

- 来源链接：[https://leetcode.cn/problems/jump-game/description/](https://leetcode.cn/problems/jump-game/description/)
- 代码文件：`leetcode/55.cc`
- 题目描述：判断能否从起点跳到终点。
- 解法摘要：贪心维护最远可达位置，发现当前位置不可达则失败。

## <a id="leetcode-56"></a>LeetCode 56. 合并区间

- 来源链接：[https://leetcode.cn/problems/merge-intervals/description/](https://leetcode.cn/problems/merge-intervals/description/)
- 代码文件：`leetcode/56.cc`
- 题目描述：合并所有重叠区间。
- 解法摘要：按左端点排序，线性维护当前合并区间。

## <a id="leetcode-70"></a>LeetCode 70. 爬楼梯

- 来源链接：[https://leetcode.cn/problems/climbing-stairs/description/](https://leetcode.cn/problems/climbing-stairs/description/)
- 代码文件：`leetcode/70.cc`
- 题目描述：每次爬 1 或 2 阶，求到达顶部的方法数。
- 解法摘要：斐波那契递推，滚动变量优化空间。

## <a id="leetcode-73"></a>LeetCode 73. 矩阵置零

- 来源链接：[https://leetcode.cn/problems/set-matrix-zeroes/description/](https://leetcode.cn/problems/set-matrix-zeroes/description/)
- 代码文件：`leetcode/73.cc`
- 题目描述：若矩阵元素为 0，则其所在行列置 0。
- 解法摘要：用首行首列作为标记，额外记录首列/首行状态。

## <a id="leetcode-76"></a>LeetCode 76. 最小覆盖子串

- 来源链接：[https://leetcode.cn/problems/minimum-window-substring/description/](https://leetcode.cn/problems/minimum-window-substring/description/)
- 代码文件：`leetcode/76.cc`
- 题目描述：求 s 中覆盖 t 所有字符的最短子串。
- 解法摘要：滑动窗口统计欠缺字符，满足后收缩左端更新答案。

## <a id="leetcode-118"></a>LeetCode 118. 杨辉三角

- 来源链接：[https://leetcode.cn/problems/pascals-triangle/description/](https://leetcode.cn/problems/pascals-triangle/description/)
- 代码文件：`leetcode/118.cc`
- 题目描述：生成前 numRows 行杨辉三角。
- 解法摘要：逐行递推，内部元素等于上一行相邻两数之和。

## <a id="leetcode-121"></a>LeetCode 121. 买卖股票的最佳时机

- 来源链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)
- 代码文件：`leetcode/121.cc`
- 题目描述：一次买卖股票获取最大利润。
- 解法摘要：遍历价格维护历史最低买入价与最大利润。

## <a id="leetcode-169"></a>LeetCode 169. 多数元素

- 来源链接：[https://leetcode.cn/problems/majority-element/description/](https://leetcode.cn/problems/majority-element/description/)
- 代码文件：`leetcode/169.cc`
- 题目描述：找出现次数超过一半的元素。
- 解法摘要：Boyer-Moore 投票算法抵消不同元素。

## <a id="leetcode-198"></a>LeetCode 198. 打家劫舍

- 来源链接：[https://leetcode.cn/problems/house-robber/description/](https://leetcode.cn/problems/house-robber/description/)
- 代码文件：`leetcode/198.cc`
- 题目描述：相邻房屋不能同时偷，求最大金额。
- 解法摘要：线性 DP，取偷当前加前前或不偷当前。

## <a id="leetcode-200"></a>LeetCode 200. 岛屿数量

- 来源链接：[https://leetcode.cn/problems/number-of-islands/description/](https://leetcode.cn/problems/number-of-islands/description/)
- 代码文件：`leetcode/200.cc`
- 题目描述：统计网格中陆地连通块数量。
- 解法摘要：遍历网格，遇到未访问陆地就 DFS/BFS 淹没一座岛。

## <a id="leetcode-207"></a>LeetCode 207. 课程表

- 来源链接：[https://leetcode.cn/problems/course-schedule/description/](https://leetcode.cn/problems/course-schedule/description/)
- 代码文件：`leetcode/207.cc`
- 题目描述：判断课程依赖是否可完成。
- 解法摘要：建有向图做拓扑排序，或 DFS 检测环。

## <a id="leetcode-347"></a>LeetCode 347. 前 K 个高频元素

- 来源链接：[https://leetcode.cn/problems/top-k-frequent-elements/description/](https://leetcode.cn/problems/top-k-frequent-elements/description/)
- 代码文件：`leetcode/347.cc`
- 题目描述：返回出现频率最高的 k 个元素。
- 解法摘要：哈希计数后用堆或桶排序取前 k。

## <a id="leetcode-739"></a>LeetCode 739. 每日温度

- 来源链接：[https://leetcode.cn/problems/daily-temperatures/description/](https://leetcode.cn/problems/daily-temperatures/description/)
- 代码文件：`leetcode/739.cc`
- 题目描述：对每天求等到更高温度的天数。
- 解法摘要：单调递减栈存下标，遇更高温时结算。

## <a id="leetcode-994"></a>LeetCode 994. 腐烂的橘子

- 来源链接：[https://leetcode.cn/problems/rotting-oranges/description/](https://leetcode.cn/problems/rotting-oranges/description/)
- 代码文件：`leetcode/994.cc`
- 题目描述：求所有新鲜橘子腐烂所需分钟数。
- 解法摘要：多源 BFS 从所有腐烂橘子同时扩散。

## <a id="leetcode-3583"></a>LeetCode 3583. 统计特殊三元组

- 来源链接：[https://leetcode.cn/problems/count-special-triplets/description/](https://leetcode.cn/problems/count-special-triplets/description/)
- 代码文件：`leetcode/3583.cc`
- 题目描述：统计满足特定数值关系的三元组数量。
- 解法摘要：哈希维护左右两侧计数，枚举中间位置累加贡献。

## <a id="luogu-1012"></a>洛谷 P1012

- 来源链接：[https://www.luogu.com.cn/problem/P1012](https://www.luogu.com.cn/problem/P1012)
- 代码文件：`luogu/1012.cc`
- 题目描述：洛谷 P1012，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1014"></a>洛谷 P1014

- 来源链接：[https://www.luogu.com.cn/problem/P1014](https://www.luogu.com.cn/problem/P1014)
- 代码文件：`luogu/1014.cc`
- 题目描述：洛谷 P1014，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1015"></a>洛谷 P1015

- 来源链接：[https://www.luogu.com.cn/problem/P1015](https://www.luogu.com.cn/problem/P1015)
- 代码文件：`luogu/1015.cc`
- 题目描述：洛谷 P1015，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1028"></a>洛谷 P1028

- 来源链接：[https://www.luogu.com.cn/problem/P1028](https://www.luogu.com.cn/problem/P1028)
- 代码文件：`luogu/1028.cc`
- 题目描述：洛谷 P1028，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1042"></a>洛谷 P1042

- 来源链接：[https://www.luogu.com.cn/problem/P1042](https://www.luogu.com.cn/problem/P1042)
- 代码文件：`luogu/1042.cc`
- 题目描述：洛谷 P1042，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1046"></a>洛谷 P1046

- 来源链接：[https://www.luogu.com.cn/problem/P1046](https://www.luogu.com.cn/problem/P1046)
- 代码文件：`luogu/1046.cc`
- 题目描述：洛谷 P1046，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1055"></a>洛谷 P1055

- 来源链接：[https://www.luogu.com.cn/problem/P1055](https://www.luogu.com.cn/problem/P1055)
- 代码文件：`luogu/1055.cc`
- 题目描述：洛谷 P1055，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1094"></a>洛谷 P1094

- 来源链接：[https://www.luogu.com.cn/problem/P1094](https://www.luogu.com.cn/problem/P1094)
- 代码文件：`luogu/1094.cc`
- 题目描述：洛谷 P1094，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1095"></a>洛谷 P1095

- 来源链接：[https://www.luogu.com.cn/problem/P1095](https://www.luogu.com.cn/problem/P1095)
- 代码文件：`luogu/1095(分治).cc`
- 分类标签：分治
- 题目描述：洛谷 P1095，题面以原题链接为准；代码标签显示主要考点为「分治」。
- 解法摘要：依据题意建模，核心实现标签为「分治」，重点处理输入规模和边界。

## <a id="luogu-1099"></a>洛谷 P1099

- 来源链接：[https://www.luogu.com.cn/problem/P1099](https://www.luogu.com.cn/problem/P1099)
- 代码文件：`luogu/1099_TreeDiameter.cc`
- 题目描述：洛谷 P1099，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1113"></a>洛谷 P1113

- 来源链接：[https://www.luogu.com.cn/problem/P1113](https://www.luogu.com.cn/problem/P1113)
- 代码文件：`luogu/1113(拓扑).cc`
- 分类标签：拓扑
- 题目描述：洛谷 P1113，题面以原题链接为准；代码标签显示主要考点为「拓扑」。
- 解法摘要：依据题意建模，核心实现标签为「拓扑」，重点处理输入规模和边界。

## <a id="luogu-1125"></a>洛谷 P1125

- 来源链接：[https://www.luogu.com.cn/problem/P1125](https://www.luogu.com.cn/problem/P1125)
- 代码文件：`luogu/1125.cc`
- 题目描述：洛谷 P1125，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1149"></a>洛谷 P1149

- 来源链接：[https://www.luogu.com.cn/problem/P1149](https://www.luogu.com.cn/problem/P1149)
- 代码文件：`luogu/1149(暴力).cc`
- 分类标签：暴力
- 题目描述：洛谷 P1149，题面以原题链接为准；代码标签显示主要考点为「暴力」。
- 解法摘要：枚举可行情况并配合必要剪枝/预处理。

## <a id="luogu-1151"></a>洛谷 P1151

- 来源链接：[https://www.luogu.com.cn/problem/P1151](https://www.luogu.com.cn/problem/P1151)
- 代码文件：`luogu/1151.cc`
- 题目描述：洛谷 P1151，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1181"></a>洛谷 P1181

- 来源链接：[https://www.luogu.com.cn/problem/P1181](https://www.luogu.com.cn/problem/P1181)
- 代码文件：`luogu/1181.cc`
- 题目描述：洛谷 P1181，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1200"></a>洛谷 P1200

- 来源链接：[https://www.luogu.com.cn/problem/P1200](https://www.luogu.com.cn/problem/P1200)
- 代码文件：`luogu/1200.cc`
- 题目描述：洛谷 P1200，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1204"></a>洛谷 P1204

- 来源链接：[https://www.luogu.com.cn/problem/P1204](https://www.luogu.com.cn/problem/P1204)
- 代码文件：`luogu/1204.cc`
- 题目描述：洛谷 P1204，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1219"></a>洛谷 P1219

- 来源链接：[https://www.luogu.com.cn/problem/P1219](https://www.luogu.com.cn/problem/P1219)
- 代码文件：`luogu/1219.cc`
- 题目描述：洛谷 P1219，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1228"></a>洛谷 P1228

- 来源链接：[https://www.luogu.com.cn/problem/P1228](https://www.luogu.com.cn/problem/P1228)
- 代码文件：`luogu/1228(递归).cc`
- 分类标签：递归
- 题目描述：洛谷 P1228，题面以原题链接为准；代码标签显示主要考点为「递归」。
- 解法摘要：依据题意建模，核心实现标签为「递归」，重点处理输入规模和边界。

## <a id="luogu-1233"></a>洛谷 P1233

- 来源链接：[https://www.luogu.com.cn/problem/P1233](https://www.luogu.com.cn/problem/P1233)
- 代码文件：`luogu/1233(dilworth定理).cc`
- 分类标签：dilworth定理
- 题目描述：洛谷 P1233，题面以原题链接为准；代码标签显示主要考点为「dilworth定理」。
- 解法摘要：依据题意建模，核心实现标签为「dilworth定理」，重点处理输入规模和边界。

## <a id="luogu-1308"></a>洛谷 P1308

- 来源链接：[https://www.luogu.com.cn/problem/P1308](https://www.luogu.com.cn/problem/P1308)
- 代码文件：`luogu/1308.cc`
- 题目描述：洛谷 P1308，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1364"></a>洛谷 P1364

- 来源链接：[https://www.luogu.com.cn/problem/P1364](https://www.luogu.com.cn/problem/P1364)
- 代码文件：`luogu/1364(暴力).cc`
- 分类标签：暴力
- 题目描述：洛谷 P1364，题面以原题链接为准；代码标签显示主要考点为「暴力」。
- 解法摘要：枚举可行情况并配合必要剪枝/预处理。

## <a id="luogu-1427"></a>洛谷 P1427

- 来源链接：[https://www.luogu.com.cn/problem/P1427](https://www.luogu.com.cn/problem/P1427)
- 代码文件：`luogu/1427.cc`
- 题目描述：洛谷 P1427，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1428"></a>洛谷 P1428

- 来源链接：[https://www.luogu.com.cn/problem/P1428](https://www.luogu.com.cn/problem/P1428)
- 代码文件：`luogu/1428.cc`
- 题目描述：洛谷 P1428，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1540"></a>洛谷 P1540

- 来源链接：[https://www.luogu.com.cn/problem/P1540](https://www.luogu.com.cn/problem/P1540)
- 代码文件：`luogu/1540.cc`
- 题目描述：洛谷 P1540，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1547"></a>洛谷 P1547

- 来源链接：[https://www.luogu.com.cn/problem/P1547](https://www.luogu.com.cn/problem/P1547)
- 代码文件：`luogu/1547.cc`
- 题目描述：洛谷 P1547，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1563"></a>洛谷 P1563

- 来源链接：[https://www.luogu.com.cn/problem/P1563](https://www.luogu.com.cn/problem/P1563)
- 代码文件：`luogu/1563.cc`
- 题目描述：洛谷 P1563，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1618"></a>洛谷 P1618

- 来源链接：[https://www.luogu.com.cn/problem/P1618](https://www.luogu.com.cn/problem/P1618)
- 代码文件：`luogu/1618.cc`
- 题目描述：洛谷 P1618，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1634"></a>洛谷 P1634

- 来源链接：[https://www.luogu.com.cn/problem/P1634](https://www.luogu.com.cn/problem/P1634)
- 代码文件：`luogu/1634.cc`
- 题目描述：洛谷 P1634，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1802"></a>洛谷 P1802

- 来源链接：[https://www.luogu.com.cn/problem/P1802](https://www.luogu.com.cn/problem/P1802)
- 代码文件：`luogu/1802.cpp`
- 题目描述：洛谷 P1802，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1888"></a>洛谷 P1888

- 来源链接：[https://www.luogu.com.cn/problem/P1888](https://www.luogu.com.cn/problem/P1888)
- 代码文件：`luogu/1888.cc`
- 题目描述：洛谷 P1888，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-1996"></a>洛谷 P1996

- 来源链接：[https://www.luogu.com.cn/problem/P1996](https://www.luogu.com.cn/problem/P1996)
- 代码文件：`luogu/1996.cc`
- 题目描述：洛谷 P1996，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-2152"></a>洛谷 P2152

- 来源链接：[https://www.luogu.com.cn/problem/P2152](https://www.luogu.com.cn/problem/P2152)
- 代码文件：`luogu/2152.cpp`
- 题目描述：洛谷 P2152，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-2278"></a>洛谷 P2278

- 来源链接：[https://www.luogu.com.cn/problem/P2278](https://www.luogu.com.cn/problem/P2278)
- 代码文件：`luogu/2278(毒瘤题).cc`
- 分类标签：毒瘤题
- 题目描述：洛谷 P2278，题面以原题链接为准；代码标签显示主要考点为「毒瘤题」。
- 解法摘要：依据题意建模，核心实现标签为「毒瘤题」，重点处理输入规模和边界。

## <a id="luogu-2580"></a>洛谷 P2580

- 来源链接：[https://www.luogu.com.cn/problem/P2580](https://www.luogu.com.cn/problem/P2580)
- 代码文件：`luogu/2580.cpp`
- 题目描述：洛谷 P2580，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-2615"></a>洛谷 P2615

- 来源链接：[https://www.luogu.com.cn/problem/P2615](https://www.luogu.com.cn/problem/P2615)
- 代码文件：`luogu/2615.cc`
- 题目描述：洛谷 P2615，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-2888"></a>洛谷 P2888

- 来源链接：[https://www.luogu.com.cn/problem/P2888](https://www.luogu.com.cn/problem/P2888)
- 代码文件：`luogu/2888.cc`
- 题目描述：洛谷 P2888，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-3478"></a>洛谷 P3478

- 来源链接：[https://www.luogu.com.cn/problem/P3478](https://www.luogu.com.cn/problem/P3478)
- 代码文件：`luogu/3478(ac).cc`、`luogu/3478(tle).cc`
- 分类标签：ac、tle
- 题目描述：洛谷 P3478，题面以原题链接为准；代码标签显示主要考点为「ac、tle」。
- 解法摘要：依据题意建模，核心实现标签为「ac、tle」，重点处理输入规模和边界。

## <a id="luogu-3741"></a>洛谷 P3741

- 来源链接：[https://www.luogu.com.cn/problem/P3741](https://www.luogu.com.cn/problem/P3741)
- 代码文件：`luogu/3741.cc`
- 题目描述：洛谷 P3741，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-4551"></a>洛谷 P4551

- 来源链接：[https://www.luogu.com.cn/problem/P4551](https://www.luogu.com.cn/problem/P4551)
- 代码文件：`luogu/4551(最长异或路径).cpp`
- 分类标签：最长异或路径
- 题目描述：洛谷 P4551，题面以原题链接为准；代码标签显示主要考点为「最长异或路径」。
- 解法摘要：依据题意建模，核心实现标签为「最长异或路径」，重点处理输入规模和边界。

## <a id="luogu-4781"></a>洛谷 P4781

- 来源链接：[https://www.luogu.com.cn/problem/P4781](https://www.luogu.com.cn/problem/P4781)
- 代码文件：`luogu/4781.cc`
- 题目描述：洛谷 P4781，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。

## <a id="luogu-4994"></a>洛谷 P4994

- 来源链接：[https://www.luogu.com.cn/problem/P4994](https://www.luogu.com.cn/problem/P4994)
- 代码文件：`luogu/4994(暴力).cc`
- 分类标签：暴力
- 题目描述：洛谷 P4994，题面以原题链接为准；代码标签显示主要考点为「暴力」。
- 解法摘要：枚举可行情况并配合必要剪枝/预处理。

## <a id="luogu-b4016"></a>洛谷 B4016

- 来源链接：[https://www.luogu.com.cn/problem/B4016](https://www.luogu.com.cn/problem/B4016)
- 代码文件：`luogu/B4016_TreeDiameter.cc`
- 题目描述：洛谷 B4016，题面以原题链接为准；代码标签显示主要考点为「综合实现」。
- 解法摘要：依据题意建模，核心实现标签为「综合实现」，重点处理输入规模和边界。
