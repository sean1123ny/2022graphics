#include <stdio.h>
int main()
{///�ɮ׫��� fout �}���ɮ�(�ɦW, write�Ҧ�)
    FILE * fout = fopen("file.txt", "w+");
     printf(     "Hello World");
    fprintf(fout,"Hello World");
    fclose(fout);///�����ɮ�

    float angle=0;
    FILE * fin = fopen("file.txt", "r");
    fscanf(fin,"%f", &angle );
    printf("Ū��F����:%f", angle);
    fclose(fin);
}
