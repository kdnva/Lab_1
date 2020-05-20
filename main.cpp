#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <clocale>

//����������

char* concatenation()
{
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    printf("������� ������ ������\n");
    scanf ("%s", first);
    printf("������� ������ ������\n");
    scanf ("%s", second);
    char* third = (char*)malloc(strlen(first)+strlen(second)+1);
    memcpy(third, first, strlen(first));
    memcpy(third+strlen(first), second, strlen(second)+1);
    printf("%s\n", third);
    free(first);
    free(second);
    free(third);
}

//��������� ���������

char* selection()
{
    char* first = (char*)malloc(sizeof(char)*512);
    int g=0;
    int i, j;
    while (g==0){
    printf("������� ������\n");
    scanf ("%s", first);
    printf("������� ������ � ����� ���������\n");
    scanf ("%i %i", &i, &j);
    if (i>j){
        int p=j;
        j=i;
        i=p;
    }
    if (((j-i+1)>strlen(first))||(i>strlen(first))||(j>strlen(first))||(strlen(first)==0))
        g=0;
    else g=1;
    if(g==0)
        printf("������! ������� ��������� ������ �/��� ������ ����� ������\n");
    }
    char* third = (char*)malloc(sizeof(char)*(j-i));
    for (int k=i; k<=j; ++k)
        *(third+k-i)=*(first+k);
 //   printf("%c", *(first+k));
    printf("%s", third);
    free (first);
    free (third);
}

//����� ���������
/*int search(char* first, char* second){
    int f=0;
    for (int i=0; i<strlen(first); ++i){
        if(*(first+i)==*(second+0)){
                char* third = (char*)malloc(strlen(second));
                memcpy(third, first+i, strlen(second));
               // printf(third);
                free(third);
                if (strcmp(third, second)!=0){
                    f=1;
                 }
        }
    }
    return(f);
}*/

int search(char* first, char* second){
    int f=0;
    for (int i=0; i<strlen(first); ++i){
        if(*(first+i)==*(second+0)){
            for (int j=1; j<strlen(second); ++j){
                if(*(first+i+j)==*(second+j))
                    f=f+1;
                else{
                    f=0;
                    break;
                }
            }
        }
    }
    return f;
}


//�������������� �����

void search_sensitive()
{
    int f;
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    int g=0;
    while (g==0){
    printf("������� ������ ������\n");
    scanf ("%s", first);
    printf("������� ������ ������\n");
    scanf ("%s", second);
    if ((strlen(first)<strlen(second))||(strlen(first)==0)||(strlen(second)==0))
        g=0;
    else g=1;
    if(g==0)
        printf("������! ����� ������� ������ ��������� ����� �������� �/��� ������� ������� ������. ������� ������ ������");}
    f=search(first, second);
    if(f==0)
        printf ("false");
    else
        printf ("true");
    free(first);
    free(second);
}

//���������������� �����

void search_insensitive()
{
    int f;
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    int g=0;
    while (g==0){
    printf("������� ������ ������\n");
    scanf ("%s", first);
    printf("������� ������ ������\n");
    scanf ("%s", second);
    first=strlwr(first);
    second=strlwr(second);
    if ((strlen(first)<strlen(second))||(strlen(first)==0)||(strlen(second)==0))
        g=0;
    else g=1;
    if(g==0)
        printf("������! ����� ������� ������ ��������� ����� �������� �/��� ������� ������� ������. ������� ������ ������");}
    f=search(first, second);
    if(f==0)
        printf ("false");
    else
        printf ("true");
    free(first);
    free(second);
}

//�����

void test(){
    int k=0;
    char* first = (char*)malloc(sizeof(char)*512);
    printf ("���� 1 \n��� ������������ ������������ ���� ����� ������� 1 \n��� ������������ ��������� ��������� �� ������ ������� 2 \n��� ������������ ��������������� � �������� ������ ��������� ������� 3 \n��� ������������ ����������������� � �������� ������ ��������� ������� 4 \n");
    scanf ("%i", &k);
    if (k==1){
        printf("��� ����� qwertyui � sdfgh ��������� ������ ���� qwertyuisdfgh \n������� ��� ������ � �������� ���������");
        concatenation();}
    if (k==2){
        printf("��� ������ qwertyuiopasd � ����� 3 � 8 ��������� ������ ���� ertyui \n������� ��� ������ � �������� ���������");
        selection();}
    if (k==3){
         printf("��� ����� qwertyui � sdfgh ��������� ������ ���� false \n������� ��� ������ � �������� ���������");
        search_sensitive();}
    if (k==4){
        printf("��� ����� qwertyui � sdfgh ��������� ������ ���� false \n������� ��� ������ � �������� ���������");
        search_insensitive();}

    printf ("���� 2 \n��� ������������ ������������ ���� ����� ������� 1 \n��� ������������ ��������� ��������� �� ������ ������� 2 \n��� ������������ ��������������� � �������� ������ ��������� ������� 3 \n��� ������������ ����������������� � �������� ������ ��������� ������� 4 \n");
    scanf ("%i", &k);
    if (k==1){
        printf("��� ����� qwerTiip � sDfgh ��������� ������ ���� qwerTiipsDfgh \n������� ��� ������ � �������� ���������");
        concatenation();}
    if (k==2){
        printf("��� ������ qwERtyuiopasd � ����� 2 � 3 ��������� ������ ���� wE \n������� ��� ������ � �������� ���������");
        selection();}
    if (k==3){
         printf("��� ����� qwERTtyui � RTyu ��������� ������ ���� true \n������� ��� ������ � �������� ���������");
        search_sensitive();}
    if (k==4){
        printf("��� ����� qwerTYUi � ErtY ��������� ������ ���� true \n������� ��� ������ � �������� ���������");
        search_insensitive();}
}

//������� �������

int main(){
    setlocale (LC_CTYPE, "rus");
    char* first = (char*)malloc(sizeof(char)*512);
    int k=10;
    while (k!=0){
        printf ("\n��� ������������ ���� ����� ������� 1 \n��� ��������� ��������� �� ������ ������� 2 \n��� ��������������� � �������� ������ ��������� ������� 3 \n��� ����������������� � �������� ������ ��������� ������� 4 \n��� ������������ ������� 5 \n��� ���������� ������� 0 \n");
        scanf ("%i", &k);
        if (k==1)
            concatenation();
        if (k==2)
            selection();
        if (k==3)
            search_sensitive();
        if (k==4)
            search_insensitive();
        if (k==5)
            test();
    }
    return 0;
}
