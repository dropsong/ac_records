// Author: dropsong
// Github: https://github.com/dropsong
// https://leetcode.cn/problems/edit-distance/description/



// #include <string>
// #include <string.h>
// #include <iostream>
#define MIN(a,b) ((a)<(b)?(a):(b))
// using std::string;
// using std::cout;
// using std::endl;

char w1[505], w2[505];
int D[505][505];

class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(w1, 0, sizeof(w1));
        memset(w2, 0, sizeof(w2));
        for(int i = 0; i<505; i++)
            for(int j = 0; j< 505; j++)
                D[i][j] = 0;
        strcpy(w1+1, word1.c_str());
        strcpy(w2+1, word2.c_str());
        int len1 = word1.size();
        int len2 = word2.size();
        return dp(len1, len2);
    }

    int dp(int i, int j)
    {
        if(D[i][j]) return D[i][j];
        if(!i) 
        {
            D[i][j] = j;
            return j;
        }
        if(!j)
        {
            D[i][j] = i;
            return i;
        }

        D[i][j] = MIN(dp(i-1, j)+1, dp(i, j-1)+1);
        D[i][j] = MIN(D[i][j], dp(i-1, j-1)+((w1[i]==w2[j])?0:1));

        return D[i][j];
    }
};

// int main()
// {
//     Solution sl;
//     int ans = sl.minDistance("intention", "execution");
//     std::cout << ans << endl;
//     return 0;
// }