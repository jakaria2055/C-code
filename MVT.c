#include <stdio.h>

int main() {
    int memory_size, block_size, number_of_blocks, remaining_memory, num_processes, memory_required[10], total_internal_fragmentation = 0, total_external_fragmentation = 0;
    int i, allocated_blocks = 0;

    printf("Enter the total memory available: ");
    scanf("%d", &memory_size);

    printf("Enter the block size: ");
    scanf("%d", &block_size);

    number_of_blocks = memory_size / block_size;
    remaining_memory = memory_size - number_of_blocks * block_size;

    printf("\nNumber of blocks available in memory: %d\n\n", number_of_blocks);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("\n");

    for (i = 0; i < num_processes; i++) {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &memory_required[i]);
    }

    printf("\nPROCESS\tMEMORY_REQUIRED\tALLOCATED\tINTERNAL_FRAGMENTATION\n");

    for (i = 0; i < num_processes && allocated_blocks < number_of_blocks; i++) {
        printf("%d\t\t%d", i + 1, memory_required[i]);

        if (memory_required[i] > block_size) {
            printf("\t\tNO\t\t---\n");
        } else {
            printf("\t\tYES\t\t%d\n", block_size - memory_required[i]);
            total_internal_fragmentation += block_size - memory_required[i];
            allocated_blocks++;
        }
    }

    if (i < num_processes) {
        printf("\nMemory is full, Remaining processes cannot be accommodated.\n");
    }

    total_external_fragmentation = remaining_memory;

    printf("\nTotal internal fragmentation: %d\n", total_internal_fragmentation);
    printf("Total external fragmentation: %d\n", total_external_fragmentation);

    return 0;
}

