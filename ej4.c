#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo *TArbol;

int main(){
 
    TArbol A = NULL;
    
    InsertaRandom(&A);

    return 0;
}

void InsertaRandom(TArbol *A){

    unsigned long int i;

    for (i = 0; i < MAX; i++)
        AgregarNodos(&A,rand());
}

void AgregarNodos(TArbol *A, int x) {

    if (*A == NULL) {
        *A = (TArbol)malloc(sizeof(nodo));
        (*A)->dato = x;
        (*A)->der = NULL;
        (*A)->izq = NULL;
    } else if (x>(*A)->dato)
        AgregarNodos(&((*A)->der), x);
    else
        AgregarNodos(&((*A)->izq), x);
}