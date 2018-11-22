/* Lista de Natal */

# include <stdio.h>
# include <string.h>

struct kid {
    char name[20], behavior[2];
};

int partition(struct kid *,int,int);
void quicksort(struct kid *,int,int);


int main() {
    int N, i, j, good, bad;

    good = bad = 0;

    scanf("%d", &N);

    struct kid Kind[N], t;

    
    for (i = 0; i < N; i++) {
        scanf("%s%s", Kind[i].behavior, Kind[i].name);                
    }

    quicksort(Kind,0,N);

        
    for (i = 0; i < N; i++) {
        printf("%s\n", Kind[i].name);
    }
    

    for (i = 0; i < N; i++) {
        if (Kind[i].behavior[0] == '+') {

            good += 1;

        } else {

            bad += 1;

        }
    }

    printf("Se comportaram: %d | Nao se comportaram: %d\n", good, bad);

    // O input foi corrigido. Trabalhar na contagem das crianças comportadas e não comportadas. //
    return 0;
}

void quicksort(struct kid A[],int p,int r){

    int q;

    if (p < r) {
        q = partition(A,p,r);
        quicksort(A,p,q);
        quicksort(A,q+1,r);
    }
    
}

int partition(struct kid A[],int p,int r) {

    // O pivô x é colocado no início do vetor.
    int i, j;
    struct kid aux, x = A[p];
    i = r;
    for (j = r - 1; j > p; j--) {
        if (strcmp(A[j].name, x.name) > 0) {
            i = i - 1;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        } 
    }
    aux = A[i-1];
    A[i-1] = A[p];
    A[p] = aux;

    return (i-1);
}
