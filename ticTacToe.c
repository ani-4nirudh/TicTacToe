#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 'X'
#define COMPUTER 'O'

char board[3][3];
char winner;

void reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printCurrentBoard()
{
    printf("%c  | %c  | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|----|---\n");
    printf("%c  | %c  | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|----|---\n");
    printf("%c  | %c  | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

int checkSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;
}

void printTheWinner(char winner)
{
    if (winner == 'X')
    {
        printf("You won!\n");
    } else if (winner == 'O')
    {
        printf("Computer won! You lose!\n");
    } else
    {
        printf("It's a tie!\n");
    }
}

char checkTheWinner()
{
    // check the rows
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
        {
            return (board[i][0]);
        }
    }

    // check the coulmns
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
        {
            return (board[0][i]);
        }
    }

    // check the diagonals
    if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
    {
        return (board[1][1]);
    } else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        return (board[1][1]);
    }

    return ' ';
}

void playerTurn()
{
    int x, y;
    
    do
        {
            printf("Enter Row Number (1 - 3): ");
            scanf("%d", &x);
            getchar();
            printf("Enter Coulmn Number (1 - 3): ");
            scanf("%d", &y);
            x--;
            y--;
            if (board[x][y] == ' ')
            {
                board[x][y] = PLAYER;
                break;
            } else
            {
                printf("Incorrect Choice! Try again! \n");
            }
        } while(board[x][y] != ' ');
}

void computerTurn()
{
    int x, y;
    srandom((unsigned)time(NULL));
    do
        {
            x = random() % 3;
            y = random() % 3;
            if (board[x][y] == ' ')
            {
                board[x][y] = COMPUTER;
                break;
            }
        } while(board[x][y] != ' ');
}

int main()
{
    reset();
    winner = ' ';

    while(checkSpaces() > 0 && winner == ' ')
    {
        printCurrentBoard();
        
        playerTurn();
        winner = checkTheWinner();
        if (winner != ' ' || checkSpaces() == 0)
        {
            break;
        }

        computerTurn();
        winner = checkTheWinner();
        if (winner != ' ' || checkSpaces() == 0)
        {
            break;
        }
    }

    printCurrentBoard();
    printTheWinner(winner);
    
    return 0;
}