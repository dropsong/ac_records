// luogu-judger-enable-o2
//每一个不曾AC的日子都是一种遗憾
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
#include<string>
#include<sstream>
#define MAXN 10000000
#define TARGET 123804765
using namespace std;

bool ok=false;
int q[MAXN][2];
int front,rear;
set<int> a;
const int b[9][5]={1,3,-1,-1,-1
                  ,0,2,4,-1,-1
                  ,1,5,-1,-1,-1
                  ,0,4,6,-1,-1
                  ,3,5,1,7,-1
                  ,2,4,8,-1,-1
                  ,3,7,-1,-1,-1
                  ,6,4,8,-1,-1
                  ,7,5,-1,-1,-1};

void TEST(bool enable1,bool enable2,string ch,int i)
{
    cout<<endl;
    if(enable1)
    cout<<"test: "<<ch<<"="<<i<<endl;
    if(enable2){
        printf("front: %d\n",front);
    	printf("rear: %d\n",rear);
    	printf("q[front][0]= %d\n",q[front][0]);
    	printf("q[rear-1][0]= %d\n",q[rear-1][0]);
        printf("the size of a: %d\n",a.size());
    }
    system("pause");
}

inline void _swap(char &ch1,char &ch2)
{
    char ch3=ch1;
    ch1=ch2;
    ch2=ch3;
}

inline string numToStr(int i)  
{  
    stringstream ss;  
    ss<<i;
    string st=ss.str();
    if(i<100000000)st="0"+st;
    return st;
}  
  
inline int strToNum(string s)  
{  
    int num;  
    stringstream ss(s);  
    ss>>num;
    return num;  
}

inline int find_0(int x)
{
    string st=numToStr(x);
    if(st.size()==8)return 0;
    for(int i=0;st[i];i++)
    {
        if(st[i]=='0')
        return i;
    }
}

inline int transf(int n,int s,int e)
{
    string st=numToStr(n);
    _swap(st[s],st[e]);
    return strToNum(st);
}

inline void BFS()
{
    while(front<=rear)
    {
        int qwq=q[front][0];
        //TEST(false,true,"qwq",qwq);
        int pos=find_0(qwq);
        
        for(int i=0;b[pos][i]!=-1;i++)
        {
            int nqwq=transf(qwq,pos,b[pos][i]);
            if(a.count(nqwq))continue;
            else{
                if(nqwq==TARGET){
                    printf("%d",q[front][1]+1);
                    ok=true;
                    return;
                }
                q[rear][0]=nqwq;
                q[rear++][1]=q[front][1]+1;
                a.insert(nqwq);
                //TEST(false,true,"ignore",0);
            }
        }		
        front++;
    }
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==TARGET){
    	cout<<0;
    	return 0;
    }
    q[0][0]=n; q[0][1]=0;
    rear++;
    a.insert(n);
    //TEST(false,true,"kill",0);
    BFS();
    
    if(ok)return 0;
    printf("no solution\n");
    return 0;
}