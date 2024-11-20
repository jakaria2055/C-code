#include<stdio.h>

int main(){
    int p[20], brust_t[20], waiting_t[20], turnaround_t[20],priority[20], i, j, n,temp;
    float wtavg,tatavg;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("\n");

    for(i=0; i<n; i++){

        printf("Enter brust time for process p%d: ",i);
        scanf("%d", &brust_t[i]);

        printf("Enter the priority for process p%d: ",i);
        scanf("%d",&priority[i]);
        printf("\n");
        p[i]=i;
    }

    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(priority[j]>priority[j+1]){
                temp=priority[j];
                priority[j]=priority[j+1];
                priority[j+1]=temp;

                temp=brust_t[j];
                brust_t[j]=brust_t[j+1];
                brust_t[j+1]=temp;

                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }

        }
    }

    waiting_t[0]=wtavg=0;
    turnaround_t[0]=tatavg=brust_t[0];
    for(i=1; i<n; i++){
        waiting_t[i]= waiting_t[i-1] + brust_t[i-1];
        turnaround_t[i]= waiting_t[i] + brust_t[i];
        wtavg= wtavg + waiting_t[i];
        tatavg= tatavg + turnaround_t[i];
    }

    printf("\nPROCESS\t\tBURST_TIME\tWAITING_TIME\tTURNAROUND_TIME\tPRIORITY");

    for(i=0; i<n; i++){
        printf("\np%d \t\t %d\t\t %d \t\t %d \t\t %d",p[i],brust_t[i],waiting_t[i],turnaround_t[i],priority[i]);

    }

    printf("\n\n");
    printf("Average waiting time---> %f\n",wtavg/n);
    printf("Average turnaround time---> %f\n",tatavg/n);
    printf("\n");

    return 0;

}
