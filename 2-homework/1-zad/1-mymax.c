#include <stdio.h>
#include <string.h>
#include <search.h>
//const void *a je genericki pokazivac na bilo koji tip podataka
//(int*) je pokazivac na int, i zatim to dereferenciramo u int sa jos jednim *

int compare_int(const void *a, const void *b){
    if (*(int*)a > *(int*)b){
        return 1;
    }
    return 0;
}

int gt_str(const void *s1, const void *s2) {
    return strcmp(*(char**)s1, *(char**)s2) > 0 ? 1 : 0;
}

int main(void){
    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
            "Gle", "malu", "vocku", "poslije", "kise",
            "Puna", "je", "kapi", "pa", "ih", "njise"
    };

    qsort(arr_int, sizeof(arr_int)/sizeof(int), sizeof(int), compare_int);
    printf("Najveci element: %d", arr_int[sizeof(arr_int)/sizeof(int)-1]);

    return 0;
}
