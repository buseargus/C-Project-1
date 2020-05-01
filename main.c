#include <stdio.h>
#include <stdlib.h>

int main()
{
    int upperCase = 0;
    int lowerCase = 0;
    int punctuation = 0;
    int word = 0;
    int digit = 0;
    char s;
    FILE *file;

    if ((file = fopen("a.txt","r")) == NULL)
        printf("Dosya okumada hata var.");
    else{
        int flag = 1;
        while (!feof(file)){
            s = fgetc(file);
            if (isupper(s)) {
                upperCase++;
            } else if (islower(s)) {
                lowerCase++;
            } else if (isdigit(s)) {
                digit++;
                flag = 0;
            } else if (ispunct(s)) {
                punctuation++;
                if(flag == 1) {
                    word++;
                }
                flag = 1;

            } else if (isspace(s)) {
                if(flag == 1) {
                    word++;
                }
                flag = 1;
            }
        }

        fclose(file);
        }
    printf("Words = %d, Uppercase letters = %d, Lowercase letters = %d, Punctuation marks = %d, Numbers = %d",
           word, upperCase, lowerCase, punctuation, digit);
    return 0;
}
