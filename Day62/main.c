// Remove All Vowels From A String
#include <stdio.h>
#include<string.h>

void removeVowels (char str[]){
    char result[100];
    int j = 0;

    for(int i = 0; str[i] !='\0'; i++){
        switch (str[i]){
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
            break;
            default:

            result[j++] = str[i];
        }
    }
    result[j]='\0';
    printf("string without vowels: %s\n",result);
}
int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str,"\n")] = '\0';

    removeVowels(str);
    return 0;
}