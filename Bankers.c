#include <stdio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input() {
    int i, j;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    
    printf("Enter the Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for(i = 0; i < r; i++) {
        scanf("%d", &avail[i]);  // Corrected indexing
    }
}

void show() {
    int i, j;
    printf("\nProcess\t Allocation\t Max\t Available\n");
    
    for(i = 0; i < n; i++) {
        printf("P%d\t ", i + 1);
        
        for(j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        
        printf("\t");
        
        for(j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        
        printf("\t");
        
        if(i == 0) {  // Available resources are printed only once
            for(j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        
        printf("\n");
    }
}

void cal() {
    int finish[100], safe[100], flag = 1;
    int i, j, k, c1 = 0;

    // Initialize finish array to 0 (not finished)
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Calculate the Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Start Safe Sequence Calculation
    while(flag) {
        flag = 0;
        
        for(i = 0; i < n; i++) {
            int canExecute = 1;
            
            if(finish[i] == 0) { // Process is unfinished
                for(j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        canExecute = 0; // Not enough resources
                        break;
                    }
                }
                
                if(canExecute) {
                    // Process can execute, release resources
                    for(k = 0; k < r; k++) {
                        avail[k] += alloc[i][k]; // Corrected index
                    }
                    
                    finish[i] = 1; // Mark process as finished
                    safe[c1++] = i; // Add to safe sequence
                    flag = 1;
                }
            }
        }
    }

    // Checking if all processes finished
    if(c1 == n) {
        printf("\nThe system is in a safe state.\nSafe Sequence: ");
        for(i = 0; i < n; i++) {
            printf("P%d ", safe[i]);
            if(i != n - 1) printf("-> ");
        }
    } else {
        printf("\nThe system is in an unsafe state (deadlock detected).");
    }
}

int main() {
    printf("-----Banker's Algorithm-----\n");
    input();
    show();
    cal();
    return 0;
}
