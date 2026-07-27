#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// guess the number game
void gsGame()
{
    printf("Wellcomed to the guess the number game!\n");
    while (1)
    {
        srand(time(NULL));
        int random_num = (rand() % 100) + 1;
        int nums = 0;
        int b = 0;
        int guess;

        printf("Guess a number between 1 and 100:");

        while (!b)
        {

            scanf("%d", &guess);
            if (guess > random_num)
            {
                printf("Too high, try again: ");
            }
            else if (guess < random_num)
            {
                printf("Too low, try again: ");
            }
            else
            {
                printf("You got it!");
                b = 1;
            }
            nums++;
        };
        printf("You guessed in %d times\n", nums);
        printf("Nice try\n");
        printf("Would you like to play again? (y/n): ");
        char again;
        scanf(" %c", &again);
        if (again == 'y')
            printf("New game :\n");
        else
            break;
    }
}

// code word

void codeWordworld()
{
    printf("Welcome to codeword world!\n");

    while (1)
    {
        printf("Enter your choice:\n");
        printf("1) Code\n");
        printf("2) Decode\n");
        printf("0) Exit\n");
        printf("--> ");

        int choice;
        scanf("%d", &choice);
        int keyc;

        // Clear the input buffer
        while (getchar() != '\n')
            ;

        if (choice == 1)
        {
            printf("Enter the key: ");
            scanf("%d", &keyc);
            while (getchar() != '\n')
                ;
            char str[200];
            printf("Enter a text to code: ");
            fgets(str, 200, stdin);
            // Remove the newline character if present
            str[strcspn(str, "\n")] = '\0';
            for (int i = 0; i < strlen(str); i++)
            {
                str[i] = str[i] + keyc;
            }
            printf("Coded string: ");
            puts(str);
        }
        else if (choice == 2)
        {
            printf("Enter the key: ");
            scanf("%d", &keyc);
            while (getchar() != '\n')
                ;
            char dec[200];
            printf("Enter the code to decode: ");
            fgets(dec, 200, stdin);
            // Remove the newline character if present
            dec[strcspn(dec, "\n")] = '\0';
            for (int i = 0; i < strlen(dec); i++)
            {
                dec[i] = dec[i] - keyc;
            }
            printf("Decoded string: ");
            puts(dec);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("Invalid choice, Try again\n");
        }
    }

    printf("Goodbye!\n\n");
}

// rock paper scizor game

void run_rps()
{
    int inp, win = 0, lose = 0, tie = 0, life = 3, score = 0;
    while (1)
    {
        int randnum = (rand() % 3) + 1;
        printf("Enter your choice: ");
        scanf("%d", &inp);
        if (inp == 0)
        {
            printf("Game over!");
            break;
        }
        else if (inp == 1 || inp == 2 || inp == 3)
        {
            if (inp == 1)
                printf("You chose rock.\n");
            if (inp == 2)
                printf("You chose paper.\n");
            if (inp == 3)
                printf("You chose scissor.\n");
            if (randnum == 1)
                printf("Computer chose rock.\n");
            if (randnum == 2)
                printf("Computer chose paper.\n");
            if (randnum == 3)
                printf("Computer chose scissor.\n");
            if (inp == randnum)
            {
                tie++;
                printf("It's a tie!\n\n");
            }
            else if ((inp == 1 && randnum == 3) || (inp == 2 && randnum == 1) || (inp == 3 && randnum == 2))
            {
                win++;
                printf("You win!\n\n");
                if (win >= 4 && win % 4 == 0)
                {
                    life++;
                    printf("you gaind a life! Total lives: %d\n", life);
                };
            }
            else if ((inp == 3 && randnum == 1) || (inp == 1 && randnum == 2) || (inp == 2 && randnum == 3))
            {
                lose++;
                life--;
                printf("You lose!\n");
                printf("You have %d life left!\n\n", life);
                if (life == 0)
                {
                    score = ((win * 2) + tie - lose) * 100;
                    break;
                };
            };

            score = ((win * 2) + tie - lose) * 100;
            if (score >= 500 && score % 500 == 0)
                printf("Congratulation You score %d points.\n", score);
        }
        else
        {
            printf("Invalid choice, Try again\n");
        }
    }
    printf("Game over!!!\n");
    printf("Your score : %d\n", score);
    printf("Win=%d tie=%d lose=%d\n", win, tie, lose);
    if (score > 0)
        printf("Your win rate : %.2f Percent\n", ((win * 100.0) / (win + tie + lose)));
    else
        printf("Your win rate : 0 Percent\n");
}

void rpsgame()
{
    srand(time(NULL));

    printf("Welcome to rock paper scissor game!\n");
    printf("You have 3 lives, if you lose all life, the game is over!\n but You cain gain life by winning every 4 times.\nEvery win gives you 200 points, tie 100 and lose takes 100 points.\n");
    printf("guide:\n");

    run_rps();
    char againc;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &againc);
    if (againc == 'y' || againc == 'Y')
        run_rps();
    else
        printf("Thanks for playing!\n\n");
}

int main(void)
{
    printf("Hello we have 2 games and 1 code-word genarat.\n");
    printf("1) Guess the number game.\n");
    printf("2) Rock, Paper, Scissor game\n");
    printf("3) code and decoder\n");
    printf("0) To Exit\n");
    while (1)
    {
        printf("Enter the game number you want to play :");
        int choose;
        scanf("%d", &choose);
        if (choose == 1)
            gsGame();
        else if (choose == 2)
            rpsgame();
        else if (choose == 3)
            codeWordworld();
        else if (choose == 0)
            break;
        else
            printf("Sorry, But there is no choice like %d\n", choose);
    }
    printf("Thanks for playing!");
    return 0;
}
