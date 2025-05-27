// link: https://www.luogu.com.cn/problem/UVA10111
// todo
# include <cstdio>


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
    while(scanf("%c", &op) && op == '?')
    {
        char board[4][4];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf(" %c", &board[i][j]);

        workon(board, 4);
    }

    return 0;
}
