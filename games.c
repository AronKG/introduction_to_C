#include <stdio.h>
#include <stdlib.h> // standarld librery
#include <time.h>   // time control.

enum Status
{
        Continue,
        Won,
        Lost
};                  //
int rollDice(void); // point räknare
void craps(void);
void pigs(void);
void abyss(void);

void main()
{

        srand(time(NULL));

        int choice;
        do
        {

                printf("Which game would you want to play? \n");

                printf("Enter 1 for Craps \n");
                printf("Enter 2 for The Abyss \n");
                printf("Enter 3 for Pig \n");
                printf("Enter 0 to Quit \n");
                printf("Your Choice: ");
                scanf_s("%d", &choice);

                /*printf("who wants ")
                printf("P")
                printf("c")
                scanf("")*/

                switch (choice)
                {
                case 1:
                        craps();
                        break;
                case 2:
                        abyss();
                        break;
                case 3:
                        pigs();
                        break;

                case 0:
                        printf("Goodbye!\n");
                        break;
                default:
                        puts("Please enter a valid option");
                        break;
                }

        } while (choice != 0);
}

void craps()
{

        int myPoint;
        enum Status gameStatus;
        int sum = rollDice();

        switch (sum)
        {
        case 7:
        case 11:
                gameStatus = Won;
                break;
        case 2:
        case 3:
        case 12:
                gameStatus = Lost;
                break;
        default:
                gameStatus = Continue;
                myPoint = sum;
                printf("Point is %d\n", myPoint);
                break;
        }

        while (Continue == gameStatus)
        {
                sum = rollDice();

                if (sum == myPoint)
                {
                        gameStatus = Won;
                }

                else
                {
                        if (sum == 7)
                        {
                                gameStatus = Lost;
                        }
                }
        }
        if (Won == gameStatus)
        {
                puts("Player wins!\n");
        }
        else
        {
                puts("Player loses!\n");
        }
}

int rollDice(void)
{
        int die1 = 1 + (rand() % 6);
        int die2 = 1 + (rand() % 6);

        printf("Player rolled  %d + %d = %d\n", die1, die2, die1 + die2);
        return die1 + die2;
}

void abyss()
{

        int computer = 0;
        int player = 0;
        enum Status gameStatus;
        gameStatus = Continue;

        while (gameStatus == Continue)
        {

                int playerRollsDice = 1 + (rand() % 6);
                printf("players point = %d \n", player);
                printf("player dice rolled = %d \n\n", playerRollsDice);

                int computerRollsDice = 1 + (rand() % 6);
                printf("Computer point = %d \n", computer);
                printf("Computer dice rolled = %d \n\n", computerRollsDice);

                /* printf("dice results are computerRollsDice = %d, and playerRollsDice = %d  \n\n", computerRollsDice, playerRollsDice);*/

                computer = computer + computerRollsDice;
                player += playerRollsDice;

                if (computer > 26)
                {
                        computer -= computerRollsDice;
                }
                
                if (player > 26)
                {
                        player -= playerRollsDice;
                }

                if (computer == 26)
                {
                        gameStatus = Won;
                        printf("You Lost! \n\n");
                }

                if (player == 13)
                {
                        gameStatus = Lost;
                        printf("You Lost!\n\n");
                }

                 if (player == 26)
                {
                        gameStatus = Won;
                        printf("You Won! \n\n");
                }

                if (player >= 1 || player <= 12)
                {
                        if (computer == player)
                        {
                                player = 0;
                        }
                }
                
                if (player >= 14 || player <= 24)
                {
                        if (player == computer)
                        {
                                player = 14;
                        }
                }
        }
}



void pigs()

{

    int playerTotalPoint = 0;
    int computerTotalPoint = 0;
    enum Status gameStatus;
    gameStatus = Continue;
    char hold = 'n';
    char yes = 'y';
    char no = 'n';
    int playerRollsDice;
    int ComputerRollsDice;

    while (gameStatus == Continue)
    {
        if (hold != yes && hold != no)
        {
                printf ("\nInvalid value \n\n");
                playerRollsDice = 0; 
        }
        else 
        { 
        printf("\n Players total point = %d\n", playerTotalPoint);
        playerRollsDice = 1 + (rand() % 6);
        printf("Player's Dice roll = %d \n\n", playerRollsDice); 
        }
        
        hold = no;
   
        while (playerRollsDice != 1 && hold == no && playerTotalPoint < 100)
        {

            playerTotalPoint += playerRollsDice;
            printf("Players total point = %d\n", playerTotalPoint);
            printf("If you want to hold enter 'Y' else enter 'N' to roll: ");
            scanf_s(" %c", &hold, 1);
            if (hold == no ) {
                playerRollsDice = 1 + (rand() % 6);
                printf("\n Players total point = %d\n", playerTotalPoint);
                printf("Player's Dice roll = %d \n\n", playerRollsDice);
                if (playerRollsDice == 1) {
                    printf("\n Now computer's turn to roll!\n\n");
                }
            }
            else if ( hold == yes) {
                printf("\n Players total point = %d\n", playerTotalPoint);
            }
        }
        if (hold != yes && hold != no)
                continue;

        for (int i = 0; i < 2; i++)
        {
            ComputerRollsDice = 1 + (rand() % 6);
            printf("Computer's Dice roll = %d \n", ComputerRollsDice);
            if (ComputerRollsDice != 1)
            {
                computerTotalPoint += ComputerRollsDice;
                printf("Computer's total point = %d\n", computerTotalPoint);
            } else{
                printf("Computer's total point = %d\n", computerTotalPoint);
                break;
            }
        }
        if (ComputerRollsDice == 2 || ComputerRollsDice == 4 || ComputerRollsDice == 6)
        {
            ComputerRollsDice = 1 + (rand() % 6);
            if (ComputerRollsDice != 1)
            {
                computerTotalPoint += ComputerRollsDice;
            }
            printf("Computer's total point = %d\n", computerTotalPoint);
            printf("Computer's Dice roll = %d \n\n", ComputerRollsDice);
        }
        
        if (playerTotalPoint >= 100)
        {
            gameStatus = Won;
            printf("Player Wins!!\n\n");
            break;
        }

        if (computerTotalPoint >= 100)
        {
            gameStatus = Lost;
            printf("Player Lost!\n");
            break;
        }

    }

}