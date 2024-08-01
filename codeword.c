#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Welcome to codeword world!\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1) Code\n");
        printf("2) Decode\n");
        printf("0) Exit\n");
        printf("--> ");

        int choice;
        scanf("%d", &choice);
        int keyc;
        
        // Clear the input buffer
        while (getchar() != '\n');

        if (choice == 1) {  
          printf("Enter the key: ");
          scanf("%d", &keyc);
          while (getchar() != '\n');
            char str[200];
            printf("Enter a string to code: ");
            fgets(str, 200, stdin);
            // Remove the newline character if present
            str[strcspn(str, "\n")] = '\0';
            for (int i = 0; i < strlen(str); i++) {
                str[i] = str[i] + keyc;
            }
            printf("Coded string: ");
            puts(str);
        } else if (choice == 2) {
          printf("Enter the key: ");
          scanf("%d", &keyc);
          while (getchar() != '\n');
            char dec[200];
            printf("Enter the code to decode: ");
            fgets(dec, 200, stdin);
            // Remove the newline character if present
            dec[strcspn(dec, "\n")] = '\0';
            for (int i = 0; i < strlen(dec); i++) {
                dec[i] = dec[i] - keyc;
            }
            printf("Decoded string: ");
            puts(dec);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice, Try again\n");
        }
    }

    printf("Goodbye!");
    return 0;
}