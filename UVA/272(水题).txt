#include<stdio.h>
int main()
{
    int c;
    bool flag=true;
    while((c=getchar())!=EOF)
    {
        if(c=='"'){
            printf("%s",flag?"``":"''");
            flag=!flag;
        }
        else 
        printf("%c",c);
    }
    return 0;
}