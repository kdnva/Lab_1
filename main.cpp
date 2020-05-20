#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <clocale>

//склеивание

char* concatenation()
{
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    printf("Введите первую строку\n");
    scanf ("%s", first);
    printf("Введите вторую строку\n");
    scanf ("%s", second);
    char* third = (char*)malloc(strlen(first)+strlen(second)+1);
    memcpy(third, first, strlen(first));
    memcpy(third+strlen(first), second, strlen(second)+1);
    printf("%s\n", third);
    free(first);
    free(second);
    free(third);
}

//выделение подстроки

char* selection()
{
    char* first = (char*)malloc(sizeof(char)*512);
    int g=0;
    int i, j;
    while (g==0){
    printf("Введите строку\n");
    scanf ("%s", first);
    printf("Введите начало и конец подстроки\n");
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
        printf("Ошибка! Введите ненулевые строки и/или верные числа заново\n");
    }
    char* third = (char*)malloc(sizeof(char)*(j-i));
    for (int k=i; k<=j; ++k)
        *(third+k-i)=*(first+k);
 //   printf("%c", *(first+k));
    printf("%s", third);
    free (first);
    free (third);
}

//поиск подстроки
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


//чувствительный поиск

void search_sensitive()
{
    int f;
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    int g=0;
    while (g==0){
    printf("Введите первую строку\n");
    scanf ("%s", first);
    printf("Введите вторую строку\n");
    scanf ("%s", second);
    if ((strlen(first)<strlen(second))||(strlen(first)==0)||(strlen(second)==0))
        g=0;
    else g=1;
    if(g==0)
        printf("Ошибка! Длина искомой строки превышает длину исходной и/или введены нулевые строки. Введите строки заново");}
    f=search(first, second);
    if(f==0)
        printf ("false");
    else
        printf ("true");
    free(first);
    free(second);
}

//нечувствительный поиск

void search_insensitive()
{
    int f;
    char* first = (char*)malloc(sizeof(char)*512);
    char* second = (char*)malloc(sizeof(char)*512);
    int g=0;
    while (g==0){
    printf("Введите первую строку\n");
    scanf ("%s", first);
    printf("Введите вторую строку\n");
    scanf ("%s", second);
    first=strlwr(first);
    second=strlwr(second);
    if ((strlen(first)<strlen(second))||(strlen(first)==0)||(strlen(second)==0))
        g=0;
    else g=1;
    if(g==0)
        printf("Ошибка! Длина искомой строки превышает длину исходной и/или введены нулевые строки. Введите строки заново");}
    f=search(first, second);
    if(f==0)
        printf ("false");
    else
        printf ("true");
    free(first);
    free(second);
}

//тесты

void test(){
    int k=0;
    char* first = (char*)malloc(sizeof(char)*512);
    printf ("ТЕСТ 1 \nДля тестирования конкатенации двух строк введите 1 \nДля тестирования выделения подстроки из строки введите 2 \nДля тестирования чувствительного к регистру поиска подстроки введите 3 \nДля тестирования нечувствительного к регистру поиска подстроки введите 4 \n");
    scanf ("%i", &k);
    if (k==1){
        printf("Для строк qwertyui и sdfgh результат должен быть qwertyuisdfgh \nВведите эти данные и сравните результат");
        concatenation();}
    if (k==2){
        printf("Для строки qwertyuiopasd и чисел 3 и 8 результат должен быть ertyui \nВведите эти данные и сравните результат");
        selection();}
    if (k==3){
         printf("Для строк qwertyui и sdfgh результат должен быть false \nВведите эти данные и сравните результат");
        search_sensitive();}
    if (k==4){
        printf("Для строк qwertyui и sdfgh результат должен быть false \nВведите эти данные и сравните результат");
        search_insensitive();}

    printf ("ТЕСТ 2 \nДля тестирования конкатенации двух строк введите 1 \nДля тестирования выделения подстроки из строки введите 2 \nДля тестирования чувствительного к регистру поиска подстроки введите 3 \nДля тестирования нечувствительного к регистру поиска подстроки введите 4 \n");
    scanf ("%i", &k);
    if (k==1){
        printf("Для строк qwerTiip и sDfgh результат должен быть qwerTiipsDfgh \nВведите эти данные и сравните результат");
        concatenation();}
    if (k==2){
        printf("Для строки qwERtyuiopasd и чисел 2 и 3 результат должен быть wE \nВведите эти данные и сравните результат");
        selection();}
    if (k==3){
         printf("Для строк qwERTtyui и RTyu результат должен быть true \nВведите эти данные и сравните результат");
        search_sensitive();}
    if (k==4){
        printf("Для строк qwerTYUi и ErtY результат должен быть true \nВведите эти данные и сравните результат");
        search_insensitive();}
}

//главная функция

int main(){
    setlocale (LC_CTYPE, "rus");
    char* first = (char*)malloc(sizeof(char)*512);
    int k=10;
    while (k!=0){
        printf ("\nДля конкатенации двух строк введите 1 \nДля выделения подстроки из строки введите 2 \nДля чувствительного к регистру поиска подстроки введите 3 \nДля нечувствительного к регистру поиска подстроки введите 4 \nДля тестирования введите 5 \nДля завершения введите 0 \n");
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
