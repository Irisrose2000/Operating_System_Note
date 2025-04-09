#include <stdio.h>

void bestFit(int blockCount, int blockSize[], int processCount, int processSize[]) {
    int allocation[processCount];

    // Initialize all allocations to -1 (not allocated)
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    // Best Fit Allocation
    for (int i = 0; i < processCount; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // If found a suitable block
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display results
    printf("\nProcess\tSize\tBlock Allocated\n");
    for (int i = 0; i < processCount; i++) {
        printf("%d\t%d\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1); // Adding 1 to show block index as human-readable
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

    // Call Best Fit function
    bestFit(blockCount, blockSize, processCount, processSize);

    return 0;
}
