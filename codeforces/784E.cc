#include <iostream>
using namespace std;
int main()
{
    bool iIn1, iIn2, iIn3, iIn4,iAns;
    cin>>iIn1>>iIn2>>iIn3>>iIn4;
    iAns=((iIn1^iIn2)&(iIn3|iIn4))^((iIn2&iIn3)|(iIn1^iIn4));
    cout << int(iAns);
    return 0; 
}
