// https://leetcode.cn/problems/longest-cycle-in-a-graph/description/
// 给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。
// 请你返回图中的 最长环，如果没有任何环，请返回 -1 。

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

const int MAXN = 1e5+5;
const int MAXM = MAXN;

class Tarjan {
public:
    inline void addedge(int x, int y) {
        edge[++tot].v = y;
        edge[tot].next = head[x];
        head[x] = tot;
        if(x == y) selfloop[x] = true;   // 自环也是一个长度为 1 的环
    }

    void tarjan(int x) {
        low[x] = dfn[x] = ++num;
        stac[++top] = x; ins[x] = true;
        for(int i = head[x]; i; i = edge[i].next) {
            int y = edge[i].v;
            if(!dfn[y]) {
                tarjan(y);
                low[x] = std::min(low[x], low[y]);
            } else if(ins[y]) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if(dfn[x] == low[x]) {
            int y; int cnt = 0;
            do {
                y = stac[top--]; ins[y] = false;
                ++cnt;   // 每个节点至多有一条出边实际上保证了我们这样做的正确性，否则 tarjan 只是求出强连通分量的大小
            }while(x!=y);
            // 出度为 0 的孤立点也会被弹成一个大小为 1 的 SCC，但它不是环；
            // 只有 多节点 SCC（必是简单环）或 自环 才是合法的环
            if(cnt > 1 || selfloop[x]) ans = std::max(ans, cnt);
        }
    }

    struct Edge{int v, next;} edge[MAXM];
    int head[MAXN] = {};
    int dfn[MAXN] = {};
    int low[MAXN] = {};
    int stac[MAXN] = {};
    bool ins[MAXN] = {};
    bool selfloop[MAXN] = {};
    int n = 0, m = 0, tot = 0, num = 0, top = 0, ans = -1;
};


class Solution {
public:
    int longestCycle(vector<int>& edges) {
        Tarjan t;
        for(int i = 0; i < edges.size(); ++i) {
            if(edges[i] != -1) t.addedge(i, edges[i]);
        }
        for(int i = 0; i < edges.size(); ++i) {
            if(!t.dfn[i]) t.tarjan(i);
        }
        return t.ans;
    }
};

#if 0
int main() {
    Solution s;
    vector<int> in1 = {3, 3, 4, 2, 3}; // 3
    vector<int> in2 = {2, -1, 3, 1};   // -1
    cout << s.longestCycle(in1) << endl;
    cout << s.longestCycle(in2) << endl;
    return 0;
}
#endif
