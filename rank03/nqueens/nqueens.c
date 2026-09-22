// ftabs -> issafe -> printa -> solve -> main
#include <stdio.h>
#include <stdlib.h>

int ftabs(int n)
{
    return (n < 0 ? -n : n);
}

int issafe(int *board, int col, int row)
{
    int prev = 0;
    while(prev < col)
    {
        if(board[prev] == row)
            return (0);
        if(ftabs(board[prev] - row) == col - prev)
            return (0);
        prev++;
    }
    return (1);
}
void print_sol(int *board, int n)
{
    int i = 0;
    while(i < n)
    {
        fprintf(stdout, "%d", board[i]);
        if(i < n - 1)
            fprintf(stdout, " ");
        i++;
    }
    fprintf(stdout, "\n");
}

void solve(int *board, int col, int n)
{
    int row = 0;
    //caso base
    if(col == n)
    {
        print_sol(board, n);
        return ;
    }
    while (row < n)
    {
        if(issafe(board, col, row))
        {
            board[col] = row;
            solve(board, col + 1, n);
        }
        row++;
    }
}
int main(int argc, char **argv)
{
    int *board;
    int n;

    if (argc != 2)
        return (1);
    n = atoi(argv[1]);
    if (n <= 0)
        return (1);
    board = malloc(sizeof(int) * n);
    if (!board)
        return (1);
    solve(board, 0, n);
    free(board);
    return (0);
}