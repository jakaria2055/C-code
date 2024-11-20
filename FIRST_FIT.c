#include<stdio.h>
#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf;
    int bf[max], ff[max];

    for (i = 0; i < max; i++) {
        b[i] = 0;
        f[i] = 0;
        frag[i] = 0;
        bf[i] = 0;
        ff[i] = 0;
    }

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1 && b[j] >= f[i]) {
                ff[i] = j;
                frag[i] = b[j] - f[i];
                bf[j] = 1;
                break;
            }
        }
    }

    printf("\nFile_no \tFile_size \tBlock_no \tBlock_size \tFragment");
    for (i = 1; i <= nf; i++) {
        if (ff[i] != 0)
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("\n%d\t\t%d\t\t%s\t\t%s\t\t%s", i, f[i], "NA", "NA", "NA");
    }
}
