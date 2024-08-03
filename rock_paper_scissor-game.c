#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
  int inp, win=0, lose=0, tie=0,life=3, score=0;
  printf("Welcome to rock paper scissor game!\n");
  printf("You have 3 lives, if you lose all life, the game is over!\n but You cain gain life by winning every 4 times.\nEvery win gives you 200 points, tie 100 and lose takes 100 points.\n");
  printf("guide:\n");
  printf("1) Rock\n");
  printf("2) Paper\n");
  printf("3) Scissor\n");
  printf("0) Quit the game\n");
  while (1){
  int randnum = (rand() % 3) + 1;
      printf("Enter your choice: ");
      scanf("%d", &inp);
      if (inp == 0){
        printf("Game over!");
        break;
      }else if(inp==1||inp==2||inp==3){
      if (inp == 1)printf("You chose rock.\n");
      if (inp == 2)printf("You chose paper.\n");
      if (inp == 3)printf("You chose scissor.\n");
      if (randnum == 1)printf("Computer chose rock.\n");
      if (randnum == 2)printf("Computer chose paper.\n");
      if (randnum == 3)printf("Computer chose scissor.\n");
      if (inp == randnum){
          tie++;
          printf("It's a tie!\n\n");
      }else if((inp==1 && randnum==3)||(inp==2 && randnum==1)||(inp==3 && randnum==2)){
          win++;
          printf("You win!\n\n");
          if(win>=4 && win%4==0){life++;printf("you gaind a life! Total lives: %d\n",life);};
      }else if((inp==3 && randnum==1)||(inp==1 && randnum==2)||(inp==2 && randnum==3)){
          lose++;
          life--;
          printf("You lose!\n");
          printf("You have %d life left!\n\n",life);
          if(life==0){
              score=((win*2)+tie-lose)*100;
              break;
          };
      };

      
      
      score=((win*2)+tie-lose)*100;
      if(score>=500 && score%500==0)printf("Congratulation You score %d points.\n",score);
      }else{
          printf("Invalid choice, Try again\n");
      }
  }
    printf("Game over!!!\n");
    printf("Your score : %d\n",score);
    printf("Win=%d tie=%d lose=%d\n",win,tie,lose);
    if(score>0)printf("Your win rate : %.2f Percent\n",((win*100.0)/(win+tie+lose)));
 return 0;
}
