///Week14-2.cpp step01-2
///�m�߶}�ɡB�g��write�B����
///�m�߶}�ɡBŪ��read�B����
#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout, "angle1 %d\n", 999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);
    printf("Ū��F�r��:%s �ξ��%d\n", line, a);
    fclose(fin);
}

