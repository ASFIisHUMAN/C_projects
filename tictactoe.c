#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkWin(char arr[9]){
    if(
        (arr[0]==arr[1] && arr[2]==arr[0]) ||
        (arr[3]==arr[4] && arr[5]==arr[3]) ||
        (arr[6]==arr[7] && arr[8]==arr[6]) ||
        (arr[0]==arr[3] && arr[6]==arr[0]) ||
        (arr[1]==arr[4] && arr[7]==arr[1]) ||
        (arr[2]==arr[5] && arr[8]==arr[2]) ||
        (arr[0]==arr[4] && arr[8]==arr[0]) ||
        (arr[6]==arr[4] && arr[2]==arr[6])
    ) return true;
    return false;
}

void printUpdated(char arr[9]){
    
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^       ^^^^^^^^^^^Manual!^^^^^^^^^^\n");
    printf("    %c    |    %c    |    %c             (1)   |   (2)   |   (3)  \n", arr[0], arr[1], arr[2]);
    printf("---------+---------+--------       ---------+---------+--------\n");
    printf("    %c    |    %c    |    %c     <->     (4)   |   (5)   |   (6)  \n", arr[3], arr[4], arr[5]);
    printf("---------+---------+--------       ---------+---------+--------\n");
    printf("    %c    |    %c    |    %c             (7)   |   (8)   |   (9)  \n", arr[6], arr[7], arr[8]);
    printf("____________________________       ____________________________\n");
};

int valinp(){
    int a;
    printf("enter the cell ID-> ");
    scanf("%d", &a);
    printf(" \n");
    while(a>9 || a<0){
        printf("invalid id");
        printf("enter the cell ID-> ");
        scanf("%d", &a);
        printf(" \n");
    }
    if(a==0){
        printf("Quiting...\n");
        exit(0);
    }
    return a;
}

int main(){
    char arr[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char arr2[9]= {'a','b','c','d','e','f','g','h','i'};

    

    printf("\\\\       TicTacToe        //\n");
    printf("~~-------- MANUAL --------~~\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("   (1)   |   (2)   |   (3)  \n");
    printf("---------+---------+--------\n");
    printf("   (4)   |   (5)   |   (6)  \n");
    printf("---------+---------+--------\n");
    printf("   (7)   |   (8)   |   (9)  \n");
    printf("____________________________\n");
    printf("\nAbove are the cell's id number. remember it\n");

    printf("\nPlayer 1 move : X\n");
    printf("Player 1 move : 0\n");

    char player1[10],player2[10];
    printf("Enter your name(player1):  ");
    fgets(player1, sizeof(player1), stdin);
    
    printf("Enter your name(player2):  ");
    fgets(player2, sizeof(player2), stdin);

    player1[strcspn(player1, "\n")] = '\0';
    player2[strcspn(player2, "\n")] = '\0';
    printf("***[Note: enter 0 to quit instantly]***\n");
    for(int i=1; i<10; i++){
        int index;
        char cp;

        if(i>1 && i%2==0){
            printf("%s, Its your turn.\n", player2);
            cp = '0'; 
        }else{
            printf("%s, Its your turn.\n", player1);
            cp = 'X'; 
        }

        index = valinp();

        while(arr[index-1]!=' '){
            printf("~~already taken~~\n");
            index = valinp();
        }
        
        arr[index-1]=cp;
        arr2[index-1]=cp;
        
        printUpdated(arr);

        if(i>4){
            if(checkWin(arr2)){
                if(cp=='X'){
                    printf("Congratulations, %s! you've won.\n", player1);
                    printf("Sorry about %s, better luck next time...\n", player2);
                }else{
                    printf("Congratulations, %s! you've won.\n", player2);
                    printf("Sorry about %s, better luck next time...\n", player1);
                }
                return 0;
            }
        }        
    }
    printf("Its a draw, well played.\n Let's see who wins next time....\n");


    return 0;
}