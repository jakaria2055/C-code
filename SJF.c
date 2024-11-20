#include<stdio.h>
#include<conio.h>

int main(){

int p[20], brust_t[20], waiting_t[20], turnaround_t[20], i, k, n, temp;
float wtavg, tatavg;

printf("Enter the number of process: ");
scanf("%d",&n);
printf("\n");

for(i=0; i<n; i++){
    p[i]=i;
    printf("Enter the process %d brust Time: ",i);
    scanf("%d",&brust_t[i]);
}


for(i=0; i<n; i++){
    for(k=i+1; k<n; k++){
       if(brust_t[i]>brust_t[k]){
        temp=brust_t[i];
        brust_t[i]=brust_t[k];
        brust_t[k]=temp;

        temp=p[i];
        p[i]=p[k];
        p[k]=temp;

       }
    }
}

waiting_t[0]= wtavg = 0;
turnaround_t[0] = tatavg = brust_t[0];

for(i=1; i<n; i++){
    waiting_t[i] = turnaround_t[i-1];
    turnaround_t[i] = waiting_t[i] + brust_t[i];
    wtavg = wtavg + waiting_t[i];
    tatavg = tatavg + turnaround_t[i];

}

 printf("\n\t PROCESS \tBRUST TIME \t WAITING TIME\t TURNAROUND TIME\n");

 for(i=0; i<n; i++){
    printf("\n\t p%d \t\t %d \t\t %d \t\t %d", p[i],brust_t[i], waiting_t[i], turnaround_t[i]);
 }

 printf("\n\n");
 printf("Average Waiting Time---> %f \n", wtavg/n);
 printf("\n");

 printf("Average Turnaround Time---> %f", tatavg/n);
 printf("\n");

 getch();
}