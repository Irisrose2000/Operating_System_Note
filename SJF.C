#include <stdio.h>

void sort(int b[], int p[], int n);
void compute_wt_tat(int b[], int p[], int n);

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int b[n], p[n];
    printf("Enter the burst times: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        p[i] = i + 1;
    }

    sort(b, p, n);
    compute_wt_tat(b, p, n);

    return 0;
}

// Sorting processes based on burst time (SJF)
void sort(int b[], int p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                // Swap burst time
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;

                // Swap process ID
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Compute Waiting Time (WT) & Turnaround Time (TAT)
void compute_wt_tat(int b[], int p[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    wt[0] = 0; // First process has no waiting time

    // Compute Waiting Time (WT)
    for (int i = 1; i < n; i++) { // Start from 1, not 0
        wt[i] = wt[i - 1] + b[i - 1];
        total_wt += wt[i];  // Accumulate total waiting time
    }

    // Compute Turnaround Time (TAT)
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + b[i];
        total_tat += tat[i]; // Accumulate total turnaround time
    }

    // Print results
    printf("\nProcess\tBT\tWT\tTAT");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d", p[i], b[i], wt[i], tat[i]);
    }

    // Print Total & Average Times
    printf("\nTotal Waiting Time: %d", total_wt);
    printf("\nTotal Turnaround Time: %d", total_tat);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}
