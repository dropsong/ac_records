#include<iostream>
using namespace std;
int nbnb(int x)
{
    if(x>=2)
    {
        return nbnb(x/2)+nbnb(x-2);
    }
    else
    return 1;
}
int main()
{
    int n;
    cin>>n;
    cout<<nbnb(n)<<endl;
    return 0;
}