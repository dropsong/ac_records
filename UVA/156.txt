#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
#define HOME
#define TEST printf("a test.\n")
using namespace std;

vector<string> words;
map<string,int> cnt;

string repr(const string& s)
{
    string ans=s;
    int ans_len=ans.length();
    for(int i=0;i<ans_len;i++)
        ans[i]=tolower(ans[i]);
    
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    
    string s;
    while(cin>>s){
        if(s[0]=='#') break;
        words.push_back(s);
        string r=repr(s);
        if(!cnt.count(r)) cnt[r]=0;
        cnt[r]++;
    }
    
    vector<string> ans;
    int words_len=words.size();
    for(int i=0;i<words_len;i++)
        if(cnt[repr(words[i])]==1)
        ans.push_back(words[i]);
        
    sort(ans.begin(),ans.end());
    
    int ans_len=ans.size();
    for(int i=0;i<ans_len;i++)
        cout<<ans[i]<<endl;
    
    return 0;
}