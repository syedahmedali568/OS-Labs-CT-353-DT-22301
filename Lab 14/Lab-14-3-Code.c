#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int f[50], p, i, j, a, st, len, k, c;

    //clrscr();
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    do {
        printf("\nEnter the starting index block and length: ");
        scanf("%d %d", &st, &len);

        k = len;

        for (j = st; j < (st + k); j++) {
            if (f[j] == 0) {
                f[j] = 1;
                printf("\n%d -> %d", j, f[j]);
            } else {
                printf("\n%d -> Block is already allocated", j);
                k++;
            }
        }

        printf("\nDo you want to enter one more file? (1 = Yes / 0 = No): ");
        scanf("%d", &c);

    } while (c == 1);

    getch();
    return 0;
}
