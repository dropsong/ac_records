//...
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;

const int coeff[3]={2,3,5};

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    priority_queue<LL,vector<LL>,greater<LL> >qwq;
    set<LL>s;
    qwq.push(1);
    s.insert(1);
    
    for(int i=1;;i++)
    {
        LL x=qwq.top();qwq.pop();
        if(i==1500){
            
            cout<<"The 1500'th ugly number is "<<x<<'.'<<endl;
            break;
        }
        
        for(int j=0;j<3;j++)
        {
            LL x2=x*coeff[j];
            if(!s.count(x2)){
                s.insert(x2);
                qwq.push(x2);
            }
        }
    }
    
    return 0;
} 