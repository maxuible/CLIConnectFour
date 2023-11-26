#include <stdio.h>

int printBoard(int board[]);
int sendColumn(int board[], int column);
int setUpBoardWalls(int board[]);

char *x = "[x]";
char *o = "[o]";
char *e = "[ ]";
char *w = "[█]";
char *err = "[e]";

int main(int argc, char const *argv[])
{

    int board[72] = {0};
    setUpBoardWalls(board);
    printBoard(board);

    int column = 0;
    /*while (1)
    {
        printf("What column?");
        scanf("%d", &column);
        printf("Column selected : %d\n\n", column);
        sendColumn(board, column);
        printBoard(board);
        printf("\n\n");
    }*/

    printf("What column?");
    /*scanf("%d",&column);*/
    printf("Column selected : %d\n\n", column);
    sendColumn(board, column);
    printBoard(board);
    printf("\n\n");

    sendColumn(board, column);
    printBoard(board);
    printf("\n\n");
    return 0;
}

int sendColumn(int board[], int column)
{

    column += 9;

    while (board[column] == 0)
    {
        column += 9;
    }

    board[column - 9] = 1;

    return 0;
}

int setUpBoardWalls(int board[])
{
    int i = 0;
    for (i; i < 72; i++)
    {
        /*top and bottom wall and right
        Less than 9 is top, more than 62 is bottom, mod 9 = 8 is right*/
        if (i < 9 || i > 62 || i % 9 == 8 || i % 9 == 0)
        {
            board[i] = 3;
        }
    }
}

int printBoard(int board[])
{
    int i = 0;
    for (i; i < 72; i++)
    {
        if (i % 9 == 0)
        {
            printf("\n");
        }
        if (board[i] == 3)
        {
            printf("%s", w);
        }
        /*peice handling*/
        else if (board[i] == 0)
        {
            printf("%s", e);
        }
        else if (board[i] == 1)
        {
            printf("%s", x);
        }
        else if (board[i] == 2)
        {
            printf("%s", o);
        }
        else
        {
            printf("%s", err);
        }
    }
    return 0;
}