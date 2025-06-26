// link: https://www.luogu.com.cn/problem/UVA10111
// todo
# include <cstdio>


//  x take --> x win --> output
//         |-> no win --> o take --> o win --> output
//                               |-> no win --> x take --> x win --> output
//                                                     ...


void workon(char board[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }


    // output
}


int main()
{
    char op;
    // 加一个空格，跳过所有空白字符（包括换行、空格等）
    while(scanf(" %c", &op) && op == '?')
    {
        char board[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf(" %c", &board[i][j]);

        workon(board, 4);
    }

    return 0;
}
