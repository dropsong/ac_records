#include <bits/stdc++.h>
using namespace std;

void init()
{
    priority_queue<int, vector<int>, greater<int> > heap;
    int n, c, x;
    scanf("%d", &n);
    for(register int i = 1; i <= n; i++) 
    {
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d", &x);
            heap.push(x);
        }
        else if(c == 2)
            printf("%d\n", heap.top());
        else heap.pop();
    }
}

int main()
{
    init();
    return 0;
}