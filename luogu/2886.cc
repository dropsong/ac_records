// https://www.luogu.com.cn/problem/P2886

#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

using Matrix = std::vector<std::vector<long long>>;

constexpr long long INF = std::numeric_limits<long long>::max() / 4;


// Min-Plus 矩阵乘法
//
// left[i][k]  表示第一段路径的最短距离
// right[k][j] 表示第二段路径的最短距离
//
// result[i][j] = min_k(left[i][k] + right[k][j])
Matrix minPlusMultiply(const Matrix& left, const Matrix& right) {
    const int vertexCount = static_cast<int>(left.size());

    Matrix result(
        vertexCount,
        std::vector<long long>(vertexCount, INF)
    );

    for (int i = 0; i < vertexCount; ++i) {
        for (int k = 0; k < vertexCount; ++k) {
            if (left[i][k] == INF) {
                continue;
            }

            for (int j = 0; j < vertexCount; ++j) {
                if (right[k][j] == INF) {
                    continue;
                }

                result[i][j] = std::min(
                    result[i][j],
                    left[i][k] + right[k][j]
                );
            }
        }
    }

    return result;
}


// 构造 Min-Plus 乘法下的单位矩阵。
// 它表示“恰好经过 0 条边”的最短距离：
// 自己到自己为 0，其余位置为 INF。
Matrix createIdentityMatrix(int vertexCount) {
    Matrix identity(
        vertexCount,
        std::vector<long long>(vertexCount, INF)
    );

    for (int i = 0; i < vertexCount; ++i) {
        identity[i][i] = 0;
    }

    return identity;
}


// Min-Plus 矩阵快速幂
Matrix minPlusPower(Matrix base, int exponent) {
    const int vertexCount = static_cast<int>(base.size());
    Matrix result = createIdentityMatrix(vertexCount);

    while (exponent > 0) {
        if (exponent & 1) {
            result = minPlusMultiply(result, base);
        }

        base = minPlusMultiply(base, base);
        exponent >>= 1;
    }

    return result;
}


struct Edge {
    int from;
    int to;
    int weight;
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int requiredEdgeCount;
    int edgeCount;
    int startLabel;
    int endLabel;

    std::cin >> requiredEdgeCount
             >> edgeCount
             >> startLabel
             >> endLabel;

    std::vector<Edge> edges;
    edges.reserve(edgeCount);

    std::unordered_map<int, int> vertexId;

    auto getVertexId = [&vertexId](int label) -> int {
        auto it = vertexId.find(label);

        if (it != vertexId.end()) {
            return it->second;
        }

        int newId = static_cast<int>(vertexId.size());
        vertexId[label] = newId;
        return newId;
    };

    // S 和 E 也提前加入映射。
    int start = getVertexId(startLabel);
    int end = getVertexId(endLabel);

    for (int i = 0; i < edgeCount; ++i) {
        int weight;
        int fromLabel;
        int toLabel;

        std::cin >> weight >> fromLabel >> toLabel;

        int from = getVertexId(fromLabel);
        int to = getVertexId(toLabel);

        edges.push_back({from, to, weight});
    }

    const int vertexCount = static_cast<int>(vertexId.size());

    Matrix adjacency(
        vertexCount,
        std::vector<long long>(vertexCount, INF)
    );

    for (const Edge& edge : edges) {
        adjacency[edge.from][edge.to] =
            std::min(adjacency[edge.from][edge.to],
                     static_cast<long long>(edge.weight));

        adjacency[edge.to][edge.from] =
            std::min(adjacency[edge.to][edge.from],
                     static_cast<long long>(edge.weight));
    }

    Matrix shortestDistance =
        minPlusPower(adjacency, requiredEdgeCount);

    std::cout << shortestDistance[start][end] << '\n';

    return 0;
}