#include <stdio.h>
#include <conio.h>

int main() {
    int t[20], tohm[20], n, i, tot = 0;
    float avhm;

   // clrscr();
    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 1; i < n; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] *= -1;
    }

    for (i = 1; i < n; i++) {
        tot += tohm[i];
    }

    avhm = (float)tot / n;

    printf("Tracks traversed\tDifference between tracks\n");
    for (i = 1; i < n; i++) {
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    }

    printf("\nAverage header movements: %.2f", avhm);
    getch();
    return 0;
}
