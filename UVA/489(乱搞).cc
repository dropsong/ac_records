#include<cstdio>
#include<string.h>
using namespace std;
char s[100],s2[100];
bool win,lose;
int len_s,len_s2,left,chance;
inline void guess(char ch)
{
    bool ok=false;
    for(int i=0;i<len_s;i++){
        if(s[i]==ch){
            left--;ok=true;
            s[i]=' ';
        }
    }
    if(!ok)chance--;
    if(!left)win=true;
    if(!chance)lose=true;
}
int main()
{
    int rnd;
    while(scanf("%d%s%s",&rnd,s,s2)==3&&rnd!=-1){
        printf("Round %d\n",rnd);
        win=false; lose=false;
        len_s=strlen(s);
        len_s2=strlen(s2);
        left=len_s;
        chance=7;
        for(int i=0;i<len_s2;i++){
            guess(s2[i]);
            if(win||lose)break;
        }
        if(win)printf("You win.\n");
        else if(lose)printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}