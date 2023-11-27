#include <stdio.h>

int printBoard(int board[]);
int *sendColumn(int board[], int column, int player);
int validateColumn(int board[], int column);
int setUpBoardWalls(int board[]);
int checkBoard(int *location, int player);

char *x = "[x]";
char *o = "[o]";
char *e = "[ ]";
char *w = "[█]";
char *err = "[e]";

int main(int argc, char const *argv[])
{
    int player = 1;
    int board[72] = {0};
    setUpBoardWalls(board);

    int column = 1;

    sendColumn(board, 1, 2);
    sendColumn(board, 1, 2);
    /*sendColumn(board, 1, 2);*/
    sendColumn(board, 1, 1);

    sendColumn(board, 2, 2);
    sendColumn(board, 2, 2);
    sendColumn(board, 2, 1);

    sendColumn(board, 3, 2);
    sendColumn(board, 3, 1);

    printBoard(board);

    while (1)
    {
        int valid = -1;
        while (valid)
        {
            printf("\nWhat column?");
            scanf("%d", &column);
            printf("Column selected : %d\n\n", column);
            valid = validateColumn(board, column);
        }
        int *locationOfPiece;
        locationOfPiece = sendColumn(board, column, player);
        checkBoard((int *)locationOfPiece, player);
        printBoard(board);
        if (player == 1)
        {
            player = 2;
        }
        else if (player == 2)
        {
            player = 1;
        }
    }
    printf("\n\n");

    return 0;
}
/*
@brief uses column and board params to change board
@param board
@param column
@param player
@return returns where the piece was placed
*/
int *sendColumn(int board[], int column, int player)
{
    /*move out of the wall line*/
    column += 9;

    /*check if column is not have piece*/
    if (board[column] != 0)
    {
        return;
    }

    /* "dropping" the piece , add by 9 b/c 9 columns*/
    while (board[column] == 0)
    {
        column += 9;
    }
    /*choose the piece to enter*/
    switch (player)
    {
    case 1:
        board[column - 9] = 1;
        break;
    case 2:
        board[column - 9] = 2;
        break;
    default:
        break;
    }

    return &board[column - 9];
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
        /*print new line 9 b/c 9 columns*/
        if (i % 9 == 0)
        {
            printf("\n");
        }
        /*walls*/
        if (board[i] == 3)
        {
            printf("%s", w);
        }
        /*piece handling*/
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

int validateColumn(int board[], int column)
{
    if (column < 1)
    {
        printf("Column must be above 0");
        return -1;
    }
    else if (column > 7)
    {
        printf("Column less than 8");
        return 1;
    }

    return 0;
}
/*
@brief Only need location,
@param location
@param player
@return
*/
int checkBoard(int *location, int player)
{
    int numInRow = 0;
    int *tempLocation = location;

    int checkWays[5] = {9, -1, 1, -10, 10};
    int i = 0;
    for (i; i < 5; i++)
    {
        tempLocation = location;
        numInRow = 0;
        /*if (*(tempLocation + checkWays[i]) != player){continue;}*/
        while (*(tempLocation) == player)
        {
            tempLocation = tempLocation + checkWays[i];
            numInRow++;
            if (numInRow == 4)
            {
                printf("winner %d", player);
                return 1;
            }
        }
    }

    /*VERTICAL
    check the location and all beneath, if below has same player then
    add to numInRow and check below */
    /*while (*(tempLocation) == player)
    {
        tempLocation = tempLocation + 9;
        numInRow++;
        if (numInRow == 4)
        {
            printf("winner %d",player);
            return 1;
        }
    }
    tempLocation = location;
    numInRow = 0;
    /*HORIZONTAL

    while (*tempLocation == player)
    {
        tempLocation++;
        numInRow++;
        if (numInRow == 4)
        {
            printf("winner %d",player);
            return 1;
        }
    }
    tempLocation = location;
    numInRow = 0;
    while (*tempLocation == player)
    {
        tempLocation--;
        numInRow++;
        if (numInRow == 4)
        {
            printf("winner %d",player);
            return 1;
        }
    }
    tempLocation = location;
    numInRow = 0;
    while (*tempLocation == player)
    {
        tempLocation= tempLocation + 10;
        numInRow++;
        if (numInRow == 4)
        {
            printf("winner %d",player);
            return 1;
        }
    }
    tempLocation = location;
    numInRow = 0;
    while (*tempLocation == player)
    {
        tempLocation= tempLocation - 10;
        numInRow++;
        if (numInRow == 4)
        {
            printf("winner %d",player);
            return 1;
        }
    }*/

    return 0;
}
