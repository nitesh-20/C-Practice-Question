// Delete an element from an array at the specified position.
#include<stdio.h>

int main(){
    int arr[100],n,pos,i;

    printf("enter number of elements in array: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter position to delete (1 to %d): ",n);
    scanf("%d",&pos);

    if(pos<1 || pos>n){
        printf("Invalid position\n");
    } else{
        for(i=pos-1; i<n-1; i++){
            arr[i] = arr[i+1];
        }
        n--;

        printf("Updated array: ");
        for(i=0; i<n; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
        return 0;
    
}
