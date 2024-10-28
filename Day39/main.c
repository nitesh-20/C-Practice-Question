// Calculate profit or loss.
#include <stdio.h>
int main() {
    float costPrice, sellingPrice, profit, loss;

    printf("Enter the Cost Price: ");
    scanf("%f", &costPrice);
    printf("Enter the Selling Price: ");
    scanf("%f", &sellingPrice);

    if (sellingPrice > costPrice) {
        profit = sellingPrice - costPrice;
        printf("Profit: %.2f\n", profit);
    } else if (costPrice > sellingPrice) {
        loss = costPrice - sellingPrice;
        printf("Loss: %.2f\n", loss);
    } else {
        printf("No profit, no loss.\n");
    }

    return 0;
}
