#include<stdio.h>
int main(){
    int a,b;

    printf("Enter Two Number: ");
    scanf("%d %d", &a, &b);

    if(a>b){
        printf("%d is Maxmium number",a);
    }
    else if(b>a){
        printf("%d is Minimum number ",b);
    }
    else{
        printf("Both numbers are equal");
    }
    return 0;
}