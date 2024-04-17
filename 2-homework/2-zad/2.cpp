#include <iostream>
#include <string.h>
#include <vector>
#include <set>

//oblikovati predlozak, odnosno template function po find_if iz stdbiblioteke
//template<class InputIterator, class UnaryPredicate>
//InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred)
//{
//    while (first!=last) {
//        if (pred(*first)) return first;
//        ++first;
//    }
//    return last;
//}

template <typename Iterator, typename Predicate> Iterator mymax(
        Iterator first,
        Iterator last,
        Predicate pred)
{
    Iterator maxElement = first;
    ++first;
    while (first != last) {
        if (pred(*maxElement, *first) == 0){
            maxElement = first;
        }
        ++first;
    }
    return maxElement;
}

int gt_int(int a, int b){
    if (a > b){
        return 1;
    }
    return 0;
}

int gt_str(const char* a, const char* b){
    int comparisonResult = strcmp(a, b);
    if (comparisonResult > 0){
        return 1;
    }
    return 0;
}


int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
const char* arr_str[] = {
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"
};

std::vector<const char*> vec_str(arr_str, arr_str + sizeof(arr_str) / sizeof(*arr_str));
std::vector<int> vec_int(arr_int, arr_int + sizeof(arr_int) / sizeof(*arr_int));

std::set<const char*> set_str(arr_str, arr_str + sizeof(arr_str) / sizeof(*arr_str));
std::set<int> set_int(arr_int, arr_int + sizeof(arr_int) / sizeof(*arr_int));

int main(){
    const int* maxint = mymax( &arr_int[0],
                               &arr_int[sizeof(arr_int)/sizeof(*arr_int)],
                               gt_int);
    std::cout <<*maxint <<"\n";

    const char **maxstr = mymax(&arr_str[0],
                                &arr_str[sizeof(arr_str)/sizeof(*arr_str)],
                                gt_str);
    std::cout <<*maxstr <<"\n";

    const char* maxvecstr = *mymax(vec_str.begin(),
                                   vec_str.end(),
                                   gt_str);
    std::cout << maxvecstr<< "\n";

    const int maxvecint = *mymax(vec_int.begin(),
                                 vec_int.end(),
                                 gt_int);
    std::cout << maxvecint<< "\n";

    const char* maxsetstr = *mymax(set_str.begin(),
                                   set_str.end(),
                                   gt_str);
    std::cout << maxsetstr<< "\n";

    const int maxsetint = *mymax(set_int.begin(),
                                 set_int.end(),
                                 gt_int);
    std::cout << maxsetint<< "\n";

}

//u prethodnom zadatku nadogradnju bez promjene postizemo delegiranjem preko pokazivaca na funkciju
//Prednosti upotrebe predlozaka
//postizemo nadogradivost s obzirom na razlicite vrste pretrazivackih spremnika (vector, set..)