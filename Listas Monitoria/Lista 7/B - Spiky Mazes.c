#include <stdio.h>
#include <stdlib.h>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int possible = 0;

int valid(int i, int j, int n, int m);
void dfs(int x, int y, char** maze, char** path, int n, int m, int j, int J);

int main()
{
    int n, m, j;
    scanf("%d %d %d", &n, &m, &j);
    char** maze = (char**)malloc(n * sizeof(char*));
    char** path = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (char*)malloc(m * sizeof(char));
        path[i] = (char*)malloc(m * sizeof(char));
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &maze[i][j]);
            path[i][j] = 0;
        }
    }
    for (int i = 0; i < j; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '@')
            {
                dfs(i, j, maze, path, n, m, j, j);
            }
        }
    }

    if (possible)
    {
        printf("SUCCESS\n");
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

int valid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dfs(int x, int y, char** maze, char** path, int n, int m, int j, int J)
{
    path[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (valid(newx, newy, n, m) && !path[newx][newy])
        {
            if (maze[newx][newy] == '.')
            {
                dfs(newx, newy, maze, path, n, m, j, J);
                path[newx][newy] = 0;
            }
            if (maze[newx][newy] == '@')
            {
                dfs(newx, newy, maze, path, n, m, j, J);
                path[newx][newy] = 0;
            }
            if (maze[newx][newy] == 's')
            {
                dfs(newx, newy, maze, path, n, m, j, J - 1);
                path[newx][newy] = 0;
            }
            if (maze[newx][newy] == 'x')
            {
                int custo = j - J;
                if (J >= custo)
                {
                    possible = 1;
                }
                return;
            }
        }
    }
}