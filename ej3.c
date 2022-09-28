
typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
}nodo;

typedef nodo *TArbol;

int main(){

    return 0;
}

//AGREGAR NODOS RECURSIVAMENTE
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

//RECORRIDO INORDEN RECURSIVO
void InOrden(TArbol A) {

    if(A!=NULL) {
        InOrden(A->izq);
        printf("%d \n",A->dato);
        InOrden(A->der);
    }
}

//BUSCAR ELEMENTO RECURSIVAMENTE
void BuscaElem(TArbol A, int dato, int *esta) {

    if(A!=NULL && !(*esta)) {
        if(A->dato > dato)
            BuscaElem(A->izq,dato,esta);
        else if(A->dato < dato)
            BuscaElem(A->der,dato,esta);
        else
            *esta=1;
    }
}

//AGREGAR NODOS ITERATIVAMENTE
void InsertaIT (TArbol *A, int X){

    int inserta=0;
    TArbol nuevo, act;

    act = *A;
    nuevo = (TArbol)malloc(sizeof(struct nodo));
    nuevo->dato = X;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    if (act != NULL)
        while (!inserta){
            if (X < act->dato)
                if (act->izq == NULL){
                    act->izq = nuevo;
                    inserta = !inserta;
                }
                else
                    act = act->izq;
            else 
                if (act->der == NULL){
                    act->der = nuevo;
                    inserta = !inserta;
                }
                else
                    act = act->der;
        }
    else
        *A = nuevo;
}

//RECORRIDO IN ORDEN ITERATIVO
void InOrden_Iterativo(TArbol A){
    
    TPila p;

    IniciaP(p);

    if (A!=NULL){
        do{
            while (A != NULL){
                PoneP(&p,A);
                A = A->izq;
            }
            SacaP(&p,A);

            printf("%d",A->dato);
            A = A->der;
        }
        while (!VaciaP(p) || A!=NULL)
    }
}

//BUSCA ELEMENTO ITERATIVO
int BuscaIterativo(TArbol A, int X){

    if (A != NULL){
        while(A->dato != X){
            if (X < A->dato)
                A = A->izq;
            else
                A = A->der;
        }
        return A->dato;
    }
    else
        return 0;
}