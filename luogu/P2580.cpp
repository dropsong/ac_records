#include <cstdio>

const int MAXN = 5e5+3;
char s[55];
int n,m,nex[MAXN][26],tag[MAXN],cnt=1;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int p = 1;
        for(int j=1;s[j];j++){
            int c = s[j]-'a';
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
        tag[p] = 1;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%s",s+1);
        int p = 1;
        for(int j=1;s[j];j++){
            int c = s[j]-'a';
            p=nex[p][c];
            if(!p)break;
        }
        if(tag[p]==1){
            tag[p]=2;
            puts("OK");
        }
        else if(tag[p]==2) puts("REPEAT");
        else puts("WRONG");
    }
    return 0;
}