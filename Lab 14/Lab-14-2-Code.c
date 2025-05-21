#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int f[50], i, j, k, indexBlock, n, c, inde[50];

   // clrscr();
    for (i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("\nEnter index block: ");
        scanf("%d", &indexBlock);

        if (f[indexBlock] == 0) {
            f[indexBlock] = 1;

            printf("Enter number of blocks on index: ");
            scanf("%d", &n);

            printf("Enter block numbers:\n");
            for (i = 0; i < n; i++)
                scanf("%d", &inde[i]);

            int allocated = 1;

            for (i = 0; i < n; i++) {
                if (f[inde[i]] == 1) {
                    printf("Block %d is already allocated!\n", inde[i]);
                    allocated = 0;
                    break;
                }
            }

            if (allocated) {
                for (j = 0; j < n; j++)
                    f[inde[j]] = 1;

                printf("File Indexed.\n");
                for (k = 0; k < n; k++)
                    printf("%d -> %d : %d\n", indexBlock, inde[k], f[inde[k]]);
            }

        } else {
            printf("Index block already allocated!\n");
        }

        printf("Enter 1 to enter more files and 0 to exit: ");
        scanf("%d", &c);

    } while (c == 1);

    getch();
    return 0;
}
