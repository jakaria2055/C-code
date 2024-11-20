#include<stdio.h>

int main() {
int p[20], brust_t[20], waiting_t[20], turnaround_t[20], i, n;
float wtavg,tatavg;

printf("Enter the number of process:");
scanf("%d",&n);
printf("\n");

for(i=0; i<n; i++){
    printf("Enter the process %d brust time: ", i);
    scanf("%d", &brust_t[i]);
}

waiting_t[0] = wtavg = 0;
turnaround_t[0] = tatavg = brust_t[0];

for(i=1; i<n; i++){
    waiting_t[i] = turnaround_t[i-1];
    turnaround_t[i] = brust_t[i]+waiting_t[i];
    wtavg = wtavg + waiting_t[i];
    tatavg = tatavg + turnaround_t[i]; 
}

printf("\nPROCESS\t\tBRUST TIME\tWAITING TIME\tTURNAROUNBD TIME");

for(i=0; i<n; i++){
    printf("\np%d \t\t %d \t\t %d \t\t %d ",i,brust_t[i],waiting_t[i],turnaround_t[i]);
}

printf("\n\n");
printf("Average Waiting time---> %f \n", wtavg/n);
printf("\n");
printf("Average Turnaround Time---> %f", tatavg/n);
printf("\n");

return 0;

}