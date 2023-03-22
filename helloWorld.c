#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_arr(float V[], int n, float dg, float gg);
int sekv_pret(float V[], int n, float x);
void sort(float V[], int n);
int bin_pret(float V[], int n, float x);

int main(){
    
    int n = 0, mjesto = 0;
    float dg = 0, gg = 0, random = 0, diff = 0, r = 0, x = 0;

    time_t t1, t2, t3, t4, t5, t6;

    printf("Unesite n: ");
    scanf("%d", &n);
    printf("\nUnesite dg: ");
    scanf("%f", &dg);
    printf("\nUnesite gg: ");
    scanf("%f", &gg);

    float polje[n];

    gen_arr(polje, n, dg, gg);

    printf("\nUnesite x: ");
    scanf("%f", &x);

    t1 = clock();
    mjesto = sekv_pret(polje, n, x);
    t2 = clock();
    printf("Vrijeme trajanja je %dms\n", t2-t1);

    if(mjesto != -1){
        printf("X found on %d\n", mjesto);
    }else{
        printf("X not found\n");
    }

    t3 = clock();
    sort(polje, n);
    t4 = clock();
    printf("Vrijeme trajanja je %dms\n", t4-t3);
    
    t5 = clock();
    mjesto = bin_pret(polje, n, x);
    t6 = clock();
    printf("Vrijeme trajanja je %dms\n", t6-t5);
    if(mjesto == -1){
        printf("X not found\n");
    }else{
        printf("X found on %d\n", mjesto);
    }

    return 0;
}

void gen_arr(float polje[], int n, float dg, float gg){

    srand(time(NULL));

    for(int i = 0; i < n; i++){
            polje[i] = dg + ((float)rand() / RAND_MAX) * (gg-dg);
    }
}

int sekv_pret(float polje[], int n, float x){
    
    int count = 0;
    
    for(int i = 0; i < n; i++){
            if(polje[i] == x){
                return count;
            }
            count++;
    }
    return -1;
}

void sort(float polje[], int n){

    float temp = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (polje[i] > polje[j]) {
                temp = polje[i];
                polje[i] = polje[j];
                polje[j] = temp;
            }
        }
    }
}

int bin_pret(float polje[], int n, float x){
    float l = polje[0];
    float r = polje[n] - 1;

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (polje[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (polje[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;
}