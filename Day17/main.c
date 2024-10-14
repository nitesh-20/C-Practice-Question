// The Number Is Even or Odd
#include<stdio.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    if(num % 2 ==0){
        printf("Number is even %d: ",num);
    }else{
        printf("Number is odd %d: ",num);
    }
    return 0;
}