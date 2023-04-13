#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct OE_ {
    int x;
    struct OE_ *sljedeci;
}OE;

int main(){

    OE *prvi = NULL;
    int N = 100000;
    int* V = (int*)malloc(N * sizeof(int));
    int dg = 10;
    int gg = 100;
    int target = 102;
    time_t t1, t2, t3, t4, t5, t6, t7, t8;

    t1 = clock();
    for (int i = 0; i < N; i++) {
        V[i] = dg + ((float)rand() / RAND_MAX) * (gg - dg);;
    }
    t2 = clock();
    printf("Vrijeme formiranja niza je %dms\n", t2-t1);

    t3 = clock();
    for (int i = N - 1; i >= 0; i--) {
        OE* newNode = (OE*)malloc(sizeof(OE));
        newNode->x = V[i];
        newNode->sljedeci = prvi;
        prvi = newNode;
    }
    t4 = clock();
    printf("Vrijeme formiranja PP je %dms\n", t4-t3);

    t5 = clock();
    for (int i = 0; i < N; i++) {
        if (V[i] == target) {
            printf("Element %d pronadjen na poziciji %d u nizu.\n", target, i);
            break;
        }
    }
    t6 = clock();
    printf("Vrijeme pretrazivanja niza je %dms\n", t6-t5);

    t7 = clock();
    OE* current = prvi;
    while (current != NULL) {
        if (current->x == target) {
            printf("Element %d pronadjen u povezanom popisu.\n", target);
            break;
        }
        current = current->sljedeci;
    }
    t8 = clock();
    printf("Vrijeme pretrazivanja PP je %dms\n", t8-t7);

    free(V);
    current = prvi;
    while (current != NULL) {
        OE* temp = current;
        current = current->sljedeci;
        free(temp);
    }

    return 0;
}