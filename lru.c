#include <stdio.h>

int main() {
    int pages[50], frames[50], usage[50];
    int n, f, i, j, lru_index, found;
    int time = 0, page_fault = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames and usage
    for (i = 0; i < f; i++) {
        frames[i] = -1;
        usage[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++) {
        found = 0;

        // Check if the page is already in the frame
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                usage[j] = time++;  // Update usage time
                break;
            }
        }

        // If page is not found, insert it
        if (!found) {
            // Find LRU index (least recently used)
            lru_index = 0;
            for (j = 1; j < f; j++) {
                if (usage[j] < usage[lru_index]) {
                    lru_index = j;
                }
            }

            frames[lru_index] = pages[i];
            usage[lru_index] = time++;
            page_fault++;

            printf("%d\t", pages[i]);
            for (j = 0; j < f; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("_ ");
            }
            printf("\n");
        } else {
            printf("%d\tHit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_fault);
    return 0;
}
