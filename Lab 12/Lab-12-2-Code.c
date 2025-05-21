    #include <stdio.h>
    #include <stdlib.h>  // for exit()

    int main() {
        int i, j, k, min, rs[25], m[10], count[10], flag[25];
        int n, f, pf = 0, next = 1;

        // clrscr(); // Not used in modern compilers

        printf("Enter the length of the reference string: ");
        scanf("%d", &n);

        printf("Enter the reference string: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &rs[i]);
            flag[i] = 0;
        }

        printf("Enter the number of frames: ");
        scanf("%d", &f);

        for (i = 0; i < f; i++) {
            count[i] = 0;
            m[i] = -1;
        }

        printf("\nThe Page Replacement Process is:\n");

        for (i = 0; i < n; i++) {
            for (j = 0; j < f; j++) {
                if (m[j] == rs[i]) {
                    flag[i] = 1;
                    count[j] = next++;
                    break;
                }
            }

            if (flag[i] == 0) {
                if (i < f) {
                    m[i] = rs[i];
                    count[i] = next++;
                } else {
                    min = 0;
                    for (j = 1; j < f; j++) {
                        if (count[min] > count[j]) {
                            min = j;
                        }
                    }
                    m[min] = rs[i];
                    count[min] = next++;
                }
                pf++;
            }

            for (j = 0; j < f; j++) {
                if (m[j] != -1)
                    printf("%d\t", m[j]);
                else
                    printf("-\t");
            }

            if (flag[i] == 0)
                printf("PF No. -- %d", pf);
            printf("\n");
        }

        printf("\nTotal number of page faults using LRU: %d\n", pf);

        // getch(); // Not used in modern compilers
        return 0;   
    }
