#include <stdio.h>
#include <stdlib.h>

int main()
{
    int buyukHarfler = 0;
    int kucukHarfler = 0;
    int noktalama = 0;
    int kelimeler = 0;
    int sayilar = 0;
    char s;
    FILE *dosya;

    if ((dosya = fopen("a.txt","r")) == NULL)
        printf("Dosya okumada hata var.");
    else{
        int flag = 1;
        while (!feof(dosya)){
            s = fgetc(dosya);
            if (isupper(s)) {
                buyukHarfler++;
            } else if (islower(s)) {
                kucukHarfler++;
            } else if (isdigit(s)) {
                sayilar++;
                flag = 0;
            } else if (ispunct(s)) {
                noktalama++;
                if(flag == 1) {
                    kelimeler++;
                }
                flag = 1;

            } else if (isspace(s)) {
                if(flag == 1) {
                    kelimeler++;
                }
                flag = 1;
            }
        }

        fclose(dosya);
        }
    printf("Kelime sayisi = %d, buyuk harf sayisi = %d, kucuk harf sayisi = %d, noktalama isareti sayisi = %d, rakam sayisi = %d",
           kelimeler, buyukHarfler, kucukHarfler, noktalama, sayilar);
    return 0;
}
