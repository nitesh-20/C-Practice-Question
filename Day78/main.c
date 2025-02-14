// Print “I AM IDIOT” Instead Of Your Name Using Array
#include <stdio.h>
#include <string.h>

int main() {
    char name[30] = "NITESH";

    strcpy(name, "I AM IDIOT");

    printf("%s\n", name);

    return 0;
}
