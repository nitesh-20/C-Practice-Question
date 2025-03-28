// use calloc function
#include<stdio.h>
#include<stdlib.h>

struct Owner{
    char name[50];
    int age;
};
struct Book{
    char name[50];
    float price;
};
int main(){
    struct Owner *owner = (struct Owner*)calloc(1,sizeof(struct Owner));
    struct Book *book = (struct Book*)calloc(1,sizeof(struct Book));
    if(owner == NULL || book == NULL){
        printf("Memory not allocated");
        exit(0);
    }
    printf("Enter Owner Details \n");
    printf("Enter Name: ");
    scanf("%s", owner->name);
    printf("Enter Age: ");
    scanf("%d", &owner->age);

    printf("Enter Book Details \n");
    printf("Enter Name: ");
    scanf("%s", book->name);
    printf("Enter Price: ");
    scanf("%f", &book->price);

    printf("Owner Details:\n ");
    printf("Name: %s\n", owner->name);
    printf("Age: %d\n", owner->age);
    printf("Book Details: \n");
    printf("Name: %s\n", book->name);
    printf("Price: %.1f \n", book->price);

    free(owner);
    free(book);
    return 0;

}