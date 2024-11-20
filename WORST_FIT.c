#include<stdio.h>
#define max 25

void main() {
    int frag[max], block_s[max], file_s[max], i, j, number_of_block, number_of_file, temp, highest = 0;
    int bf[max], ff[max];

    for (i = 0; i < max; i++) {
        block_s[i] = 0;
        file_s[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    printf("\nEnter the number of blocks:");
    scanf("%d", &number_of_block);

    printf("Enter the number of files:");
    scanf("%d", &number_of_file);

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= number_of_block; i++) {
        printf("Block %d:", i);
        scanf("%d", &block_s[i]);
    }

    printf("Enter the size of the files:-\n");
    for (i = 1; i <= number_of_file; i++) {
        printf("File %d:", i);
        scanf("%d", &file_s[i]);
    }

    for (i = 1; i <= number_of_file; i++) {
        for (j = 1; j <= number_of_block; j++) {
            if (bf[j] != 1) {
                temp = block_s[j] - file_s[i];
                if (temp >= 0)
                    if (highest < temp) {
                        ff[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        bf[ff[i]] = 1;
        highest = 0;
    }

    printf("\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment");
    for (i = 1; i <= number_of_file; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, file_s[i], ff[i], block_s[ff[i]], frag[i]);
}

