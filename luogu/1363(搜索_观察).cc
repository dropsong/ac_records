// link: https://www.luogu.com.cn/problem/P1363
// ref: https://www.luogu.com.cn/problem/solution/P1363
// github: https://github.com/dropsong

/*

   1   2   3
##.###.###.#
##.###.###.#
#..##..##..#
..#...#...#.
#.###.###.##   1
##.###.###.#
##.###S###.#
#..##..##..#
..#...#...#.
#.###.###.##   2
##.###.###.#
##.###.###.#
#..##..##..#
..#...#...#.
#.###.###.##   3

性质（易证）：
1. 如果无法走出幻象迷宫（即无法到达无穷远处），S 会被包围
2. 可以走出迷宫的充要条件： S 可以走到不同地图上和出发点相同的对应位置
   - 充分性：
     假设起点 S 的坐标是 (sr, sc)。它在基础矩阵单元中的位置是 (sr mod N, sc mod M)。如果在另一个矩阵单元（例如，向右移动一个单元）中的对应位置 (sr + N, sc) 也是可达的，这意味着存在一条从 (sr, sc) 到 (sr + N, sc) 的路径。
     由于迷宫的结构是周期性重复的，那么我们必然可以将在 (sr, sc) 的路径平移，得到一条从 (sr + N, sc) 到 (sr + 2*N, sc) 的路径。
     这个过程可以无限重复下去：(sr, sc) -> (sr + N, sc) -> (sr + 2*N, sc) -> ... -> (sr + k*N, sc)。当 k 趋向于无穷大时，我们离起点的距离也趋向于无穷大。因此，这是可以走出迷宫的充分条件。
    - 必要性：
     反过来，如果我们能走出迷宫，这是否意味着 S 必须能走到另一个对应的 S 位置呢？
     如果我们能走出迷宫，意味着可达点的集合是无限的。由于基础矩阵单元 N x M 的大小是有限的（只有 N*M 种不同的 (r mod N, c mod M) 状态），根据鸽巢原理，在我们走过的无限个点中，必然有两个不同的点 (r1, c1) 和 (r2, c2)，它们在基础矩阵单元中的对应位置是相同的。也就是说：
          r1 mod N == r2 mod N
          c1 mod M == c2 mod M
          (r1, c1) != (r2, c2)
     这意味着，r2 = r1 + k*N 且 c2 = c1 + l*M，其中 k, l 是整数且不都为0。
     因为从 S 能走到 (r1, c1)，也能走到 (r2, c2)，所以 (r1, c1) 和 (r2, c2) 在同一个连通分量里。这意味着存在一条从 (r1, c1) 到 (r2, c2) 的路径。
     同样，由于周期性，我们可以把这条路径平移，从而可以从 (r2, c2) 走到 (r2 + k*N, c2 + l*M)，无限延伸。
     这个无限延伸的连通分量包含了 S，所以 S 也能走到这个无限路径上。因此，整个 S 所在的连通分量都是“无限”的。在这个无限的连通分量里，任意一个点 (r, c) 都能走到其对应的 (r + k*N, c + l*M) 位置。自然，起点 S 也可以。
    所以，“能走到任意一个（而不仅仅是S）在不同地图上的对应位置”是充要条件。

*/


#include <cstdio>
#include <cstring>

const int MAXN = 1505;
bool mmap[MAXN][MAXN];  // 0 代表可走，1 代表不可走
bool flag;
int vis[MAXN][MAXN][3], n, m;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


void dfs(int x, int y, int lx, int ly)
{
    if(flag) return;
    if(vis[x][y][0] && (vis[x][y][1]!=lx || vis[x][y][2]!=ly))
    {
        flag = true;
        return;
    }

    vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
    for(int i=0; i<4; ++i) {
		int xx = (x + dx[i] + n) % n, yy = (y + dy[i] + m) % m;
		int lxx = lx + dx[i], lyy = ly + dy[i];
		if(!mmap[xx][yy]) {
			if(vis[xx][yy][1]!=lxx || vis[xx][yy][2]!=lyy || !vis[xx][yy][0])
				dfs(xx, yy, lxx, lyy);
		}
	}
}


int main()
{
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
        int sx = -1, sy = -1; flag = false;
        memset(mmap, 0, sizeof(mmap));
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char tmp; scanf(" %c", &tmp);
                if(tmp == '#') mmap[i][j] = 1;
				if(tmp == 'S') sx = i, sy = j;
            }
        }
        dfs(sx, sy, sx, sy);
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
