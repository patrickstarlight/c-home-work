#include <stdio.h>
#define N 8
int top;
int chess[N][N];
typedef struct Knight {
    int  row, col;
    int d;
    int steps;
} KNIGHT;
KNIGHT stack[N * N];
void push(KNIGHT knight)
{
    stack[top] = knight;
    top++;
}
KNIGHT pop()
{
    top--;
    return(stack[top]);
}
int inChess(int row, int col)
{
if (row >= 0 && row < N && col >= 0 && col < N)
    return 1;
else
    return 0;
}
void knightMove(int row, int col)
{
    int colMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int rowMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int steps = 1, d = 0, nRow, nCol;
    KNIGHT   knight;
    chess[row][col] = steps++;
    while (steps <=N*N)
    {
        for (; d < 8; d++)
        {
            nRow = row + rowMove[d];
            nCol = col + colMove[d];
            if (inChess(nRow, nCol) && (chess[nRow][nCol] == 0))
            {
                chess[nRow][nCol] = steps;
                knight.row = row;
                knight.col = col;
                knight.d = d;
                knight.steps = steps;
                push(knight);
                d = 0;
                row = nRow;
                col = nCol;
                steps++;
                break;
            }
        }
        if (d == 8)
        {
            knight = pop();
            row = knight.row;
            col = knight.col;
            d = knight.d;
            steps = knight.steps;
            nRow = row + rowMove[d];
            nCol = col + colMove[d];
            chess[nRow][nCol] = 0;
            d++;
        }
    }
}


/*int dirs[8][2] = { {-2, 1}, {-1, 2}, {1, 2},{2, 1},{2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
int board[8][8] = { 0 };
int x, y;*/
void showboard(int board[N][N])
{
    int i;
    for (i = 0; i < N; i++)
    {
        int j;
        for (j = 0; j < N; j++)
        {
            printf("%3d", board[i][j]);
        }
        printf("\n");

    }
}

/*void move(int count,int boardx, int boardy)
{
    if (count >= 64)
        return;
    for (int i = 0; i < 8; i++)
    {
        boardx += dirs[i][0];
        boardy += dirs[i][1];
        if (boardx >= 0 && boardy < 8 && boardy >= 0 && boardx < 8 && board[boardx][boardy] == 0)
        {
            board[boardx][boardy] = count;
            move(count + 1, boardx, boardy);
        }
        boardx -= dirs[i][0];
        boardy -= dirs[i][1];
        board[boardx][boardy] = 0;
    }
    return 0;
}*/


    

int main(void)
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            chess[i][j] = 0;
    showboard(chess);
    knightMove(0, 0);
    showboard(chess);


    return 0;
}

