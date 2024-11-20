#include <stdio.h>

int main() {
    int memory_size, block_size, number_of_blocks, remaining_memory, num_processes, memory_required[10], total_memory_allocated = 0, total_external_fragmentation = 0;
    int i;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &memory_size);

    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &memory_required[i]);

        if (total_memory_allocated + memory_required[i] > memory_size) {
            printf("Memory is Full\n");
            break;
        }

        printf("Memory is allocated for Process %d\n", i + 1);
        total_memory_allocated += memory_required[i];

        char choice;
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') break;
    }

    printf("\nTotal Memory Available – %d\n", memory_size);
    printf("PROCESS\tMEMORY-ALLOCATED\n");

    for (int j = 0; j < i; j++) {
        printf("%d\t%d\n", j + 1, memory_required[j]);
    }

    total_external_fragmentation = memory_size - total_memory_allocated;

    printf("Total Memory Allocated is %d\n", total_memory_allocated);
    printf("Total External Fragmentation is %d\n", total_external_fragmentation);

    return 0;
}
