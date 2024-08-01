 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  srand(time(NULL));
  int random_num = (rand() % 100) + 1;
  int nums=0;
  int b=0;
  int guess;
  printf("Guess a number between 1 and 100:");

  while(!b){
    
    scanf("%d", &guess);
    if(guess>random_num){
      printf("Too high, try again: ");
    }else if(guess<random_num){
      printf("Too low, try again: ");
    }else{
      printf("You got it!");
      b=1;
    }
    nums++;
  };
  printf("You guessed in %d times", nums);
  return 0;
} 