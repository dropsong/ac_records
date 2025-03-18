#include<cstdio>
using namespace std;
int main()
{
    int c;
    bool ok=false;
    while((c=getchar())!=EOF)
    {
        if(ok)
        {
            if(c=='.')printf("1");
            if(c=='-')printf("2");
            ok=false;
        }
        else
        {
            if(c=='-')ok=true;
            if(c=='.')printf("0");
        }
    }
    return 0;
}