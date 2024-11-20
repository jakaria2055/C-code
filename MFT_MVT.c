#include <stdio.h>

int main() {
    int num_blocks, num_processes, block_sizes[10], process_sizes[10];
    int i, j, allocated[10] = {0}, internal_fragmentation[10] = {0};

    printf("Enter the number of Blocks: ");
    scanf("%d", &num_blocks);

    printf("\n");
    for (i = 0; i < num_blocks; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &block_sizes[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    printf("\n");
    for (i = 0; i < num_processes; i++) {
        printf("Enter memory required for process %d: ", i + 1);
        scanf("%d", &process_sizes[i]);
    }

    printf("\n");
    printf("PROCESS\tPROCESS SIZE\tBLOCKS\tBLOCKS SIZE\tALLOCATED\tINTERNAL FRAGMENTATION\n");

    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t", i + 1, process_sizes[i]);
        for (j = 0; j < num_blocks; j++) {
            if (allocated[j] == 0 && block_sizes[j] >= process_sizes[i]) {
                allocated[j] = 1;
                internal_fragmentation[i] = block_sizes[j] - process_sizes[i];
                printf("%d\t%d\t\tYES\t\t%d\n", j + 1, block_sizes[j], internal_fragmentation[i]);
                break;
            }
        }
        if (j == num_blocks)
            printf("---\t---\t\tNO\t\t---\n");
    }

    return 0;
}

