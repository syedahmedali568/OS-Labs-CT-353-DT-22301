#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], w[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    
    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Input burst time and priority for each process
    for (i = 0; i < n; i++) {
        p[i] = i + 1;    // Process numbering starts from 1
        printf("Enter the burst time and Priority of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }
    
    // Sorting processes based on priority
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap process numbers
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                // Swap priorities
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }
    
    // Calculating waiting time and turnaround time
    wtavg = w[0] = 0;
    tatavg = tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        w[i] = w[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += w[i];
        tatavg += tat[i];
    }
    
    // Printing results
    printf("\n\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++)
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", p[i], pri[i], bt[i], w[i], tat[i]);
    
    printf("\n\nAverage waiting time: %.2f", wtavg / n);
    printf("\nAverage turnaround time: %.2f\n", tatavg / n);
    
    return 0;
}