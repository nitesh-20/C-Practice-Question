// Denomination of an Amount
#include<stdio.h>

void calcDenom(int amt){
    int denom[] = {500,200,100,50,20,10,5,2,1};
    int cnt[10]={0};

    printf("Amt: %d\n", amt);
    printf("Denoms:\n");

    for(int i=0; i<10; i++){
        if(amt >= denom[i]){
            cnt[i]= amt / denom[i];
            amt %= denom[i];
        }
        if(cnt[i]>0){
            printf("%d x %d\n",denom[i],cnt[i]);
        }
    }   
}
int main(){
    int amt;
    printf("Enter amt: ");
    scanf("%d", &amt);

    if(amt>0)
        calcDenom(amt);
    else
        printf("Enter valid amt.\n");
    
    return 0;
}