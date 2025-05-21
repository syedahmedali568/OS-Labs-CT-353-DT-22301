#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int f[50], i, st, j, len, c;

    // clrscr();
    for (i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d %d", &st, &len);

        int allocated = 1;

        for (j = st; j < (st + len); j++) {
            if (f[j] == 0) {
                f[j] = 1;
                printf("\n%d -> %d", j, f[j]);
            } else {
                printf("\nBlock %d is already allocated!", j);
                allocated = 0;
                break;
            }
        }

        if (allocated)
            printf("\nThe file is allocated to disk.");

        printf("\nDo you want to enter more files? (1 = Yes / 0 = No): ");
        scanf("%d", &c);

    } while (c == 1);

    getch();
    return 0;
}
