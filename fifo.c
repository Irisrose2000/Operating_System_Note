#include<stdio.h>

int main()
{
    int pages[50], frames[50];
    int n, f, i, j, k = 0, found, page_fault = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1 (empty)
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page is already in frame
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frames[k] = pages[i];  // Replace the frame 
            k = (k + 1) % f;       // Circular index
            page_fault++;

            printf("%d\t", pages[i]);
            for(j = 0; j < f; j++)
            {
                if(frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("_ ");
            }
            printf("\n");
        }
        else
        {
            printf("%d\tHit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_fault);
    return 0;
}
