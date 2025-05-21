#include <stdio.h>
#include <conio.h>

int main() {
    int t[20], atr[20], d[20], h, i, j, n, temp, k, p = 0, sum = 0;

    //clrscr();
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;         // Start from 0
    t[1] = h;         // Current head position

    printf("Enter the track numbers:\n");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the tracks
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find head index
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }

    // Traverse left of head
    while (t[j] != 0) {
        atr[p++] = t[j--];
    }
    atr[p++] = t[j]; // add 0

    // Traverse right of head
    for (i = k + 1; i < n + 2; i++) {
        atr[p++] = t[i];
    }

    // Calculate distances
    for (i = 0; i < n + 1; i++) {
        if (atr[i] > atr[i + 1])
            d[i] = atr[i] - atr[i + 1];
        else
            d[i] = atr[i + 1] - atr[i];
        sum += d[i];
    }

    printf("\nAverage header movements: %.2f\n", (float)sum / n);
    getch();
    return 0;
}
