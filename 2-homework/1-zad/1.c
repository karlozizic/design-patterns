#include <stdio.h>
#include <string.h>

//const void *a - generic pointer that points to any type
//(int*) is pointer to int and then we dereference to int with one more *

//base - pointer to the first element of array
//nmemb - number of elements
//size - size of one element
//compar - pointer to criteria function

const void* mymax(const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)){
    const void *maxElement = base;
    for (size_t i = 0; i < nmemb; i++) {
        if (compar(maxElement, base + i * size) == 0){
            maxElement = base + i * size;
        }
    }
    return maxElement;
}

//criteria function
//return 1 in case the first argument is greater than the second
//else 0

int gt_int(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return 1;
    }
    return 0;
}

int gt_char(const void *a, const void *b){
    if (*(char*)a > *(char*)b){
        return 1;
    }
    return 0;
}

//https://www.programiz.com/c-programming/library-function/string.h/strcmp
//strcmp for string comparison
//>0 if the first parameter is greater than the second
//0 if they are equal
//<0 else
int gt_str(const void *a, const void *b){
    int comparisonResult = strcmp(*(char**)a, *(char**)b);
    if (comparisonResult > 0){
        return 1;
    }
    return 0;
}

int main(void){
    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
            "Gle", "malu", "vocku", "poslije", "kise",
            "Puna", "je", "kapi", "pa", "ih", "njise"
    };

    int maxInt = *(int*)mymax(arr_int, sizeof(arr_int)/sizeof(int), sizeof(int), gt_int);
    printf("Najveci element u arr_int: %d\n", maxInt);

    //function strlen return number of elements in char []
    char maxChar = *(char*)mymax(arr_char, strlen(arr_char), sizeof(char), gt_char);
    printf("Najveci element u arr_char: %c\n", maxChar);

    const char* maxStr = *(char**)mymax(arr_str, sizeof(arr_str)/sizeof(char*), sizeof(char*), gt_str);
    printf("Najveci element u arr_str: %s\n", maxStr);
}