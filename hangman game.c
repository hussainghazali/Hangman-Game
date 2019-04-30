#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<WINDOWS.H>

void showHangman(int);

int main()
{
	do{
	
    char Question_Word[100], temp_Word[100];
    char Guessed_Word[100];
    int num_of_lives = 6 , correct_guess = 0;

    int count = 0 , position = 0, winner, length , i;
    char alphabet_From_User;
    int score=1;

    system("cls");
    printf("\n\n Enter any word in small case and press >>ENTER<<");
    printf("\n\n\t Enter HERE =>  ");
    scanf("%s",Question_Word);
    printf("\n\n Now ask your friend to have a go ");
    printf("\n\n\t >>ENTER<<");
    getchar();
    length = strlen(Question_Word);

    system("cls");

    HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
{
SetConsoleTextAttribute(hConsole, 14);

printf(" \n\t \t \t \t \t \t$$$$$$$$$$$$$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$  $$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$    $$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$      $$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$        $$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$          $$$$$");
printf(" \n\t \t \t \t \t \t$$$$    HANG    $$$$");
printf(" \n\t \t \t \t \t \t$$$              $$$");
printf(" \n\t \t \t \t \t \t$$                $$");
printf(" \n\t \t \t \t \t \t$       MAN        $");
printf(" \n\t \t \t \t \t \t$$                $$");
printf(" \n\t \t \t \t \t \t$$$              $$$");
printf(" \n\t \t \t \t \t \t$$$$    GAME    $$$$");
printf(" \n\t \t \t \t \t \t$$$$$          $$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$        $$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$      $$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$    $$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$ $$$$$$$$$$");
printf(" \n\t \t \t \t \t \t$$$$$$$$$$$$$$$$$$$$");
}
{
SetConsoleTextAttribute(hConsole, 15);
    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 5 chances to guess the right word");
}

    getch();

    printf("\n\n\t >>ENTER<< ");

    getch();

    system("cls");
    {
    SetConsoleTextAttribute(hConsole, 14);

        printf("\n\t||===== ");
     	  printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
}
SetConsoleTextAttribute(hConsole, 15);
    printf("\n\n     The word has %d alphabets \n\n",length);
    for( i = 0; i < length ; i++)
    {
        Guessed_Word[i] = '_';
        Guessed_Word[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",Guessed_Word[i]);

    }
    while(num_of_lives != 0)
    {
        correct_guess = 0;
        SetConsoleTextAttribute(hConsole, 15);
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabet_From_User);
    if(alphabet_From_User < 'a' || alphabet_From_User > 'z')
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        correct_guess = 2;
    }
    fflush(stdin);
    if (correct_guess != 2)
    {
        for(count=0;count<length;count++)
	    {
		    if(alphabet_From_User==Question_Word[count])
		     {
		       correct_guess = 1;
                     }
            }

	   if(correct_guess == 0)
	    {
     	      printf("\n\t :( You have %d tries left ",--num_of_lives);
	          getch();
              showHangman(num_of_lives);
              getch();
	    }

	   else
	   {
	     for(count = 0; count < length; count++)
             {
     	         correct_guess = 0;
                 if(alphabet_From_User == Question_Word[count])
	          {
     		     position = count ;
     		     correct_guess = 1;
	          }
    	      if(correct_guess == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          Guessed_Word[i] = alphabet_From_User;
                      }
                      else if( Guessed_Word[i] >= 'a' && Guessed_Word[i] <= 'z' )


                      {
                          continue;
                  	  }

                      else
                      {
                          Guessed_Word[i] = '_';
                      }
                }
                temp_Word[position] = alphabet_From_User;
                temp_Word[length] = '\0';
                winner = strcmp(temp_Word,Question_Word);

                if(winner == 0)
                {
                	  SetConsoleTextAttribute(hConsole, 11);
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n \nSCORE : %d ",score++);
                    printf("\n\n\t The Word was %s ",Question_Word);
                    getch();
                    return 0;
                }
	       }
	    }
      }
     }

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",Guessed_Word[i]);
      }

    getch();
    }

      if(num_of_lives <= 0)
      {
          printf("\n\n\t The Word was %s ",Question_Word);
	      printf("\n\n\t Better luck next!!!");
	      printf("\n \nSCORE : %d ",--score);

      }
      printf("if you want to play again press key : a ");
      printf("if you want to quit press the key : s ");
getch();
return 0;
}while(getch()!='s');
}





void showHangman(int choice)
 {

    HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
{
SetConsoleTextAttribute(hConsole, 14);

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	break;
      }
      return;
 }}
