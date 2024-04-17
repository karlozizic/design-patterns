#include <stdio.h>
#include <stdlib.h>
// forward declaration of Unary_Function as we are using struct in PTRFUN typedef
struct Unary_Function;
typedef double (*PTRFUN)(struct Unary_Function*, double);

struct Unary_Function{
    int lower_bound;
    int upper_bound;
    PTRFUN* vtable;
};

double value_at(struct Unary_Function* uf, double x){
    return 0;
}

double negative_value_at(struct Unary_Function* uf, double x){
    return (-1) * uf->vtable[0](uf, x);
}

struct Square{
    struct Unary_Function uf;
    //vtable is declared outside of struct
};

double squareValueAt(struct Unary_Function* uf, double x){
    return x*x;
}

PTRFUN SquareVTable[2] = {squareValueAt, negative_value_at};


struct Linear {
    struct Unary_Function uf;
    double a;
    double b;
    //vtable is declared outside of struct
};

double linearValueAt(struct Unary_Function* uf, double x){
    struct Linear* l = (struct Linear*) uf;
    return l->a*x + l->b;
}

PTRFUN LinearVTable[2] = {linearValueAt, negative_value_at};

void tabulate(struct Unary_Function* uf){
    for(int x = uf->lower_bound; x <= uf->upper_bound; x++) {
        printf("f(%d)=%lf\n", x, uf->vtable[0](uf, x));
    }
}


void initialize_Square(struct Square* s, int lb, int ub){
    s->uf.lower_bound = lb;
    s->uf.upper_bound = ub;
    s->uf.vtable = SquareVTable;
}

void initialize_Linear(struct Linear* l, int lb, int ub, double a, double b){
    l->uf.lower_bound = lb;
    l->uf.upper_bound = ub;
    l->uf.vtable = LinearVTable;
    l->a = a;
    l->b = b;
}

int same_functions_for_ints(struct Unary_Function* uf1, struct Unary_Function* uf2,
                            double tolerance, PTRFUN value_at){
    if(uf1->lower_bound != uf2->lower_bound) return 0;
    if(uf1->upper_bound != uf2->upper_bound) return 0;
    for(int x = uf1->lower_bound; x <= uf1->upper_bound; x++) {
        double a = uf1->vtable[0](uf1, x);
        double b = uf2->vtable[0](uf2, x);
        double delta = a - b;
        if(delta < 0) delta = - delta;
        if(delta > tolerance) return 0;
    }
    return 1;
}

int main(void){
    printf("-----Square tabulate-----\n");
    struct Unary_Function* f1 = (struct Unary_Function*) malloc(sizeof(struct Square));
    initialize_Square((struct Square*) f1, -2, 2);
    tabulate(f1);
    printf("-----Linear tabulate-----\n");
    struct Unary_Function* f2 = (struct Unary_Function*) malloc(sizeof(struct Linear));
    initialize_Linear((struct Linear*) f2, -2, 2, 5, -2);
    tabulate(f2);
    printf("f1==f2: %s\n", same_functions_for_ints(f1, f2, 1E-6, value_at) ? "DA" : "NE");
    printf("neg_val f2(1) = %lf\n", f2->vtable[1](f2, 1.0));
    //free heap memory
    free(f1);
    free(f2);
}