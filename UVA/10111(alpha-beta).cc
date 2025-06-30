// link: https://www.luogu.com.cn/problem/UVA10111
// todo
# include <cstdio>

char board[4][4];


bool check_win(char player)
{
    // 可以优化，赢的时候一定和最后一个棋子有关
    bool is_win = false;
    for (int k = 0; k < 4; k++) {
        if (board[k][0] == player && board[k][1] == player && board[k][2] == player && board[k][3] == player) {
            is_win = true;
            break;
        }
        if (board[0][k] == player && board[1][k] == player && board[2][k] == player && board[3][k] == player) {
            is_win = true;
            break;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) {
        is_win = true;
    }
    if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player) {
        is_win = true;
    }

    return is_win;
}


/*
try every x take --> x win --> output
                 |-> no win --> try every o take --> o win --> 回溯上一步 x take
                                                 |-> no win --> x take --> ...
*/
void workon(char board[][4], int rows) {
    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         printf("%c", board[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '.') {
                board[i][j] = 'x'; // x take
                // check if x win

                if (xwin) {
                    printf("X\n");
                    return;
                } else {
                    // try every o take
                    for (int m = 0; m < rows; m++) {
                        for (int n = 0; n < 4; n++) {
                            if (board[m][n] == '.') {
                                board[m][n] = 'o'; // o take
                                // check if o win
                                bool owin = false;
                                for (int k = 0; k < rows; k++) {
                                    if (board[k][0] == 'o' && board[k][1] == 'o' && board[k][2] == 'o' && board[k][3] == 'o') {
                                        owin = true;
                                        break;
                                    }
                                    if (board[0][k] == 'o' && board[1][k] == '');


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
