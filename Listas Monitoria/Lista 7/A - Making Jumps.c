#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dx[8]={2,-2,2,-2,1,-1,1,-1};
int dy[8]={1,1,-1,-1,2,2,-2,-2};

void backtrack(int starti, int startj, int tempcount, int* resto, char** board, int n);

int main() {
    int n;
    int c = 0;
    scanf("%d", &n);
    while (n)
    {
        c++;
        int total = 0;
        int Y;

        char** board = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++)
        {
            int O, R;
            board[i] = (char*)malloc(10 * sizeof(char));
            scanf("%d %d", &O, &R);
            for (int j = 0; j < 10; j++)
            {
                if (j >= O && j < O + R)
                {
                    board[i][j] = 'I';
                }
                else
                {
                    board[i][j] = 'O';
                }
            }
            total += R;
            if (i == 0) {
                Y = O;
            }
        }

        int resto = 0;
        board[0][Y] = 'V';
        backtrack(0, Y, 1, &resto, board, n);

        if ((total - resto) == 1) {
            printf("Case %d, %d square can not be reached.\n", c, total - resto);
        } else {
            printf("Case %d, %d squares can not be reached.\n", c, total - resto);
        }

        for (int i = 0; i < n; i++) {
            free(board[i]);
        }
        free(board);

        scanf("%d", &n);
    }

    return 0;
}

void backtrack(int X, int Y, int tempcount, int* resto, char** board, int n)
{
    if (*resto < tempcount)
    {
        *resto = tempcount;
    }

    int tempx = X, tempy = Y;
    for (int i = 0; i < 8; ++i)
	{
        int cx = tempx + dx[i];
        int cy = tempy + dy[i];
        if (cx >= 0 && cx < n && cy >= 0 && cy < 10 && board[cx][cy] == 'I')
		{
            board[cx][cy] = 'V';
            backtrack(cx, cy, tempcount + 1, resto, board, n);
            board[cx][cy] = 'I';
        }
    }
}