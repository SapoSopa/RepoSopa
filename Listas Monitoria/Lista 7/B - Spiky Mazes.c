#include <stdio.h>
#include <stdbool.h>

bool possible = false;
bool path[42][42];
char maze[42][42];
int n, m, j;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int rem)
{
    path[x][y] = 1;
    for(int i = 0;i < 4; i++)
    {
        int tempX = x+dx[i];
        int tempY = y+dy[i];
        if(isValid(tempX, tempY) && !path[tempX][tempY])
        {
            if(maze[tempX][tempY] == '.')
            {
                dfs(tempX, tempY, rem);
                path[tempX][tempY] = 0;
            }
            if(maze[tempX][tempY] == '@')
            {
                dfs(tempX, tempY, rem);
                path[tempX][tempY] = 0;
            }
            if(maze[tempX][tempY] == 's')
            {
                dfs(tempX, tempY, rem-1);
                path[tempX][tempY] = 0;	
            }
            if(maze[tempX][tempY] == 'x')
            {
                int consumed = j - rem;
                if(rem >= consumed)
                {
                    possible = true;
                }
                return;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &j);
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            scanf(" %c", &maze[x][y]);
        }
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            if(maze[x][y] == '@')
            {
                for(int k = 0; k < n; k++)
                {
                    for(int l = 0; l < m; l++)
                    {
                        path[k][l] = false;
                    }
                }
                dfs(x, y, j);
            }
        }
    }
    if(possible)
    {
    	printf("SUCCESS\n");
    }
    else
    {
    	printf("IMPOSSIBLE\n");
    }

    return 0;
}