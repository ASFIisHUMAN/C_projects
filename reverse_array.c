#include <stdio.h>

void print_my_array(int a[], int s) {
    for (int i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void reverse_my_array(int a[], int s) {
    int temp[s];
    for (int i = 0; i < s; i++) {
        temp[i] = a[s - 1 - i];
    }
    for (int i = 0; i < s; i++) {
        a[i] = temp[i];
    }
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    print_my_array(a, 7);
    reverse_my_array(a, 7);
    print_my_array(a, 7);
    return 0;
}