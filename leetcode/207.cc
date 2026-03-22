// https://leetcode.cn/problems/course-schedule/description/

#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 使用局部变量，每次调用函数时都会重新初始化
        vector<vector<int>> graph(numCourses); // 邻接表
        vector<int> inDegree(numCourses, 0);   // 入度数组
        
        // 建图并统计入度
        for(const auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        // 将所有入度为 0 的节点加入队列
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) { 
                q.push(i); 
            }
        }
        
        // 拓扑排序 (BFS)
        int completedCourses = 0; // 用计数器代替 vis 数组，更为简便
        while(!q.empty()) {
            int curr = q.front(); 
            q.pop();
            completedCourses++; // 成功修完一门课
            
            // 遍历相邻节点，将它们的入度减 1
            for(int neighbor : graph[curr]) {
                if(--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // 如果完成的课程数量等于总课程数，说明没有环
        return completedCourses == numCourses;
    }
};