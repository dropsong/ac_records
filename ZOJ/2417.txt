//ZOJ 2417
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n)
	{
		int i=0;
		while(!(n&(1<<(i++))));
		cout<<(1<<(i-1))<<endl;
	}	
	return 0;
} 
