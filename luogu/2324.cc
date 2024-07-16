#include <cstdio>
#include <algorithm>
#include <cctype>

int target[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0, 2, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0},
};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int st[6][6], sx, sy;
bool ok;

inline bool isValid(int x, int y)
{
    if(x<1 || x>5 || y<1 || y>5) return false;
    return true;
}

int h() // A* algo: f = g + h
{
    int cnt = 0;
    for(int i = 1; i < 6; ++i)
        for(int j = 1; j < 6; ++j)
            if(st[i][j] ^ target[i][j]) ++cnt;
    return cnt;
}

void dfs(int dep, int x, int y, int maxD)
{
    if(dep == maxD)
    {
        if(!h()) ok = true;
        return;
    }

    for(int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!isValid(nx, ny)) continue;

        std::swap(st[x][y], st[nx][ny]);
        if(dep + h() <= maxD)
            dfs(dep+1, nx, ny, maxD);
        std::swap(st[x][y], st[nx][ny]);
    }
}

int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        for(int i = 1; i < 6; ++i)
        {
            char ch[6];
            scanf("%s", ch);
            for(int j = 1; j < 6; ++j)
                if(ch[j-1] == '*')
                {
                    st[i][j] = 2;
                    sx = i; sy = j;
                }
                else st[i][j] = ch[j-1]-'0';
        }

        if(!h()) { printf("0\n"); continue; } // already in target status

        ok = false;
        for(int mDep = 1; mDep < 16; ++mDep)
        {
            dfs(0, sx, sy, mDep);
            if(ok)
            {
                printf("%d\n", mDep);
                break;
            }
        }
        if(!ok) printf("-1\n");
    }

    return 0;
}