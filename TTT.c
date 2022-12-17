#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* write a function here that determines whether the game will be between a 
computer vs player or player vs player will be a simple if statement that 
will lead to seperate sequences for each option. */ 


/* write a function for displaying the board as well as assigning numbers
to the open parts of the table so that inputing O's and X's are easier */

    char player;
    char change;
    int turn = 0;
    char entry[10] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9' };



/* write a function to add in the X's and O's into the respective slots that
the player and/or computer picks*/

    
    void changeEntryP1(char change){     
if(change == '1')    { entry[1] = 'X';} 
else if(change == '2')    {entry[2] = 'X';}
else if(change == '3')    {entry[3] = 'X';}   
else if(change == '4')    {entry[4] = 'X';}
else if(change == '5')    {entry[5] = 'X';}
else if(change == '6')    {entry[6] = 'X';}
else if(change == '7')    {entry[7] = 'X';}
else if(change == '8')    {entry[8] = 'X';}
else if(change == '9')    {entry[9] = 'X';}
}

    void changeEntryP2(char change){         // this will be adapted for the computer option as well
if(change == '1')    { entry[1] = 'O';} 
else if(change == '2')    {entry[2] = 'O';}
else if(change == '3')    {entry[3] = 'O';}   
else if(change == '4')    {entry[4] = 'O';}
else if(change == '5')    {entry[5] = 'O';}
else if(change == '6')    {entry[6] = 'O';}
else if(change == '7')    {entry[7] = 'O';}
else if(change == '8')    {entry[8] = 'O';}
else if(change == '9')    {entry[9] = 'O';}
}
    
int switch_turn()            // this will switch the turn
{
    //printf(" TURN %d", turn);
   if (turn  % 2 == 0) 
   {
   printf("\n It is the first players turn. \n input a entry to input value \n");
   change = getchar();
   changeEntryP1(change);
   change = getchar();
   //turn++;
   //return 1;

   }else if (turn % 2 == 1)
   {
    printf("\n It is the second players or the computers turn. \n input a entry to input value \n");
    change = getchar();
    changeEntryP2(change);   
    change = getchar();
    

    //turn++;
    //return 1;

   }

   return turn;
}

void board()
{
    printf("\n\tTic Tac Toe\n\n");

    if (player == '1'){
    printf("Player 1 (X)  -  Computer (O)\n\n\n");
    }
    else {
        printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    }

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", entry[1], entry[2], entry[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", entry[4], entry[5], entry[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", entry[7], entry[8], entry[9]);

    printf("     |     |     \n\n");
}

void opponentPlayer()
{
    printf("\n the opponent has been confirmed to be another player \n");

}

void opponentComputer()
{
    printf("\nthe opponent has been confirmed to be the computer \n");
    //switch_turn();

}

/* write a function that checks the win conditions if a row, column, or diagnal is 
filled with the same caracters */
bool WinConditions () 
{
    bool win = false;

    // rows if the entries 1,2,3     4,5,6,     7,8,9 are full of the same char that char wins
   //if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[2] == entry[3] )
        {
            win = true;
            printf ("You won the game 1");
            exit(0); 
        }
    //} else if (entry[4] != '4' ) 
    //{
                if (entry[4] == entry[5] == entry[6] )
        {
            win = true;
            printf ("You won the game 2");
            exit(0); 
        }
    //} else if (entry[7] != '7')
    //{
                if (entry[7] == entry[8] == entry[9] )
        {
            win = true;
            printf ("You won the game 3");
            exit(0);
        }
    //}
    // columns if the entries 1,4,7     2,5,8,     3,6,9 are full of the same char that char wins
      //  if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[4] == entry[7] )
        {
            win = true;
            printf ("You won the game 4"); 
            exit(0);
        }
    //} else if (entry[2] != '2' ) 
    //{
                if (entry[2] == entry[5] == entry[8] )
        {
            win = true;
            printf ("You won the game 5");
            exit(0); 
        }
    //} else if (entry[3] != '3')
    //{
                if (entry[3] == entry[6] == entry[9] )
        {
            win = true;
            printf ("You won the game 6");
            exit(0);
        }
    //}
    // diagnal if the entries 1,5,9     3,5,7 are full of the same char that char wins
      //  if (entry[1] != '1' )    
    //{
        if (entry[1] == entry[5] == entry[9] )
        {
            win = true;
            printf ("You won the game 7");
            exit(0);
        }
    //} else if (entry[3] != '3')
    //{
                if (entry[3] == entry[5] == entry[7] )
        {
            win = true;
            printf ("You won the game 8");
            exit(0);
        }
    //}

    return win; 
}

/* write a function that checks if all of the slots are filled up. if all the slots are 
filled up and none of the win conditions are met print out "draw" */

    bool Draw() 
    {
        bool entryFull = false;

        if (entry[1] != '1'&& entry[2] != '2'&& entry[3] != '3' && entry[4] != '4' &&  entry[5] != '5' && entry[6] != '6' && entry[7] != '7' && entry[8] != '8' && entry[9] != '9')
        {
            entryFull = true;
            printf ("\n the game is a draw");
            exit(0);
        }  


        if (entryFull = true)
        {   
        WinConditions();
        }
    }


/*write a algorithym for the computer to check if a spot is empty and input a move
if that spot is empty otherwise find an open spot and input. */

/*write a function to switch the turn from P to P and from C to P*/


/*end program*/

 int main()
{    
    printf ("Enter your choice of opponent \n 1 for a computer \n 2 for another player ");

    player = getchar();
    if(player == '1' ) {
        opponentComputer();
    }
    if(player == '2' ) {
        opponentPlayer();
    
                board();
        while 
            (WinConditions() == false && Draw() == false)
        {
            switch_turn();
            board(); 
            WinConditions();
            Draw();
            turn++;

            printf ("\n The game is on its  %d turn \n", turn - 1 );
        
        }
            printf ("this is the end of the game");
    
            exit(0);
    }
}          