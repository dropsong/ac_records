// link: https://www.luogu.com.cn/problem/UVA10111
// 相关资料见同目录下的 10111.md

# include <cstdio>
# include <algorithm>


inline bool check(char board[][4], char player)
{
    // 可以优化？赢的时候一定和最后一个棋子有关
    for (int k = 0; k < 4; k++) {
        if (board[k][0] == player && board[k][1] == player && board[k][2] == player && board[k][3] == player) {
            return true;
        }
        if (board[0][k] == player && board[1][k] == player && board[2][k] == player && board[3][k] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) {
        return true;
    }
    if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player) {
        return true;
    }

    return false;
}


// 是否平局。棋盘满了还没分出胜负，就说明平局
inline bool is_full(char board[][4], int rows=4)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == '.')
                return false;
    return true;
}


int alpha_beta(char board[][4], int alpha, int beta, bool is_max)
{
    // 先判断胜负，因为棋盘满了也可能有一方获胜
    if(check(board,'x')) return 1;   //我方获胜
    if(check(board,'o')) return -1;  //敌方获胜
    if(is_full(board)) return 0;             //平局

    if(is_max){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(board[i][j] == '.'){
                    board[i][j] = 'x'; // 落子
                    alpha = std::max(alpha, alpha_beta(board, alpha, beta, false));
                    board[i][j] = '.'; // 回溯
                    if(alpha >= beta) break;
		        }
	        }
            if(alpha >= beta) break;
        }
        return alpha;
    } else {
  	    for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
  	            if(board[i][j] == '.'){
                    board[i][j] = 'o'; // 落子
                    beta = std::min(beta, alpha_beta(board, alpha, beta, true));
                    board[i][j] = '.'; // 回溯
                    if(alpha >= beta) break;
		        }
	        }
            if(alpha >= beta) break;
        }
        return beta;
    }
}


void workon(char board[][4], int rows = 4)
{
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(board[i][j]=='.') { //枚举可以落子的点 
                char T[4][4];
                for(int x=0;x<4;x++) for(int y=0;y<4;y++)T[x][y]=board[x][y];
	            T[i][j]='x';

                if(check(T,'x')) {
                    printf("(%d,%d)\n", i, j);
                    return;
                }

	            if(alpha_beta(T,-2,2,false)==1){
                    printf("(%d,%d)\n", i, j);
                    return;
                }   
	        }
	    }
    }
    printf("#####\n");
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
