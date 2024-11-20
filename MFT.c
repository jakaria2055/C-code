#include<stdio.h>
#include<conio.h>

int main(){
    int memory_s, block_s, number_of_block, ef, n, mp[10], tif=0;
    int i, p=0;

    printf("Enter the total memory availabe -->" );
    scanf("%d",&memory_s);

     printf("Enter the Block size -->" );
     scanf("%d",&block_s);

     number_of_block=memory_s/block_s;
     ef= memory_s - number_of_block*block_s;

     printf("\n Enter the number of process: ");
     scanf("%d",&n);
     printf("\n");

     for(i=0; i<n; i++){
        printf("Enter memory required for process %d: ",i+1);
        scanf("%d", &mp[i]);
     }

     printf("\n No of block available in memory -- %d ",number_of_block);
     printf("\n\n PROCESS\tMEMORY_REQUIRED\tALLOCATED\tINTERNAL_FRAGMENTATION");

     for(i=0; i<n & p<number_of_block; i++){
        printf("\n %d\t\t%d",i+1,mp[i]);

        if(mp[i]>block_s){
            printf("\t\t NO\t\t---");
        }
        else{
            printf("\t\t YES\t\t%d",block_s-mp[i]);
            tif = tif + block_s - mp[i];
            p++;
        }
     }

     if(i<n){
        printf("\n\n Memory is full, Remaining processes can not be accomodated ");
     }

        printf("\n\n Total internal Fragmentation is %d ",tif);
        printf("\n TOtal external Fragmentation is %d ",ef);



    return 0;
}

