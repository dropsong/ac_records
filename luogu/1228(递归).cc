// link:       https://www.luogu.com.cn/problem/P1228
// follow me:  https://github.com/dropsong
// 解题思路：
// 每次将区域划分为四个象限，排除公主在的那个格子，
// 先填满剩下的三个格子（容易发现可以做到），
// 剩下的问题就变成了一个规模更小的子问题。
// 边界是：最后只剩下4个格子。

#include <cstdio>

/**
 *@param a 当前处理的方格的左上坐标位置，行
 *@param b 当前处理的方格的左上坐标位置，列
 *@param len 当前处理的方格的边长
 *@param prinx 公主的行坐标
 *@param priny 公主的列坐标
 */
void solve(int a, int b, int len, int prinx, int priny)
{
    if(len==2){ // 2*2 square
        if(prinx==a){
            if(priny==b){ //1
                printf("%d %d 1\n",a+1,b+1);
            }
            else{ //2
                printf("%d %d 2\n",a+1,b);
            }
        }
        else{
            if(priny==b){ // 3
                printf("%d %d 3\n",a,b+1);
            }
            else{ // 4
                printf("%d %d 4\n",a,b);
            }
        }
        return;
    }
    if(prinx<a+len/2){
        if(priny<b+len/2){ // 1
            printf("%d %d 1\n",a+len/2,b+len/2);
            solve(a, b, len/2, prinx, priny);
            solve(a, b+len/2, len/2, a+len/2-1, b+len/2);
            solve(a+len/2, b, len/2, a+len/2, b+len/2-1);
            solve(a+len/2, b+len/2, len/2, a+len/2, b+len/2);
        }
        else{ // 2
            printf("%d %d 2\n",a+len/2,b+len/2-1);
            solve(a, b, len/2, a+len/2-1, b+len/2-1);
            solve(a, b+len/2, len/2, prinx, priny);
            solve(a+len/2, b, len/2, a+len/2, b+len/2-1);
            solve(a+len/2, b+len/2, len/2, a+len/2, b+len/2);
        }
    }
    else{
        if(priny<b+len/2){ // 3
            printf("%d %d 3\n",a+len/2-1,b+len/2);
            solve(a, b, len/2, a+len/2-1, b+len/2-1);
            solve(a, b+len/2, len/2, a+len/2-1, b+len/2);
            solve(a+len/2, b, len/2, prinx, priny);
            solve(a+len/2, b+len/2, len/2, a+len/2, b+len/2);
        }
        else{ // 4
            printf("%d %d 4\n",a+len/2-1,b+len/2-1);
            solve(a, b, len/2, a+len/2-1, b+len/2-1);
            solve(a, b+len/2, len/2, a+len/2-1, b+len/2);
            solve(a+len/2, b, len/2, a+len/2, b+len/2-1);
            solve(a+len/2, b+len/2, len/2, prinx, priny);
        }
    }
}

int main(){
    int princess_x, princess_y, k;
    scanf("%d",&k);
    scanf("%d%d",&princess_x,&princess_y);
    solve(1, 1, 1<<k, princess_x, princess_y);
    return 0;
}
