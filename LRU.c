#include <stdio.h>

int main() {
    int pageFaultCount = 0, pages[50], memory[20], time[20];
    int numberOfPages, numberOfFrames, counter = 0;
    int i, j, k, pos, flag1, flag2, minimum;

    puts("Enter number of frames:");
    scanf("%d", &numberOfFrames);

    puts("Enter number of pages:");
    scanf("%d", &numberOfPages);

    puts("Enter reference string:");
    for(i = 0; i < numberOfPages; i++) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < numberOfFrames; i++) {
        memory[i] = -1;
    }

    puts("The Page Replacement Process is -->");
    for(i = 0; i < numberOfPages; i++) {
        flag1 = flag2 = 0;

        // Check if page is already in memory
        for(j = 0; j < numberOfFrames; j++) {
            if(memory[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page is not in memory, find an empty frame or replace LRU
        if(flag1 == 0) {
            for(j = 0; j < numberOfFrames; j++) {
                if(memory[j] == -1) {
                    counter++;
                    pageFaultCount++;
                    memory[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // Replace the least recently used page if no empty frame
        if(flag2 == 0) {
            pos = 0;
            minimum = time[0];
            for(k = 1; k < numberOfFrames; k++) {
                if(time[k] < minimum) {
                    minimum = time[k];
                    pos = k;
                }
            }
            counter++;
            pageFaultCount++;
            memory[pos] = pages[i];
            time[pos] = counter;
        }

        // Print the current state of memory
        printf("For %d : ", pages[i]);
        if(flag1 == 1 && flag2 == 1) {
            printf("No page fault!");
        } else {
            for(j = 0; j < numberOfFrames; j++) {
                if(memory[j] != -1) {
                    printf("%d ", memory[j]);
                }
            }
        }
        printf("\n");
    }

    printf("Total no of page faults using LRU is : %d\n", pageFaultCount);
    return 0;
}
