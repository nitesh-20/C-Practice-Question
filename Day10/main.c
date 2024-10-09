#include<stdio.h>
int main(){
    int num1,num2,lcm;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    lcm=(num1>num2) ? num1:num2;
    while(lcm%num1!=0 || lcm%num2!=0){
        lcm++;
    }
    printf("LCM of %d and %d is %d\n",num1,num2,lcm);
    return 0;

}