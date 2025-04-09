#include<stdio.h>

void firstFit(int blockCount, int blockSize[], int processCount, int processSize[]) {
    int allocation[processCount];
    
    // Initialize all allocations to -1 (not allocated)
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Display results
    printf("Process\tSize\tBlock Allocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockCount, processCount;

    // Input block sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blockCount);
    int blockSize[blockCount];
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input process sizes
    printf("Enter the number of processes: ");
    scanf("%d", &processCount);
    int processSize[processCount];
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call First Fit function
    firstFit(blockCount, blockSize, processCount, processSize);

    return 0;
}
