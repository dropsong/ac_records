// https://leetcode.cn/problems/combinations/
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

#include <vector>
#include <cstdio>

using std::vector;

class Solution_dummy {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        in_n = n, in_k = k;
        vector<int> tmp_ans;
        work(1, 0, tmp_ans);
        return ans;
    }

    void work(int pos, int has, vector<int>& tmp_ans) {
        if(has == in_k) {
            ans.push_back(tmp_ans);
            return;
        }
        if(pos == in_n+1) {
            return;
        }
        if(has + in_n - pos + 1 < in_k) {  // 这个剪枝反而让实际执行时间变长了
            return;
        }
        tmp_ans.push_back(pos);
        work(pos+1, has+1, tmp_ans);
        tmp_ans.pop_back();
        work(pos+1, has, tmp_ans);
    }

private:
    vector<vector<int>> ans;
    int in_n, in_k;
};


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        in_n = n;
        in_k = k;

        vector<int> path;
        work(1, path);

        return ans;
    }

private:
    void work(int start, vector<int>& path) {
        if (path.size() == in_k) {
            ans.push_back(path);
            return;
        }

        int need = in_k - path.size();

        for (int i = start; i <= in_n - need + 1; ++i) {
            path.push_back(i);
            work(i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> ans;
    int in_n, in_k;
};

#if 0
int main() {
    Solution S;
    // test case
    auto result = S.combine(1, 1);
    auto result2 = S.combine(4, 2);
    // output
    for(const auto& row : result) {
        for(const auto& col : row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    printf("\n");
    for(const auto& row : result2) {
        for(const auto& col : row) {
            printf("%d ", col);
        }
        printf("\n");
    }
    return 0;
}
#endif