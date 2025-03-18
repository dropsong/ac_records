/*********************************************
//0=O(1) 1=O(n^1) 2=O(n^2) etc.
#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct for_unit
{
    string i,x,y;
    LL result;
    void input(){cin>>i>>x>>y;}
    void work()
    {
        if(x=="n"){result=0;return;}
        if(y=="n"){result=1;return;}
        result=0; return;
    }
};

int trans(string s)
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

void input_for()
{
    stack<for_unit> s;
    string st,guess,flag;
    LL hang;
    
    cin>>hang>>st;
    for(int j=0;st[j];j++)
    if(isdigit(st[j]))guess+=st[j];
    
    for_unit temp;
    LL ans=-1,sum=0;
    bool ok=true;
    while(hang--)
    {
        cin>>flag;
        if(flag=="F"){
            temp.input();
            temp.work();
            if(ok)
            {
                s.push(temp);
                //cout<<"push_test succeed."<<endl;
            }
        }
        else if(flag=="E")
        {
            //cout<<"test"<<endl;
            if(s.empty()){
            	//cout<<"test failed."<<endl;
                if(ok)printf("ERR\n");
                ok=false;
            }
            if(ok)
            {
                for_unit tp=s.top();
                s.pop();
                sum+=tp.result;
                //cout<<"test_flag_E"<<endl;
                if(s.empty())
                {
                    if(sum>ans)ans=sum;
                    sum=0;
                }
            }
        }
    }
    if(!ok)return;
    //s.top().output();  //test
    if(!s.empty())printf("ERR\n");
    else if(ans==0&&st.size()==4)printf("Yes\n");
    else if(ans==0&&(st.size()!=4))printf("No\n");
    else if(ans==(LL)trans(guess))printf("Yes\n");
    else printf("No\n");
}

int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)input_for();
    return 0;
}
***********************************************/

#include<bits/stdc++.h>
using namespace std;

const int N=110,inf=1e9;
int st[N],val[N],top;
bool bz[N];

int read()
{
    int X=0,w=1;
    char ch=0;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}

int get()
{
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='n')ch=getchar();
    if(ch=='n')return inf;
    int ret=ch-'0';
    ch=getchar();
    while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
    return ret;
}

void readln()
{
    char ch=getchar();
    while(ch!='O'&&ch!='F'&&ch!='E')ch=getchar();
    if(ch=='O')
    {
        getchar(),getchar();
    }
    else if(ch=='F')
    {
        getchar(),getchar();
        get(),get();
    }
}

int main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        if(n&1)
        {
            printf("ERR\n");
            for(int i=0;i<=n;i++) readln();
            continue;
        }
        getchar(),getchar();
        char s=getchar();
        int t=0,pd=top=0,mx=0;
        
        memset(bz,false,sizeof(bz));
        memset(st,0,sizeof(st));
        memset(val,0,sizeof(val));
        
        if(s=='n')
        {
            while(s<'0' || s>'9') s=getchar();
            while(s>='0' && s<='9') t=t*10+s-'0',s=getchar();
        }
        else s='0';
        
        for(int i=1;i<=n;i++)
        {
            s=getchar();
            while(s!='F' && s!='E')s=getchar();
            if(s=='E')
            {
                bz[val[top--]]=false;
                if(top<0)
                {
                    for(int j=i+1;j<=n;j++) readln();
                    pd=2; break;
                }
                continue;
            }
            while(s<'a' || s>'z') s=getchar();
            
            if(bz[s-'a'+1])
            {
                for(int j=i+1;j<=n;j++) readln();
                pd=2; break;
            }
            
            bz[val[top+1]=s-'a'+1]=true;
            int x=get(),y=get();
            if(x>y) {st[++top]=-1;continue;}
            if((x==inf && y==inf) || (x<=100 && y<=100) || st[top]<0)
            {st[top+1]=st[top];top++;}
            
            else
            {
                st[top+1]=st[top]+1;
                top++;
                if(st[top]>mx) mx=st[top];
            }
        }
        if(pd==2||top>0) {printf("ERR\n");continue;}
        if(mx==t) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
