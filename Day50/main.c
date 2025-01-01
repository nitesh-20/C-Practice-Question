// Find A Generic Root Of the Number
#include <stdio.h>

int findGenericRoot(int num){
    while (num>=10){
        int sum = 0;
        while (num >0){
            sum += num%10;
            num /= 10;
    }
     num = sum;
    }
    return num;
}

int main(){
    int number;

    printf("Enter a muber: ");
    scanf("%d",&number);

    int genericRoot = findGenericRoot(number);
    printf("Generic root of %d is: %d\n", number, genericRoot);

    return 0;
}