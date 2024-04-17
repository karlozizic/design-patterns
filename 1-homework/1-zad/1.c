#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaration of the PTR to VTable
typedef char const* (*PTRFUN)();

struct Animal{
    char* name;
    PTRFUN* vtable;
};

void animalPrintGreeting(struct Animal* animal){
    // index zero of vtable, as only RTTI is before in vtable
    printf("%s pozdravlja: %s\n", animal->name, animal->vtable[0]());
}

void animalPrintMenu(struct Animal* animal){
    // first index of vtable
    printf("%s voli: %s\n", animal->name, animal->vtable[1]());
}

char const* dogGreet(void){
    return "vau!";
}

char const* dogMenu(void){
    return "kuhanu govedinu";
}

PTRFUN dogVTable[2] = {dogGreet, dogMenu};

void constructDog(struct Animal* animal, char* name){
    // *strdup creates duplicate so that name variable is not used outside of function createNDogs scope
    animal->name = strdup(name);
    animal->vtable = dogVTable;
}

struct Animal* createDogUsingHeap(char* name){
    // heap memory allocation with malloc
    struct Animal* dog = (struct Animal*) malloc(sizeof(struct Animal));
    constructDog(dog, name);
    return dog;
}

void createDogUsingStack(struct Animal* dog, char* name){
    constructDog(dog, name);
}

struct Animal* createNDogs(int n){
    struct Animal* dogs = (struct Animal*) malloc(n * sizeof(struct Animal));
    for (int i = 0; i < n; ++i) {
        char name[10];
        // https://stackoverflow.com/questions/5172107/how-to-concatenate-string-and-int-in-c
        snprintf(name, sizeof(name), "pas%d", i);
        constructDog(&dogs[i], name);
    }
    return dogs;
}

char const* catGreet(void){
    return "mijau!";
}

char const* catMenu(void){
    return "konzerviranu tunjevinu";
}

PTRFUN catVTable[2] = {catGreet, catMenu};

void constructCat(struct Animal* animal, char* name){
    animal->name = name;
    animal->vtable = catVTable;
}

struct Animal* createCatUsingHeap(char* name){
    struct Animal* cat = (struct Animal*) malloc(sizeof(struct Animal));
    constructCat(cat, name);
    return cat;
}

void createCatUsingStack(struct Animal* cat, char* name){
    constructCat(cat, name);
}

void testAnimals(void){
    struct Animal* p1=createDogUsingHeap("Hamlet");
    struct Animal* p2=createCatUsingHeap("Ofelija");
    struct Animal* p3=createDogUsingHeap("Polonije");

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    free(p1);
    free(p2);
    free(p3);
}

void testAnimalsUsingStack(void){
    struct Animal p1, p2, p3;
    createDogUsingStack(&p1, "Hamlet");
    createCatUsingStack(&p2, "Ofelija");
    createDogUsingStack(&p3, "Polonije");

    animalPrintGreeting(&p1);
    animalPrintGreeting(&p2);
    animalPrintGreeting(&p3);

    animalPrintMenu(&p1);
    animalPrintMenu(&p2);
    animalPrintMenu(&p3);
}

/*
 * Heap allocation method for N dogs
 * */
void testNDogs(int n){
    struct Animal* dogs = createNDogs(n);
    for (int i = 0; i < n; ++i) {
        animalPrintGreeting(&dogs[i]);
        animalPrintMenu(&dogs[i]);
    }
    free(dogs);
}

int main(void){
    printf("-----Output using heap-----\n");
    testAnimals();
    printf("-----Repeated output using stack-----\n");
    testAnimalsUsingStack();
    int n = 5;
    printf("-----Output create %d dogs:-----\n", n);
    testNDogs(n);
}

/* Object-oriented terminology explanation
 * constructCat, constructDog - konstruktori klasa, koji se pozivaju pri stvaranju instanci klasa
 * name je atribut klase Animal (Animal.name)
 * dogGreet, dogMenu, catGreet, catMenu su metode specijaliziranih klasa - Dog : Animal, Cat : Animal
 * navedene funkcije pozivamo preko VTable-ova - radi se o virtualnim metodama
 * */