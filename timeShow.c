#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    bool isRunning = true;
    while(isRunning){
        time_t now = time(NULL);
        struct tm *local = localtime(&now);
        printf("\r%02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}