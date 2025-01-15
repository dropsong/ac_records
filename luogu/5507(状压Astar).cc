// https://www.luogu.com.cn/problem/P5507
#include <cstdio>
#include <queue>
#include <cctype>

using std::priority_queue;

const int J = 1<<24;
int nxt[15][10], g[J+10];
bool vis[J+10];
int pre[J+10], button[J+10]; //从哪个状态过来；从那个状态过来是使用了什么按钮 

inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
    return x*f;
}

class node
{
public:
	node(int status)
    : _status(status)
	{
		double h = 0.0;
		for(int i = 0; i < 12; i++)
            h += (4 - ( (_status>>(i*2)) & 3) ) & 3;
		h /= 2.0;
		_f = g[_status] + h;	
	}
    /*           (important) 关于 h 的设计：
    假设现在的旋钮状态(a1, a2, ..., a12)，如何对 h 值作一个乐观的估计？
    对于每一个旋钮：
        如果状态为 0，它至少需要动 0 下
        如果状态为 1，它至少需要动 3 下
        如果状态为 2，它至少需要动 2 下
        如果状态为 3，它至少需要动 1 下
    由于操作一次，会有两个旋钮变化，因此每个旋钮我们都多统计了一次。
    所以至少至少需要（将上面次数加起来的一半）次。
    若不能整除也没关系，因为这里需要的是一个“乐观”的估计。
    */

    bool operator < (const node& rhs) const
    {
        return _f > rhs._f;
    }

	int _status;
	double _f;  // A* algorithm
};

priority_queue<node> qwq;
int s;  // start status

void A_Star()
{
    vis[s] = true;
    qwq.push(node(s));

    while(!qwq.empty())
    {
        int st = qwq.top()._status;  qwq.pop();
        if(st == 0) break; // end status

        for(int i = 0; i < 12; ++i)
        {
        	// 将要改变（还未改变）的 i 的状态，随之改变的按钮的编号及该按钮的状态
            int sti = (st>>(i*2)) & 3, di = nxt[i][sti], stdi = ( st>>(di*2) ) & 3; 

            // 改变第 i 个按钮的状态，(sti + 1) % 4
         	int dst = st ^ (sti << (i * 2)) ^ (((sti + 1) & 3) << (i * 2));
            // st ^ (sti << (i * 2)) 将对应二进制位清零
            // 上面的结果再 ^ (((sti + 1) & 3) << (i * 2)) ，将新的二进制位拼接进去

         	// 同理，改变第 di 个按钮的状态
            dst = dst ^ (stdi << (di * 2)) ^ (((stdi + 1) & 3) << (di * 2));

            if(!vis[dst])
            {
                g[dst] = g[st] + 1;
                pre[dst] = st, button[dst] = i + 1;
                vis[dst] = true;
                qwq.push(node(dst));
            }
        }
    }
}

inline void input()
{
	for(int i = 0; i < 12; ++i)
	{
		int a = rd() - 1;
        s |= (a << (i * 2));
		for (int j = 0; j < 4; j++) nxt[i][j] = rd() - 1;
	}	
}

void output(int x)
{
	if (x == s) return;
	output(pre[x]), printf("%d ", button[x]);
}

int main()
{
	input();
	A_Star();
	printf("%d\n", g[0]); // 0 is the target status
	output(0);
	return 0;
}
