#include <stdio.h>
int main()
{///檔案指標 fout 開啟檔案(檔名, write模式)
    FILE * fout = fopen("file.txt", "w+");
     printf(     "Hello World");
    fprintf(fout,"Hello World");
    fclose(fout);///關閉檔案

    float angle=0;
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin,"%f", &angle );
    printf("讀到了角度:%f", angle);
    fclose(fin);
}
