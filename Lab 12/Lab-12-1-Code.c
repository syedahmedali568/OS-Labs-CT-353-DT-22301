#include <stdio.h>
#include <stdlib.h>  // for exit()

int main() {
    int i, j, k, f, pf = 0, count = 0;
    int rs[25], m[10], n;

    // clrscr(); // Not needed in modern compilers

    printf("\nEnter the length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        m[i] = -1;  // Initialize all frames to -1
    }

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                break;  // Page hit
            }
        }

        if (k == f) {  // Page fault
            m[count++] = rs[i];
            pf++;
        }

        // Display current frame status
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-");
        }

        if (k == f)
            printf("\tPF No. %d", pf);
        
        printf("\n");

        if (count == f)
            count = 0;
    }

    printf("\nTotal Page Faults using FIFO: %d\n", pf);

    // getch(); // Not needed in modern compilers
    return 0;
}
