#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
    #include <windows.h>
    
    void setupConsole_windows(void) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            GetConsoleMode(hOut, &dwMode);
            dwMode |= 0x0004; // ENABLE_VIRTUAL_TERMINAL_PROCESSING
            SetConsoleMode(hOut, dwMode);
        }
    }
    void portable_sleep(unsigned int seconds) {
        Sleep(seconds * 1000);  // Windows uses milliseconds
    }
#else
    #include <unistd.h>
    void portable_sleep(unsigned int seconds) {
        sleep(seconds);  // POSIX uses seconds
    }
#endif

#define INITIAL_SIZE 20
#define COLOR_GREEN    "\033[1;32m"  // Bold green
#define COLOR_YELLOW   "\033[1;33m"  // Bold yellow
#define COLOR_RESET    "\033[0m"     // Normal
#define COLOR_RED      "\033[1;31m"  // Bold Red
#define COLOR_BLUE     "\033[1;34m"  // Bold Blue
#define COLOR_DIM      "\033[1;02m"  // dims
#define clearScreen() fputs("\033[2J\033[3J\033[H", stdout) // clear screen and move cursor to top

char *player1, *player2;

void printRepeatedChar(char c, unsigned char count){
    for(unsigned char i=0; i<count; i++){
        putchar(c);
    }
}

void printLongColored(char c, unsigned char count, const char* color){
    fputs(color, stdout);
    printRepeatedChar(c, count);
    fputs(COLOR_RESET, stdout);
}

void printWinningGrid(char arr[9], unsigned char win[3]) {
    clearScreen();
    putchar('\n');
    printLongColored('*', 29, COLOR_YELLOW);
    putchar('\n');
    
    for (int i = 0; i < 9; i++) {
        fputs("   ", stdout);
        // Check if this cell is winning
        
        if (i == win[0] || i == win[1] || i == win[2]){
            printf(">%s%c%s<", COLOR_GREEN, arr[i], COLOR_RESET);
        } 
        else{ 
            printf(" %s%c%s ", COLOR_DIM, arr[i], COLOR_RESET);
        }
        
        
        if(i!=8){
            if (i%3==2){
                puts("\n --------+---------+--------");
            }else{
                fputs("   |", stdout);
            }
        }
    }
    putchar('\n');
    printLongColored('~', 29, COLOR_YELLOW);
    putchar('\n');
}


// check if any player has won
bool checkWin(char arr[9], unsigned char cm){
    //***scaleable mathmatical approach***
    unsigned char row = (cm)/3;
    unsigned char col = (cm)%3;
    char wins[4][3] =
        {
            {row*3, row*3+1, row*3+2},
            {col,col+3,col+6},
            {0,4,8},
            {2,4,6}
        };
    for(unsigned char i=0; i<4; i++){
        if(i>1 && arr[cm]!=arr[4]) break; // no need to check diagonals if center is not equal to current move
        
        if(arr[wins[i][0]]==arr[wins[i][1]] && arr[wins[i][0]]==arr[wins[i][2]]){
            printWinningGrid(arr, wins[i]);
            return true;
        }
    }

    return false;
}

//prints the board

void printUpdated(char arr[9]){
    
    printRepeatedChar('^', 29);
    putchar('\n');
    for (int i = 0; i < 9; i++) {
        fputs("    ", stdout);

        if(arr[0]=='1'){
            fputs(COLOR_YELLOW, stdout);
        }
        else if (arr[i] == 'X') {
            fputs(COLOR_RED, stdout);
        } 
        else if(arr[i] == 'O') {
            fputs(COLOR_BLUE, stdout);
        }

        putchar(arr[i]);
        fputs(COLOR_RESET, stdout);
        fputs("  ", stdout);
        
        
        if(i!=8){
            if (i%3==2){
                puts("\n --------+---------+--------");
            }else{
                fputs("  |", stdout);
            }
        }
    }
    putchar('\n');
    printRepeatedChar('_', 29);
    putchar('\n');
};


void quitProgram(){
    free(player1);
    free(player2);
    puts("Quiting...");
    clearScreen();
}

//input validation
int getMove(int a, int b) {
    char buf[32];
    while (1) {
        fputs("enter the cell ID-> ", stdout);
        if (!fgets(buf, sizeof(buf), stdin)) {
            return 0; // EOF, handle as quit
        }
        // Remove newline
        buf[strcspn(buf, "\n")] = '\0';
        char *end;
        long val = strtol(buf, &end, 10);
        if (end == buf || *end != '\0') {
            puts("Invalid input. Enter a number.");
            continue;
        }

        if(val == 0) return 0;

        if (val > (a-1) && val < (b+1))
            return (int)val;
        printf("Invalid cell. Enter %d-%d or 0 to quit.", a, b);
    }
}

char* readPlayerName(const char* prompt, char* defaultName) {
    char temp[INITIAL_SIZE];
    fputs(prompt, stdout);
    if (!fgets(temp, sizeof(temp), stdin)) return NULL;
    
    if (!strchr(temp, '\n')) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    temp[strcspn(temp, "\n")] = '\0';
    if(strlen(temp) == 0) {
        strcpy(temp, defaultName);
    }
    char* name = malloc(strlen(temp) + 1);
    if (name) strcpy(name, temp);
    return name;
}

int main(){
    #ifdef _WIN32
        setupConsole_windows();  // Enable ANSI escape codes in Windows console
    #endif
    
    char arr[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    

    puts("\\\\       TicTacToe        //");
    puts("~~-------- MANUAL --------~~");
    printUpdated((char[9]){'1','2','3','4','5','6','7','8','9'});
    puts("\nAbove are the cell's id number.");
    puts("[***Remember the id numbers***]");
    puts("\n!!Hit Enter to skip name!!");
    puts("\nPlayer 1 move : X");
    puts("Player 2 move : 0");
    
    // get name of players

    player1 = readPlayerName("Enter Player 1 name: ", "Player 1");
    player2 = readPlayerName("Enter Player 2 name: ", "Player 2");
    

    printf("Player 1: %s\n", player1);
    printf("Player 2: %s\n", player2);
    
    puts("***[Note: enter 0 to quit instantly]***\n");

    printUpdated(arr);
    //Game loop
    for(int i=1; i<10; i++){
        unsigned char index;
        char cp;

        if(i>1 && i%2==0){
            printf("%s, Its your turn.\n", player2);
            cp = 'O'; 
        }else{
            printf("%s, Its your turn.\n", player1);
            cp = 'X'; 
        }

        index = getMove(1,9);

        while(index!=0 && arr[index-1]!=' '){
            printf("%s~~already taken~~%s\n", COLOR_GREEN, COLOR_RESET);
            index = getMove(1,9);
        }
        if(index==0){
            quitProgram();
            return 0;
        }
        
        arr[index-1]=cp;
        
        clearScreen();   // clear screen
        
        printUpdated(arr);

        if(i>4){
            if(checkWin(arr, index-1)){
                if(cp=='X'){
                    printf("Congratulations, %s! you've won.\n", player1);
                    printf("Sorry about %s, better luck next time...\n", player2);
                }else{
                    printf("Congratulations, %s! you've won.\n", player2);
                    printf("Sorry about %s, better luck next time...\n", player1);
                }
                portable_sleep(4);// Wait for user to see before closing the terminal
                quitProgram();
                return 0;
            }
        }        
    }
    puts("It's a draw, well played.\n Let's see who wins next time....");
    quitProgram();

    return 0;
}