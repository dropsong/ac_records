#include<bits/stdc++.h>
using namespace std;
char s[100005];
long j,i,num;
int main()
{
    long hua,other;
 	scanf("%c",&s[i]);
 	while(s[i]!='E')scanf("%c",&s[++i]);
  	hua=0; other=0;
    int len=strlen(s);          
    for(j=0;j<=len;j++)
    {
     	if(s[j]=='W')hua+=1;
      	if(s[j]=='L')other+=1;
      	if((((hua>=11)||(other>=11))&&(abs(hua-other)>=2))||(j==len))
      	{
        	cout<<hua<<':'<<other<<endl;
        	if((((hua>=11)||(other>=11))&&(abs(hua-other)>=2))&&(j==len))
        	printf("0:0\n");
        	hua=0; 
        	other=0;
      	}
    }
  	printf("\n");
  	hua=0; other=0;
  	for(j=0;j<=len;j++)
    {
      	if(s[j]=='W')hua+=1;
      	if(s[j]=='L')other+=1;
      	if((((hua>=21)||(other>=21))&&(abs(hua-other)>=2))||(j==len))
      	{
        	cout<<hua<<':'<<other<<endl;
        	if((((hua>=21)||(other>=21))&&(abs(hua-other)>=2))&&(j==len))
        	printf("0:0\n");
        	hua=0; 
        	other=0;
      	}
    }       
    return 0;
}