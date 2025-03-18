#include<iostream>
#include<string>
using namespace std;
string s1,s2;

void work(string left,string right)
{
    if(left.size()>0)
    {
        char c=right[right.size()-1];
        cout<<c;
        int pos=left.find(c);
        
        work(left.substr(0,pos),right.substr(0,pos));
        work(left.substr(pos+1),right.substr(pos,left.size()-pos-1));		
    }
    
}

int main()
{
    cin>>s1>>s2;
    work(s1,s2);
    return 0;
}