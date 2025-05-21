#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], n, i, initial, count = 0, TotalHeadMovement = 0;

    printf("Enter the number of Requests: ");
    scanf("%d", &n);

    printf("Enter the Request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    while (count != n) {
        int min = 1000, d, index;

        for (i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if (RQ[i] != 1000 && d < min) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = 1000;  // Mark as visited
        count++;
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}
