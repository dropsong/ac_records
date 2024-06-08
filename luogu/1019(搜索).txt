#include<bits/stdc++.h>
using namespace std;
string word[21],start;
bool vis[21][2];
int n,dragon_len;
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      cin>>word[i];
    cin>>start;
}
void dfs(int now_len,string s)
{
    int s_len=s.size();
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(vis[i][1]==true)continue;
        bool ok=true;
        for(int j=0;j<s_len;j++)
        {
            if(word[i][j]!=s[j])
            {
                ok=false; break;
            }
        }
        if(ok)
        {
            flag=true;
            bool OK=false;
            if(vis[i][0])vis[i][1]=true;
            else 
            {
                vis[i][0]=true;
                OK=true;
            }
            int word_len=word[i].size();
            for(int k=1;k<=word_len-1;k++)
            {
                dfs(now_len+word_len-s_len,word[i].substr(k,word_len-k));
            }
            vis[i][1]=false;
            if(OK)vis[i][0]=false;
        }		
    }
    if(flag==false)
    {
        if(now_len>dragon_len)
        dragon_len=now_len;
        return;
    }
}
int main()
{
    input();
    dfs(1,start);
    cout<<dragon_len;
    return 0;
}