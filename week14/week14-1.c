#include <stdio.h>
int main()
{///�ɮ׫��� fout �}���ɮ�(�ɦW, write�Ҧ�)
    FILE * fout = fopen("file.txt", "w+");
     printf(     "Hello World");
    fprintf(fout,"Hello World");
    fclose(fout);///�����ɮ�
}
