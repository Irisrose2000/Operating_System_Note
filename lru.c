#include <stdio.h>
#include <stdlib.h>

#define MAX_REF 100
#define MAX_FRAME 10

int ref[MAX_REF], count, n;

void input() {
    count = 0;
    printf("Enter the number of page frames: ");
    scanf("%d", &n);
    
    printf("Enter the reference string (-1 to stop): ");
    while (1) {
        int temp;
        scanf("%d", &temp);
        if (temp == -1) break;
        ref[count++] = temp;
    }
}

void LRU() {
    int stack[MAX_FRAME], top = 0, fault = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        
        // Check if the page is already in memory
        for (int j = 0; j < top; j++) {
            if (stack[j] == ref[i]) {
                found = 1;
                // Move recently used page to the most recent position
                int temp = stack[j];
                for (int k = j; k < top - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top - 1] = temp;
                break;
            }
        }
        
        // If page not found, page fault occurs
        if (!found) {
            if (top < n) {
                stack[top++] = ref[i]; // Insert if space is available
            } else {
                // Shift left to remove the LRU page and insert new one
                for (int k = 0; k < n - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[n - 1] = ref[i];
            }
            fault++;
        }

        // Display current frame state
        printf("\nAfter inserting %d, frames: ", ref[i]);
        for (int j = 0; j < top; j++) {
            printf("%d ", stack[j]);
        }
    }
    printf("\n\nTotal page faults: %d\n", fault);
}

int main() {
    while (1) {
        int choice;
        printf("\n\n----- MENU -----");
        printf("\n1. Input Reference String");
        printf("\n2. Execute LRU Algorithm");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: input(); break;
            case 2: LRU(); break;
            case 0: return 0;
            default: printf("\nInvalid choice. Try again.");
        }
    }
}
